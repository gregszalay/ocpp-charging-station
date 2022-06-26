#pragma once

#include <Arduino.h>
#include <ArduinoJson.h>
#include "Message.h"
#include "enums/BootReasonEnumType.h"

class BootNotificationRequest : public Message
{
public:
    BootReasonEnumType reason = BootReasonEnumType::Unknown;
    String serialNumber = "";
    String model = "";
    String vendorName = "";


    BootNotificationRequest(
        BootReasonEnumType reason,
        String serialNumber,
        String model,
        String vendorName,
        int messageTypeId = 2,
        String action = "BootNotification") : Message(messageTypeId, action)
    {
        this->reason = reason;
        this->serialNumber = serialNumber;
        this->model = model;
        this->vendorName = vendorName;
        createMessage(message);
    }

    ~BootNotificationRequest();

    void createMessage(String &destinationString) const override;
    std::function<void(StaticJsonDocument<200>)> getResponseCallback() const override;
};
