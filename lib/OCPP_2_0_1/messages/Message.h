#pragma once

#include <Arduino.h>
#include <ArduinoJson.h>
#include <ESPRandom.h>

#include "enums/BootReasonEnumType.h"

class Message
{
public:
    String messageId = "";
    int messageTypeId;
    String action = "";
    String message = "";

    Message(int messageTypeId, String action);
    ~Message();
    virtual void createMessage(String &destinationString) const = 0;
    virtual std::function<void(StaticJsonDocument<200>)> getResponseCallback() const {};

    int getMessageTypeId() const;
    String getMessageId() const;
    String getAction() const;
    String getMessage() const;
};
