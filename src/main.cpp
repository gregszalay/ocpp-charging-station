#include <Arduino.h>
#include "MemoryCheck.h"
#include "FS.h"
#include <LITTLEFS.h>
#include "WebsocketToCSMS.h"
#include <ArduinoJson.h>
#include "BootNotificationRequest.h"
#include "HeartbeatRequest.h"
#include "AuthorizeRequest.h"
//#include "core/OCPP.h"

// This needs to be the first object created!
static MemoryCheck MEMORY_CHECK;

WebsocketToCSMS CSMS_GOCPP_VPS("gergelyszalay.hu", 3000, "/echo", "ocpp2.0.1");

void setup()
{
  USE_SERIAL.begin(115200);
  USE_SERIAL.setDebugOutput(true);

  CSMS_GOCPP_VPS.open();

  // Bootnotification
  Serial.println("bootNotification...");
  BootNotificationRequest *bootNotificationRequest = new BootNotificationRequest(
      BootReasonEnumType::PowerUp,
      "001",
      "RevolutionCharger",
      "chargerevolution.net");
  MemoryCheck::newnew();
  CSMS_GOCPP_VPS.sendRequest(bootNotificationRequest);

  // AuthorizeReq
  Serial.println("authorize...");
  IdTokenType idTokenZ("abcd", IdTokenEnumType::ISO14443);
  AuthorizeRequest *authorizeRequest = new AuthorizeRequest(idTokenZ);
  MemoryCheck::newnew();
  CSMS_GOCPP_VPS.sendRequest(authorizeRequest);
}

long lastMessageSent = 0;

void loop()
{
  CSMS_GOCPP_VPS.loop();

  if (millis() - lastMessageSent >= 3000)
  {
    HeartbeatRequest *heartbeatRequest = new HeartbeatRequest;
    MemoryCheck::newnew();
    CSMS_GOCPP_VPS.sendRequest(heartbeatRequest);

    lastMessageSent = millis();
  }
}