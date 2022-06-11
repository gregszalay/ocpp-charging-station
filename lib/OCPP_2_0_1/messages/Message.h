#pragma once

#include <Arduino.h>

#include "FS.h"
#include <LITTLEFS.h>

#include <WiFi.h>
#include <WiFiClientSecure.h>

#include <WebSocketsClient.h>
#include <config.h>
#include <ArduinoJson.h>
#include <map>

#include "ESPRandom.h"

#include "enums/BootReasonEnumType.h"

class Message
{
public:
    const char *messageId = nullptr;
    int messageTypeId;
    const char *action = nullptr;
    String message = "";

    Message(int messageTypeId, const char *action);
    ~Message();
    virtual String createMessage();

    int getMessageTypeId();
    const char *getMessageId();
    const char *getAction();
};
