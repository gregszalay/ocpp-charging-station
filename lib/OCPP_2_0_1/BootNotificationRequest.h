#pragma once
#include "MESSAGE.h"

class BootNotificationRequest : public CALL
{
    BootReasonEnumType reason = BootReasonEnumType::Unknown;
    String serialNumber;
    String model;
    String vendorName;

    void buildPayload() override;

public:
    BootNotificationRequest(
        BootReasonEnumType reason,
        const char *serialNumber,
        const char *model,
        const char *vendorName);

    ~BootNotificationRequest();

    std::function<void(StaticJsonDocument<200>)> getResponseCallback() const override;
};
