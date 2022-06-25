
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
    const char *serverAddr = nullptr;
    uint16_t port = 0;
    const char *URL = nullptr;
    const char *protocol = nullptr;

    std::map<String, std::function<void(StaticJsonDocument<200>)>> responseCallbacks;

    WebSocketsClient webSocket;
    void hexdump(const void *mem, uint32_t len, uint8_t cols = 16);
    /* void webSocketEvent(WStype_t type, uint8_t *payload, size_t length); */

public:
    OCPPWebsocketConnection(const char *serverAddr, uint16_t port, const char *URL, const char *protocol);
    ~OCPPWebsocketConnection();
    void open();
    void loop();
    void sendRequest(Message &message, std::function<void(StaticJsonDocument<200> payloadObj)> callback);
};