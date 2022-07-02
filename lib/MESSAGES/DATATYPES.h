#pragma once
#include "Arduino.h"
#include "ENUMERATIONS.h"

namespace DATATYPES
{

    /******************************************************************************/

    class IdTokenType
    {
        String idToken;
        ENUMERATIONS::IdTokenEnumType type;

    public:
        IdTokenType(String idToken, ENUMERATIONS::IdTokenEnumType type);
        ~IdTokenType();
        String getIdToken()
        {
            return this->idToken;
        }
        ENUMERATIONS::IdTokenEnumType getType()
        {
            return this->type;
        }
    };

    /******************************************************************************/

} // DATATYPES