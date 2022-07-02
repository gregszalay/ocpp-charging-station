#include "AuthorizeRequest.h"

AuthorizeRequest::AuthorizeRequest(IdTokenType _idToken) : CALL("Authorize"), idToken(_idToken)
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
    idToken["type"] = ID_TOKEN_ENUM_TYPE()[this->idToken.getType()];
}

std::function<void(StaticJsonDocument<200>)> AuthorizeRequest::getResponseCallback() const
{
    return [](StaticJsonDocument<200> payloadObj)
    {
        Serial.print("Id token:   ");
        Serial.println((const char *)payloadObj[3]["idToken"]["idToken"]);
        Serial.println((const char *)payloadObj[3]["idToken"]["type"]);
    };
}

/* AuthorizeRequest::operator String() const
{
    this->buildMessage();
    serializeJson(jsonDoc, message);
    return message;
}
 */