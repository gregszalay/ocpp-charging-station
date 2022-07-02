#pragma once
#include "Arduino.h"
#include "ENUMERATIONS.h"

/******************************************************************************/

class IdTokenType
{
    String idToken;
    IdTokenEnumType type;

public:
    IdTokenType(String idToken, IdTokenEnumType type);
    ~IdTokenType();
    String getIdToken()
    {
        return this->idToken;
    }
    IdTokenEnumType getType()
    {
        return this->type;
    }
};