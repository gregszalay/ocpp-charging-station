

#include <Arduino.h>
#include "FS.h"
#include <LITTLEFS.h>

//#include <config.h>
#include "OCPPWebsocketConnection.h"
#include <ArduinoJson.h>
#include "messages/BootNotificationRequest.h"
#include "messages/HeartbeatRequest.h"
#include "enums/BootReasonEnumType.h"

//#include "core/OCPP.h"

OCPPWebsocketConnection csmsSocket("gergelyszalay.hu", 3000, "/echo", "ocpp2.0.1");

void setup()
{
  USE_SERIAL.begin(115200);
  USE_SERIAL.setDebugOutput(true);

  csmsSocket.open();

  Serial.println("bootNotificationRequest");
  BootNotificationRequest bootNotificationRequest(
      BootReasonEnumType::PowerUp,
      "001",
      "RevolutionCharger",
      "chargerevolution.net");

  csmsSocket.sendRequest(bootNotificationRequest, [](StaticJsonDocument<200> payloadObj)
                         {
      Serial.println("Reason:");
      Serial.println((const char*)payloadObj[3]["reason"]); });
}

long lastMessageSent = 0;

void loop()
{
  csmsSocket.loop();

  if (millis() - lastMessageSent >= 3000)
  {
    HeartbeatRequest heartbeatRequest;
    csmsSocket.sendRequest(heartbeatRequest, [](StaticJsonDocument<200> payloadObj)
                           {
      Serial.println("chargerTime:");
      Serial.println((long)payloadObj[3]["chargerTime"]); });

    lastMessageSent = millis();
  }
}