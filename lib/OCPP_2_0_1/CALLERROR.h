#pragma once
#include <Arduino.h>
#include "MemoryCheck.h"
#include <ArduinoJson.h>
#include <ESPRandom.h>
#include "MESSAGE.h"

class CALLERROR : public MESSAGE
{
protected:
    String errorCode;
    String errorDescription;
    void buildPayload() override;

public:
    void buildFrame();
    CALLERROR(String _messageId, String _errorCode, String _errorDescription);
    String getErrorCode() const { return this->errorCode; }
    String getErrorDescription() const { return this->errorDescription; }
};
