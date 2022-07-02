#pragma once
#include "MESSAGE.h"

class AuthorizeRequest : public CALL
{
    DATATYPES::IdTokenType idToken;
    void buildPayload() override;

public:
    AuthorizeRequest(DATATYPES::IdTokenType _idToken);
    ~AuthorizeRequest();
};
