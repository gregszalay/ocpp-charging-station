#include <Arduino.h>

#include "FS.h"
#include <LITTLEFS.h>

#include <WiFi.h>
#include <WiFiClientSecure.h>

#include <WebSocketsClient.h>
#include <config.h>
#include <ArduinoJson.h>
#include <map>

#include "enums/BootReasonEnumType.h"

class BootNotificationRequest
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
        const char *vendorName)
    {
        this->reason = reason;
        this->serialNumber = serialNumber;
        this->model = model;
        this->vendorName = vendorName;
    };

    ~BootNotificationRequest(){};

    // BootNotificationRequest(DynamicJsonDocument *payload);

    const char *getMessageTypeName() { return "BootNotificationRequest"; };

    /*
    std::unique_ptr<DynamicJsonDocument> create(){
            auto doc = std::unique_ptr<DynamicJsonDocument>(new DynamicJsonDocument(JSON_OBJECT_SIZE(4)
        + strlen(chargePointModel) + 1
        + strlen(chargePointVendor) + 1
        + strlen(chargePointSerialNumber) + 1
        + strlen(firmwareVersion) + 1));
    JsonObject payload = doc->to<JsonObject>();
    payload["chargePointModel"] = chargePointModel;
    if (chargePointSerialNumber[0]) {
        payload["chargePointSerialNumber"] = chargePointSerialNumber;
    }
    payload["chargePointVendor"] = chargePointVendor;
    if (firmwareVersion[0]) {
        payload["firmwareVersion"] = firmwareVersion;
    }
    return doc;
    };
*/

    String createMessage()
    {
        StaticJsonDocument<500> doc;
        JsonObject bootNotificationRequest = doc.createNestedObject();
        bootNotificationRequest["reason"] = BOOT_REASON_ENUM_TYPE()[this->reason];
        JsonObject chargingStation = bootNotificationRequest.createNestedObject("chargingStation");
        chargingStation["serialNumber"] = this->serialNumber;
        chargingStation["model"] = this->model;
        chargingStation["vendorName"] = this->vendorName;
        String output = "";
        serializeJson(doc, output);
        // doc.printTo(output);
        return output;
    }
};
