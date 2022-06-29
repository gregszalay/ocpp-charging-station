#include "HeartbeatRequest.h"

HeartbeatRequest::~HeartbeatRequest() {}

void HeartbeatRequest::buildPayload()
{
    JsonObject messageCore = jsonDoc.createNestedObject();
    messageCore["chargerTime"] = millis();
}

std::function<void(StaticJsonDocument<200>)> HeartbeatRequest::getResponseCallback() const
{
    return [](StaticJsonDocument<200> payloadObj)
    {
        Serial.print("chargerTime:    ");
        Serial.println((long)payloadObj[3]["chargerTime"]); };
}
