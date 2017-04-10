//
// Created by bele on 10.04.17.
//

#include "LinuxUdpClient.h"

LinuxUdpClient::LinuxUdpClient() : linuxSystem(),linuxUdpSocket(),mqttsnmsghandler() {
    // base constructor called automatically
}

bool LinuxUdpClient::begin() {
    linuxUdpSocket.setMqttSnMessageHandler(&mqttsnmsghandler);
    mqttsnmsghandler.setCore(this);
    mqttsnmsghandler.setSocket(&linuxUdpSocket);
    Client::set_mqttsn_message_handler(&mqttsnmsghandler);
    Client::set_system(&linuxSystem);
    Client::set_socket(&linuxUdpSocket);

    return Client::begin();
}
