#include "BootNotificationRequest.h"

BootNotificationRequest::BootNotificationRequest(
    BootReasonEnumType reason,
    const char *serialNumber,
    const char *model,
    const char *vendorName) : CALL("BootNotification")
{
    this->reason = reason;
    this->serialNumber = String(serialNumber);
    this->model = String(model);
    this->vendorName = String(vendorName);
}

BootNotificationRequest::~BootNotificationRequest() {}

void BootNotificationRequest::buildPayload()
{
    JsonObject messageCore = jsonDoc.createNestedObject();
    messageCore["reason"] = "sdfvdfsvbxdf";
    //messageCore["reason"] = BOOT_REASON_ENUM_TYPE()[this->reason];
    JsonObject chargingStation = messageCore.createNestedObject("chargingStation");
    chargingStation["serialNumber"] = this->serialNumber;
    chargingStation["model"] = this->model;
    chargingStation["vendorName"] = this->vendorName;
}

std::function<void(StaticJsonDocument<200>)> BootNotificationRequest::getResponseCallback() const
{
    return [](StaticJsonDocument<200> payloadObj)
    {
        Serial.print("Reason:   ");
        Serial.println((const char *)payloadObj[3]["reason"]);
    };
}