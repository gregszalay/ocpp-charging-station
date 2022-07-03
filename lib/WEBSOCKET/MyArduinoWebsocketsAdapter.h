
#pragma once
#include <Arduino.h>
#include <ArduinoJson.h>
#include <WebSocketsClient.h>
#include <map>
#include "OCPPNetwork.h"
#include "MESSAGE.h"
#include "OCPPWebsocketVirtual.h"

#define USE_SERIAL Serial

class MyArduinoWebsocketsAdapter : public OCPPWebsocketVirtual
{
    WebSocketsClient webSocket;
    void hexdump(const void *mem, uint32_t len, uint8_t cols = 16);

public:
    MyArduinoWebsocketsAdapter(WebsocketServerAddress &wsAddress, OCPPEventHandlers *eventHandlersPtr);
    ~MyArduinoWebsocketsAdapter();
    void open() override;
    void loop() override;
    void close() override;
    void sendMessage(MESSAGE *message, std::function<void(StaticJsonDocument<200>)> onResponse) override;
};