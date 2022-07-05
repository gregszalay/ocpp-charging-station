#include "AuthorizeRequest.h"

AuthorizeRequest::AuthorizeRequest(
    DATATYPES::IdTokenType _idToken,
    std::function<void(StaticJsonDocument<200>)> _onResponse)
    : CALL("Authorize", _onResponse), idToken(_idToken)
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