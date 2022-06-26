#include "HeartbeatRequest.h"

HeartbeatRequest::~HeartbeatRequest() {}

void HeartbeatRequest::createMessage(String &destinationString) const
{
    StaticJsonDocument<500> doc;

    doc.add(this->messageTypeId);
    doc.add(this->messageId);
    doc.add(this->action);

    JsonObject messageCore = doc.createNestedObject();
    messageCore["chargerTime"] = millis();

    serializeJson(doc, destinationString);
}


std::function<void(StaticJsonDocument<200>)> HeartbeatRequest::getResponseCallback() const
{
    return ([](StaticJsonDocument<200> payloadObj)
            {
        Serial.print("chargerTime:    ");
        Serial.println((long)payloadObj[3]["chargerTime"]); });
}
