#pragma once
#include "MESSAGE.h"

class HeartbeatRequest : public CALL
{

    void buildPayload() override;

public:
    HeartbeatRequest() : CALL("Heartbeat"){};
    ~HeartbeatRequest();
    std::function<void(StaticJsonDocument<200>)> getResponseCallback() const override;
};
