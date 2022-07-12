#pragma once
#include "MESSAGE.h"

class AuthorizeRequest : public CALL
{
    DATATYPES::IdTokenType idToken;
    void buildPayload() override;

public:
    AuthorizeRequest(
        DATATYPES::IdTokenType _idToken,
        std::function<void(StaticJsonDocument<200>)> _onResponse);
    ~AuthorizeRequest();
};
