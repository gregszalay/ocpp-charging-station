#include <Arduino.h>

#include "FS.h"
#include <LITTLEFS.h>

#include <WiFi.h>
#include <WiFiClientSecure.h>

#include <WebSocketsClient.h>
#include <config.h>
#include <ArduinoJson.h>

#include "ESPRandom.h"
#include "Message.h"

class HeartbeatRequest : public Message
{

public:
    HeartbeatRequest() : Message(2, "Heartbeat"){};
    ~HeartbeatRequest();
    const char *createMessage();
};
