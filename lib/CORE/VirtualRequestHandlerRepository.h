#pragma once
#include "Arduino.h"
#include "MESSAGE.h"

class VirtualRequestHandlerRepository
{

public:
    virtual std::map<String, std::function<MESSAGE *(StaticJsonDocument<200>)>> *getRequestHandlers() = 0;
};