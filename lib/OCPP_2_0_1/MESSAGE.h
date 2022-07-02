#pragma once
#include <Arduino.h>
#include "MemoryCheck.h"
#include <ArduinoJson.h>
#include <ESPRandom.h>

class MESSAGE
{
protected:
    uint8_t messageTypeId;
    String messageId;
    String message;
    StaticJsonDocument<500> jsonDoc;
    virtual void buildPayload() = 0;
    void buildMessage();

public:
    void buildFrame();
    MESSAGE(uint8_t _messageTypeId, String _messageId = "");
    virtual ~MESSAGE() { MemoryCheck::freeOne(); }
    virtual std::function<void(StaticJsonDocument<200>)> getResponseCallback() const = 0;
    uint8_t getMessageTypeId() const;
    String getMessageId() const;
    String getMessage();
    operator String() { return getMessage(); };
};
