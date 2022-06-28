#include <Arduino.h>
#include "FS.h"
#include <LITTLEFS.h>
#include "WebsocketToCSMS.h"
#include <ArduinoJson.h>
#include "CALL_messages/BootNotificationRequest.h"
#include "CALL_messages/HeartbeatRequest.h"
#include "enums/BootReasonEnumType.h"
//#include "core/OCPP.h"

WebsocketToCSMS CSMS_GOCPP_VPS("gergelyszalay.hu", 3000, "/echo", "ocpp2.0.1");

void setup()
{
  USE_SERIAL.begin(115200);
  USE_SERIAL.setDebugOutput(true);

  CSMS_GOCPP_VPS.open();

  Serial.println("bootNotificationRequest");
  BootNotificationRequest *bootNotificationRequest = new BootNotificationRequest(
      BootReasonEnumType::PowerUp,
      "001",
      "RevolutionCharger",
      "chargerevolution.net");

  CSMS_GOCPP_VPS.sendRequest(bootNotificationRequest);
}

long lastMessageSent = 0;

void loop()
{
  CSMS_GOCPP_VPS.loop();

  if (millis() - lastMessageSent >= 3000)
  {
    HeartbeatRequest *heartbeatRequest = new HeartbeatRequest;
    CSMS_GOCPP_VPS.sendRequest(heartbeatRequest);

    lastMessageSent = millis();
  }
}