#pragma once
#include <Arduino.h>
#include "MemoryCheck.h"
#include <ArduinoJson.h>
#include "MESSAGE.h"

class CALLRESULT : public MESSAGE
{
public:
    CALLRESULT(uint8_t _messageTypeId, String _messageId);
};
