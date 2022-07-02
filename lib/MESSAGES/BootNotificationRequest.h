#pragma once
#include "MESSAGE.h"

class BootNotificationRequest : public CALL
{
    ENUMERATIONS::BootReasonEnumType reason = ENUMERATIONS::BootReasonEnumType::Unknown;
    String serialNumber;
    String model;
    String vendorName;
    void buildPayload() override;

public:
    BootNotificationRequest(
        ENUMERATIONS::BootReasonEnumType reason,
        const char *serialNumber,
        const char *model,
        const char *vendorName);
    ~BootNotificationRequest();
};
