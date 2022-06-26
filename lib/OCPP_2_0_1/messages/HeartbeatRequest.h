#pragma once

#include <Arduino.h>
#include <ArduinoJson.h>
#include "Message.h"

class HeartbeatRequest : public Message
{
    void createMessage(String &destinationString) const override;

public:
    HeartbeatRequest() : Message(2, "Heartbeat")
    {
        createMessage(message);
    };
    ~HeartbeatRequest();
    std::function<void(StaticJsonDocument<200>)> getResponseCallback() const override;
};
