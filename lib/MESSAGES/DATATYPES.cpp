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

} // DATATYPES