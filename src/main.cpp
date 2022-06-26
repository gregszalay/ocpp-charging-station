#include <Arduino.h>
#include "FS.h"
#include <LITTLEFS.h>
#include "OCPPWebsocketConnection.h"
#include <ArduinoJson.h>
#include "CALL_messages/BootNotificationRequest.h"
#include "CALL_messages/HeartbeatRequest.h"
#include "enums/BootReasonEnumType.h"
//#include "core/OCPP.h"

OCPPWebsocketConnection csmsSocket("gergelyszalay.hu", 3000, "/echo", "ocpp2.0.1");

void setup()
{
  USE_SERIAL.begin(115200);
  USE_SERIAL.setDebugOutput(true);

  csmsSocket.open();

  Serial.println("bootNotificationRequest");
  BootNotificationRequest *bootNotificationRequest = new BootNotificationRequest(
      BootReasonEnumType::PowerUp,
      "001",
      "RevolutionCharger",
      "chargerevolution.net");

  csmsSocket.sendRequest(bootNotificationRequest);
}

long lastMessageSent = 0;

void loop()
{
  csmsSocket.loop();

  if (millis() - lastMessageSent >= 3000)
  {
    HeartbeatRequest *heartbeatRequest = new HeartbeatRequest;
    csmsSocket.sendRequest(heartbeatRequest);

    lastMessageSent = millis();
  }
}