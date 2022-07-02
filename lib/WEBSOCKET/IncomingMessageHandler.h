
#pragma once
#include <Arduino.h>
#include <ArduinoJson.h>
#include <WebSocketsClient.h>
#include <map>
#include "Network.h"
#include "MESSAGE.h"
#include "CustomImplementation.h"

class IncomingMessageHandler
{
    StaticJsonDocument<200> incomingMessageJSON;
    CustomImplementation customImpl;
    void processCALL();
    void processCALLRESULT();
    void processCALLERROR();

public:
    IncomingMessageHandler(CustomImplementation _customImplementation);
    ~IncomingMessageHandler();
    void processMessage(uint8_t *payload);
};