//
// Created by bele on 10.04.17.
//

#ifndef CORE_MQTT_SN_CLIENT_LINUXUDPCLIENT_H
#define CORE_MQTT_SN_CLIENT_LINUXUDPCLIENT_H


#include <Client.h>
#include <LinuxSystem.h>
#include <LinuxUdpSocket.h>


class LinuxUdpClient : public Client {
    LinuxSystem linuxSystem;
    LinuxUdpSocket linuxUdpSocket;
    MqttSnMessageHandler mqttsnmsghandler;
public:
    LinuxUdpClient();

    bool begin() override;

};


#endif //CORE_MQTT_SN_CLIENT_LINUXUDPCLIENT_H
