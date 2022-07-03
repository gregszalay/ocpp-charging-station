
#pragma once
#include <Arduino.h>
#include <ArduinoJson.h>
#include <functional>
#include "MESSAGE.h"
#include "VirtualRequestHandlerRepository.h"
#include "SentMessageRepository.h"

class OCPPEventHandlers
{
    StaticJsonDocument<200> incomingMessageJSON;
    SentMessageRepository *sentMessagesRepo = nullptr;
    VirtualRequestHandlerRepository *reqHandlerRepo = nullptr;
    void handleCALL();
    void handleCALLRESULT();
    void handleCALLERROR();

public:
    OCPPEventHandlers(SentMessageRepository *_sentMessagesRepo, VirtualRequestHandlerRepository *_reqHandlerRepo);
    ~OCPPEventHandlers();
    void handleIncomingMessage(uint8_t *payload);
    void handleOutgoingMessage(MESSAGE *message, std::function<void(StaticJsonDocument<200>)> onResponse);
    void handleError(String errorDescription);
};