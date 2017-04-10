#include <Client.h>
#include <LinuxUdpSocket.h>
#include <LinuxUdpClient.h>

LinuxUdpClient client;
device_address gateway_address;
const char *client_id = "Linux MQTT-SN Client";
uint16_t duration = 60;
const char *ping_request_topic = "ping/request";
uint8_t ping_qos = 0;
const char *ping_response_topic = "ping/response";

const char *expected_msg = "Hello";
const char *reply_msg = "Hello World";
bool expected_msg_received = false;

void init_gw_address() {
    gateway_address.bytes[0] = 127;
    gateway_address.bytes[1] = 0;
    gateway_address.bytes[2] = 0;
    gateway_address.bytes[3] = 1;
    uint16_t port = ntohs(8888);
    memcpy(&gateway_address.bytes[4], &port, sizeof(uint16_t));
}

void mqttsn_callback(char *topic, uint8_t *payload, uint16_t length, bool retain) {
    if (memcmp(topic, ping_request_topic, sizeof(ping_request_topic)) == 0) {
        if (length == strlen(expected_msg) &&
            memcmp(payload, expected_msg, strlen(expected_msg)) == 0) {
            std::cout << "Hello received" << std::endl;
            expected_msg_received = true;
        }
    }
}

void setup() {
    init_gw_address();

    client.setCallback(mqttsn_callback);
    if (client.begin()) {
        std::cout << "ready" << std::endl;
    }
}


void loop() {
    if (!client.loop()) {
        expected_msg_received = false;
        client.connect(&gateway_address, client_id, duration);
        client.subscribe(ping_request_topic, ping_qos);
    }
    if (expected_msg_received) {
        client.publish(reply_msg, ping_response_topic, ping_qos);
        expected_msg_received = false;
    }
}

int main(int argc, char *argv[]) {
    setup();
    while (true) {
        loop();
    }
}