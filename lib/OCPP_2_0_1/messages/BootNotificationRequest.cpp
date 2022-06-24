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
    const int JSON_CAPACITY = JSON_ARRAY_SIZE(4) + 2 * JSON_OBJECT_SIZE(3);

    StaticJsonDocument<JSON_CAPACITY> doc;

    doc.add(this->messageTypeId);
    doc.add(this->messageId);
    doc.add(this->action);

    JsonObject bootNotificationRequest = doc.createNestedObject();
    bootNotificationRequest["reason"] = BOOT_REASON_ENUM_TYPE()[this->reason];
    JsonObject chargingStation = bootNotificationRequest.createNestedObject("chargingStation");
    chargingStation["serialNumber"] = this->serialNumber;
    chargingStation["model"] = this->model;
    chargingStation["vendorName"] = this->vendorName;

    // bootNotificationRequestWrapperArray.add(bootNotificationRequest);

    /*     serializeJson(doc, message);
        return message;

        const int capacity = JSON_ARRAY_SIZE(4) + 2 * JSON_OBJECT_SIZE(1);

        StaticJsonDocument<500> doc;

        // Create OCPP message wrapper
        doc.add(this->messageTypeId);
        doc.add(this->messageId);
        doc.add(this->action);

        // Create message
        JsonObject heartbeatRequestObj = doc.createNestedObject("chargerTime" );
        heartbeatRequestObj["chargerTime"] = millis(); */

    serializeJson(doc, message);
    return message;
}