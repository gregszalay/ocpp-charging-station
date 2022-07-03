#pragma once
#include <Arduino.h>
#include <ArduinoJson.h>
#include <map>
#include <functional>
#include "MESSAGE.h"
#include "SentMessageRepository.h"
#include "OCPPWebsocketVirtual.h"
#include "VirtualRequestHandlerRepository.h"

class VirtualOCPP
{
public:
    long lastMessageSentMillis;
    OCPPWebsocketVirtual *wsImpl = nullptr;
    SentMessageRepository *sentMessagesRepo = nullptr;
    VirtualRequestHandlerRepository *reqHandlerRepo = nullptr;

    VirtualOCPP(OCPPWebsocketVirtual *_wsImpl, SentMessageRepository *_sentMessagesRepo, VirtualRequestHandlerRepository *_reqHandlerRepo);
    virtual ~VirtualOCPP(){};
    virtual void setup();
    virtual void loop();
};