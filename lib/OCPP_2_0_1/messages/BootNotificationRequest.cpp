#include "BootNotificationRequest.h"

/* BootNotificationRequest::BootNotificationRequest(
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
 */
BootNotificationRequest::~BootNotificationRequest() {}

String BootNotificationRequest::createMessage()
{
    const int JSON_CAPACITY = JSON_ARRAY_SIZE(6) + 2 * JSON_OBJECT_SIZE(3);

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

    serializeJson(doc, message);
    return message;
}