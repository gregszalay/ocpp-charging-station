#pragma once

#include <Arduino.h>
#include <ArduinoJson.h>
#include "Message.h"

class HeartbeatRequest : public Message
{

public:
    HeartbeatRequest() : Message(2, "Heartbeat"){};
    ~HeartbeatRequest();
    String createMessage() override;
};
