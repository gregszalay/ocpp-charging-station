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

#include "enums/BootReasonEnumType.h"

class Message
{
public:
    const char *messageId = nullptr;
    int messageTypeId;
    const char *action = nullptr;

    Message(int messageTypeId, const char *action)
    {
        this->messageTypeId = messageTypeId;
        this->action = action;
        uint8_t uuid_array[32];
        ESPRandom::uuid4(uuid_array);
        this->messageId = ESPRandom::uuidToString(uuid_array).c_str();
    };

    ~Message();

    const char *createMessage();

    int getMessageTypeId()
    {
        return this->messageTypeId;
    };

    const char *getMessageId()
    {
        return this->messageId;
    };

    const char *getAction()
    {
        return this->action;
    };

};
