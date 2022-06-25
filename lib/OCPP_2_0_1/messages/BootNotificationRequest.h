#pragma once

#include <Arduino.h>
#include <ArduinoJson.h>
#include "Message.h"
#include "enums/BootReasonEnumType.h"

class BootNotificationRequest : public Message
{
public:
    BootReasonEnumType reason = BootReasonEnumType::Unknown;
    const char *serialNumber = nullptr;
    const char *model = nullptr;
    const char *vendorName = nullptr;

    BootNotificationRequest(
        BootReasonEnumType reason,
        const char *serialNumber,
        const char *model,
        const char *vendorName,
        int messageTypeId = 2,
        const char *action = "BootNotification") : Message(messageTypeId, action)
    {
        this->reason = reason;
        this->serialNumber = serialNumber;
        this->model = model;
        this->vendorName = vendorName;
    }

    ~BootNotificationRequest();

    String createMessage() override;
};
