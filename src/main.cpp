
/*
 * WebSocketClient.ino
 *
 *  Created on: 24.05.2015
 *
 */

#include <Arduino.h>

#include "FS.h"
#include <LITTLEFS.h>

#include <WiFi.h>
#include <WiFiClientSecure.h>

#include <WebSocketsClient.h>
#include <config.h>

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

void setup()
{
  USE_SERIAL.begin(921600);
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
  /*
    while (WiFi.begin("Telekom-CM5zbC", "pr4s3asjkgba") != WL_CONNECTED)
    {
      USE_SERIAL.printf("Connecting...");
      USE_SERIAL.flush();
      delay(1000);
    }
   */
  // server address, port and URL
  webSocket.begin("revolutionchargermanager.herokuapp.com", 80, "/", "ocpp2.0.1");

  webSocket.onEvent(webSocketEvent);

  // use HTTP Basic Authorization this is optional remove if not needed
  //[] webSocket.setAuthorization("", "");

  webSocket.setReconnectInterval(5000);
  webSocket.enableHeartbeat(15000, 3000, 2);

  webSocket.sendTXT("Hello from RevolutionCharger!");
}

long lastMessageSent = 0;

void loop()
{
  webSocket.loop();
  if (millis() - lastMessageSent >= 5000)
  {
    webSocket.sendTXT("RevolutionCharger is online!");
    lastMessageSent = millis();
  }
}