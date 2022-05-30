#include "BootNotificationRequest.h"

BootNotificationRequest::~BootNotificationRequest() {}

const char *BootNotificationRequest::createMessage()
{
    StaticJsonDocument<500> doc;
    JsonArray bootNotificationRequestWrapperArray = doc.createNestedArray();
    bootNotificationRequestWrapperArray.add(this->messageTypeId);
    bootNotificationRequestWrapperArray.add(this->messageId);
    bootNotificationRequestWrapperArray.add(this->action);
    
    JsonObject bootNotificationRequest = doc.createNestedObject();
    bootNotificationRequest["reason"] = BOOT_REASON_ENUM_TYPE()[this->reason];
    JsonObject chargingStation = bootNotificationRequest.createNestedObject("chargingStation");
    chargingStation["serialNumber"] = this->serialNumber;
    chargingStation["model"] = this->model;
    chargingStation["vendorName"] = this->vendorName;

    bootNotificationRequestWrapperArray.add(bootNotificationRequest);
    
    String output = "";
    serializeJson(doc, output);
    return output.c_str();
}