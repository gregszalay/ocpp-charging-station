
#pragma once

#include <Arduino.h>
#include "CALL_messages/CALL_Message.h"
#include <WebSocketsClient.h>
#include "Network.h"
#include <ArduinoJson.h>
#include <map>

#define USE_SERIAL Serial

class WebsocketToCSMS
{
    std::map<String, CALL_Message *> sentMessages;

    WebSocketsClient webSocket;
    String serverAddr = "";
    uint16_t port = 0;
    String URL = "";
    String protocol = "";

    void hexdump(const void *mem, uint32_t len, uint8_t cols = 16);
    void processResponse(uint8_t *payload);

    /* void webSocketEvent(WStype_t type, uint8_t *payload, size_t length); */

public:
    WebsocketToCSMS(String serverAddr, uint16_t port, String URL, String protocol);
    ~WebsocketToCSMS();
    void open();
    void loop();
    void sendRequest(CALL_Message *message);
};