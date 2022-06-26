#pragma once

#include <Arduino.h>
#include <ArduinoJson.h>
#include "CALL_Message.h"

class HeartbeatRequest : public CALL_Message
{

    void buildPayload() override;

public:
    HeartbeatRequest() : CALL_Message(2, "Heartbeat"){};
    ~HeartbeatRequest();
    std::function<void(StaticJsonDocument<200>)> getResponseCallback() const override;
};
