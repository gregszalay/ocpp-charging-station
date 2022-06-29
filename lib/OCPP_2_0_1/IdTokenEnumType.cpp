#include "IdTokenEnumType.h"
#include <map>

std::map<IdTokenEnumType, String> myMap;

std::map<IdTokenEnumType, String>& ID_TOKEN_ENUM_TYPE()
{
    myMap[IdTokenEnumType::Central] = "Central";
    myMap[IdTokenEnumType::eMAID] = "eMAID";
    myMap[IdTokenEnumType::ISO14443] = "ISO14443";
    myMap[IdTokenEnumType::ISO15693] = "ISO15693";
    myMap[IdTokenEnumType::KeyCode] = "KeyCode";
    myMap[IdTokenEnumType::Local] = "Local";
    myMap[IdTokenEnumType::MacAddress] = "MacAddress";
    myMap[IdTokenEnumType::NoAuthorization] = "NoAuthorization";
    return myMap;
}
