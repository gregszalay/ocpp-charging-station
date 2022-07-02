#include "DATATYPES.h"

/******************************************************************************/

IdTokenType::IdTokenType(String idToken, IdTokenEnumType type)
{
    this->idToken = idToken;
    this->type = type;
}
IdTokenType::~IdTokenType()
{
}

/******************************************************************************/