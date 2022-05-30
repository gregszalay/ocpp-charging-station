#include "HeartbeatRequest.h"



HeartbeatRequest::~HeartbeatRequest() {}

const char *HeartbeatRequest::createMessage()
{
    StaticJsonDocument<500> doc;
    JsonObject HeartbeatRequest = doc.createNestedObject();
    HeartbeatRequest["chargerTime"] = millis();
    String output = "";
    serializeJson(doc, output);
    const char *resultMessage = output.c_str();
    return resultMessage;
}