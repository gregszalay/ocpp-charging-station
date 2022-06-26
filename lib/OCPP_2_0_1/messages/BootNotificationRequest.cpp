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

void BootNotificationRequest::createMessage(String &destinationString) const
{
    StaticJsonDocument<500> doc;

    doc.add(this->messageTypeId);
    doc.add(this->messageId);
    doc.add(this->action);
    JsonObject messageCore = doc.createNestedObject();
    messageCore["reason"] = BOOT_REASON_ENUM_TYPE()[this->reason];
    JsonObject chargingStation = messageCore.createNestedObject("chargingStation");
    chargingStation["serialNumber"] = this->serialNumber;
    chargingStation["model"] = this->model;
    chargingStation["vendorName"] = this->vendorName;

    serializeJson(doc, destinationString);
}

std::function<void(StaticJsonDocument<200>)> BootNotificationRequest::getResponseCallback() const
{
    return [](StaticJsonDocument<200> payloadObj)
    {
        Serial.print("Reason:   ");
        Serial.println((const char *)payloadObj[3]["reason"]);
    };
}