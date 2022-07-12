#include "G_Availability.h"

HeartbeatRequest::~HeartbeatRequest() {}

void HeartbeatRequest::buildPayload()
{
    JsonObject messageCore = jsonDoc.createNestedObject();
    messageCore["chargerTime"] = millis();
}