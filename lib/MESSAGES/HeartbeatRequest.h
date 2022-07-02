#pragma once
#include "MESSAGE.h"

class HeartbeatRequest : public CALL
{

    void buildPayload() override;

public:
    HeartbeatRequest() : CALL("Heartbeat"){};
    ~HeartbeatRequest();
};
