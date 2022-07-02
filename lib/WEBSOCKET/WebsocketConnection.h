
#pragma once
#include <Arduino.h>
#include <ArduinoJson.h>
#include <WebSocketsClient.h>
#include <map>
#include "Network.h"
#include "MESSAGE.h"

#define USE_SERIAL Serial

class WebsocketConnection
{
    WebSocketsClient webSocket;
    String serverAddr;
    uint16_t port;
    String URL;
    String protocol;
    std::function<void(uint8_t *)> onMessage;
    void hexdump(const void *mem, uint32_t len, uint8_t cols = 16);

public:
    WebsocketConnection(String _serverAddr,
                        uint16_t _port,
                        String _URL,
                        String _protocol,
                        std::function<void(uint8_t *)> _onMessage);
    ~WebsocketConnection();
    void open();
    void loop();
    void send(String message) { this->webSocket.sendTXT(message); }
};