#pragma once

#include <Arduino.h>
#include <ArduinoJson.h>
#include "CALL_Message.h"
#include "IdTokenType.h"

class AuthorizeRequest : public CALL_Message
{
    IdTokenType idToken;
    void buildPayload() override;

public:
    AuthorizeRequest(IdTokenType _idToken);

    ~AuthorizeRequest();

    std::function<void(StaticJsonDocument<200>)> getResponseCallback() const override;

};
