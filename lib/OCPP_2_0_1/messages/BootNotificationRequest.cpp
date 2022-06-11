#include "BootNotificationRequest.h"

BootNotificationRequest::BootNotificationRequest(
    BootReasonEnumType reason,
    const char *serialNumber,
    const char *model,
    const char *vendorName,
    int messageTypeId,
    const char *action) : Message(messageTypeId, action)
{
    this->reason = reason;
    this->serialNumber = serialNumber;
    this->model = model;
    this->vendorName = vendorName;
}

BootNotificationRequest::~BootNotificationRequest() {}

String BootNotificationRequest::createMessage()
{
    StaticJsonDocument<500> doc;
    JsonArray bootNotificationRequestWrapperArray = doc.createNestedArray();
    bootNotificationRequestWrapperArray.add(this->messageTypeId);
    bootNotificationRequestWrapperArray.add(messageId);
    bootNotificationRequestWrapperArray.add(this->action);

    JsonObject bootNotificationRequest = doc.createNestedObject();
    bootNotificationRequest["reason"] = BOOT_REASON_ENUM_TYPE()[this->reason];
    JsonObject chargingStation = bootNotificationRequest.createNestedObject("chargingStation");
    chargingStation["serialNumber"] = this->serialNumber;
    chargingStation["model"] = this->model;
    chargingStation["vendorName"] = this->vendorName;

    bootNotificationRequestWrapperArray.add(bootNotificationRequest);

    serializeJson(doc, message);
    return message;
}