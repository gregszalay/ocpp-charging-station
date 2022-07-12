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

    class StatusInfoType
    {
        String reasonCode;
        String additionalInfo;

    public:
        StatusInfoType(String reasonCode, String additionalInfo = "");
        ~StatusInfoType();
        inline String getReasonCode()
        {
            return this->reasonCode;
        }
        inline String getAdditionalInfo()
        {
            return this->additionalInfo;
        }
    };

    /******************************************************************************/

} // DATATYPES