#pragma once
#include "MESSAGE.h"

class HeartbeatRequest : public CALL
{

    void buildPayload() override;

public:
    HeartbeatRequest(std::function<void(StaticJsonDocument<200>)> _onResponse) 
    : CALL("Heartbeat", _onResponse){};
    ~HeartbeatRequest();
};
