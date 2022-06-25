#include "HeartbeatRequest.h"

HeartbeatRequest::~HeartbeatRequest() {}

String HeartbeatRequest::createMessage()
{
    const int JSON_CAPACITY = JSON_ARRAY_SIZE(6) + 2 * JSON_OBJECT_SIZE(5);

    StaticJsonDocument<JSON_CAPACITY> doc;

    // Create OCPP message wrapper
    doc.add(this->messageTypeId);
    doc.add(this->messageId);
    doc.add(this->action);

    // Create message
    JsonObject heartbeatRequestObj = doc.createNestedObject();
    heartbeatRequestObj["chargerTime"] = millis();

    serializeJson(doc, message);
    return message;
}