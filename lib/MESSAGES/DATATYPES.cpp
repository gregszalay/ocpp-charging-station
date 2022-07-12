#include "DATATYPES.h"

namespace DATATYPES
{

    /******************************************************************************/

    IdTokenType::IdTokenType(String idToken, ENUMERATIONS::IdTokenEnumType type)
    {
        this->idToken = idToken;
        this->type = type;
    }
    IdTokenType::~IdTokenType()
    {
    }

    /******************************************************************************/

    StatusInfoType::StatusInfoType(String _reasonCode, String _additionalInfo)
        : reasonCode(_reasonCode), additionalInfo(_additionalInfo)
    {
    }
    StatusInfoType::~StatusInfoType()
    {
    }

    /******************************************************************************/

} // DATATYPES