#include "AuthorizeRequest.h"

AuthorizeRequest::AuthorizeRequest(DATATYPES::IdTokenType _idToken) : CALL("Authorize"), idToken(_idToken)
{
    this->idToken = _idToken;
}

AuthorizeRequest::~AuthorizeRequest()
{
}

void AuthorizeRequest::buildPayload()
{
    JsonObject messageCore = jsonDoc.createNestedObject();
    JsonObject idToken = messageCore.createNestedObject("idToken");
    idToken["idToken"] = this->idToken.getIdToken();
    idToken["type"] = "dfbsdgfb";
    idToken["type"] = ENUMERATIONS::ID_TOKEN_ENUM_TYPE()[this->idToken.getType()];
}