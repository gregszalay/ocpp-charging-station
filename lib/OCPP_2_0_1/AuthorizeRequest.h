#pragma once
#include "MESSAGE.h"

class AuthorizeRequest : public CALL
{
    IdTokenType idToken;
    void buildPayload() override;

public:
    AuthorizeRequest(IdTokenType _idToken);
    ~AuthorizeRequest();
    std::function<void(StaticJsonDocument<200>)> getResponseCallback() const override;
};
