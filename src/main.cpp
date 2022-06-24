#include <Arduino.h>

#include "FS.h"
#include <LITTLEFS.h>

#include <WiFi.h>
#include <WiFiClientSecure.h>

#include <WebSocketsClient.h>
#include <config.h>
#include <ArduinoJson.h>
#include "messages/BootNotificationRequest.h"
#include "messages/HeartbeatRequest.h"
#include "enums/BootReasonEnumType.h"

WebSocketsClient webSocket;

#define USE_SERIAL Serial

void hexdump(const void *mem, uint32_t len, uint8_t cols = 16)
{
  const uint8_t *src = (const uint8_t *)mem;
  USE_SERIAL.printf("\n[HEXDUMP] Address: 0x%08X len: 0x%X (%d)", (ptrdiff_t)src, len, len);
  for (uint32_t i = 0; i < len; i++)
  {
    if (i % cols == 0)
    {
      USE_SERIAL.printf("\n[0x%08X] 0x%08X: ", (ptrdiff_t)src, i);
    }
    USE_SERIAL.printf("%02X ", *src);
    src++;
  }
  USE_SERIAL.printf("\n");
}

void webSocketEvent(WStype_t type, uint8_t *payload, size_t length)
{

  switch (type)
  {
  case WStype_DISCONNECTED:
    USE_SERIAL.printf("[WSc] Disconnected!\n");
    break;
  case WStype_CONNECTED:
    USE_SERIAL.printf("[WSc] Connected to url: %s\n", payload);

    // send message to server when Connected
    webSocket.sendTXT("Connected");
    break;
  case WStype_TEXT:
    USE_SERIAL.printf("[WSc] get text: %s\n", payload);

    // send message to server
    // webSocket.sendTXT("message here");
    break;
  case WStype_BIN:
    USE_SERIAL.printf("[WSc] get binary length: %u\n", length);
    hexdump(payload, length);

    // send data to server
    // webSocket.sendBIN(payload, length);
    break;
  case WStype_ERROR:
  case WStype_FRAGMENT_TEXT_START:
  case WStype_FRAGMENT_BIN_START:
  case WStype_FRAGMENT:
  case WStype_FRAGMENT_FIN:
    break;
  }
}

BootNotificationRequest bootNotificationRequest(
    BootReasonEnumType::PowerUp,
    "001",
    "RevolutionCharger",
    "chargerevolution.net");

void setup()
{
  USE_SERIAL.begin(115200);
  USE_SERIAL.setDebugOutput(true);

  USE_SERIAL.println();
  USE_SERIAL.println();
  USE_SERIAL.println();

  Serial.print("Connecting...");

  WiFi.begin(SSID, WIFIPASSWORD);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // server address, port and URL
  webSocket.begin("gergelyszalay.hu", 3000, "/echo", "ocpp2.0.1");

  webSocket.onEvent(webSocketEvent);

  // use HTTP Basic Authorization this is optional remove if not needed
  //  webSocket.setAuthorization("", "");

  webSocket.setReconnectInterval(5000);
  webSocket.enableHeartbeat(15000, 3000, 2);

  // webSocket.sendTXT("Hello from RevolutionCharger!");

  delay(5000);
  // Serial.println("BootnotificationRequest: ");
  // Serial.println(bootNotificationRequest.createMessage());

  // delay(3000);
  webSocket.sendTXT(bootNotificationRequest.createMessage().c_str());

  /*
      [2,"1000000","BootNotification",{
        "chargePointModel" : "My Charging Station",
        "chargePointVendor" : "My company name"
        }
     */
}

long lastMessageSent = 0;

void loop()
{
  webSocket.loop();
  if (millis() - lastMessageSent >= 4000)
  {
    HeartbeatRequest heartbeatRequest;
    // Serial.println("Outgoing HeartbeatRequest:");
    // Serial.println(heartbeatRequest.createMessage());
    webSocket.sendTXT(heartbeatRequest.createMessage().c_str());
    delay(500);
    webSocket.sendTXT(bootNotificationRequest.createMessage().c_str());
    lastMessageSent = millis();
  }
}