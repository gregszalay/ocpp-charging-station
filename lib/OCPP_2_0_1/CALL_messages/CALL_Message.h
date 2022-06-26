#pragma once

#include <Arduino.h>
#include <ArduinoJson.h>
#include <ESPRandom.h>

class CALL_Message
{
protected:
    String messageId;
    uint8_t messageTypeId;
    String action;
    String message;
    StaticJsonDocument<500> jsonDoc;

    virtual void buildPayload() = 0;
    void buildMessage();
    void buildFrame();
public:
    CALL_Message(uint8_t messageTypeId, String action);
    virtual ~CALL_Message(){};
    virtual std::function<void(StaticJsonDocument<200>)> getResponseCallback() const = 0;
    uint8_t getMessageTypeId() const;
    String getMessageId() const;
    String getAction() const;
    String getMessage();
};
