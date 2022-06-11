#include <Arduino.h>

#include "FS.h"
#include <LITTLEFS.h>

#include <WiFi.h>
#include <WiFiClientSecure.h>

#include <WebSocketsClient.h>
#include <config.h>
#include <ArduinoJson.h>
#include <map>

#include "ESPRandom.h"
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
        const char *action = "BootNotification");

    ~BootNotificationRequest();

    String createMessage();
};
