#pragma once

#include <Arduino.h>
#include <ArduinoJson.h>
#include "CALL.h"

class HeartbeatRequest : public CALL
{

    void buildPayload() override;

public:
    HeartbeatRequest() : CALL("Heartbeat"){};
    ~HeartbeatRequest();
    std::function<void(StaticJsonDocument<200>)> getResponseCallback() const override;
};
