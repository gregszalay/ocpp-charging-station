#include "B_Provisioning.h"

BootNotificationRequest::BootNotificationRequest(
    ENUMERATIONS::BootReasonEnumType reason,
    const char *serialNumber,
    const char *model,
    const char *vendorName,
    std::function<void(StaticJsonDocument<200>)> _onResponse) : CALL("BootNotification", _onResponse)
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
    messageCore["reason"] = ENUMERATIONS::BOOT_REASON_ENUM_TYPE()[this->reason];
    // messageCore["reason"] = BOOT_REASON_ENUM_TYPE()[this->reason];
    JsonObject chargingStation = messageCore.createNestedObject("chargingStation");
    chargingStation["serialNumber"] = this->serialNumber;
    chargingStation["model"] = this->model;
    chargingStation["vendorName"] = this->vendorName;
}