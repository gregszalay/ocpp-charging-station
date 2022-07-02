#include <Arduino.h>
#include <ArduinoJson.h>
#include <map>
#include <functional>
#include "MESSAGE.h"
#include "WebsocketConnection.h"
#include "IncomingMessageHandler.h"


class CustomImplementation
{
public:
    WebsocketConnection ws;
    std::map<String, std::function<void(StaticJsonDocument<200>)>> sentMessages;
    long lastMessageSentMillis = 0;

    IncomingMessageHandler msgHandler;

    CustomImplementation(WebsocketConnection _ws, IncomingMessageHandler _msgHandler);
    virtual ~CustomImplementation(){};

    virtual void setup();
    virtual void loop();
    virtual void sendMessage(MESSAGE *message, std::function<void(StaticJsonDocument<200>)> onResponse);
    virtual std::map<String, std::function<MESSAGE *(StaticJsonDocument<200>)>> *getRequestHandlers();
};