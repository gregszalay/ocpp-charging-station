#include "HeartbeatRequest.h"

HeartbeatRequest::~HeartbeatRequest() {}

String HeartbeatRequest::createMessage()
{
    StaticJsonDocument<500> doc;

    //Create OCPP message wrapper
    JsonArray messageWrapper = doc.createNestedArray();
    messageWrapper.add(this->messageTypeId);
    messageWrapper.add(messageId);
    messageWrapper.add(this->action);

    //Create message 
    JsonObject HeartbeatRequest = doc.createNestedObject("chargerTime");
    HeartbeatRequest["chargerTime"] = millis();

    messageWrapper.add(HeartbeatRequest);
    serializeJson(doc, message);
    return message;
}