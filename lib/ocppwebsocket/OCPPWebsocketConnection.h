
#pragma once

#include <Arduino.h>
/* #include "FS.h"
#include <LITTLEFS.h> */

#include "messages/Message.h"
#include <WebSocketsClient.h>
#include "Network.h"
//#include <config.h>
#include <ArduinoJson.h>
#include <map>

#define USE_SERIAL Serial

class OCPPWebsocketConnection
{
    std::map<String, std::function<void(StaticJsonDocument<200>)>> responseCallbacks;

    WebSocketsClient webSocket;
    String serverAddr = "";
    uint16_t port = 0;
    String URL = "";
    String protocol = "";

    void hexdump(const void *mem, uint32_t len, uint8_t cols = 16);
    /* void webSocketEvent(WStype_t type, uint8_t *payload, size_t length); */

public:
    OCPPWebsocketConnection(String serverAddr, uint16_t port, String URL, String protocol);
    ~OCPPWebsocketConnection();
    void open();
    void loop();
    void sendRequest(const Message &message);
};