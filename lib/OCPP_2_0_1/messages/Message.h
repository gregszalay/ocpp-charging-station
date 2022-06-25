#pragma once

#include <Arduino.h>
#include <ESPRandom.h>

#include "enums/BootReasonEnumType.h"

class Message
{
public:
    String messageId = "";
    int messageTypeId;
    const char *action = nullptr;
    String message = "";

    Message(int messageTypeId, const char *action);
    ~Message();
    virtual String createMessage(){};

    int getMessageTypeId();
    String getMessageId();
    const char *getAction();
};
