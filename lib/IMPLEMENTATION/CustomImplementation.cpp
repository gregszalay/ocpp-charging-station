#include "CustomImplementation.h"

CustomImplementation::CustomImplementation(
    String _serverAddr,
    uint16_t _port,
    String _URL,
    String _protocol) : ws(_serverAddr, port, URL, protocol)
{
    this->msgHandler = msgHandler;
};

void CustomImplementation::setup()
{
}

void CustomImplementation::loop()
{
}

void CustomImplementation::sendMessage(MESSAGE *message, std::function<void(StaticJsonDocument<200>)> onResponse)
{
    sentMessages[message->getMessageId()] = onResponse;
    String payloadTemp = (*message);
    this->ws.send(payloadTemp);
}

std::map<String, std::function<MESSAGE *(StaticJsonDocument<200>)>> *CustomImplementation::getRequestHandlers()
{
    return new std::map<String, std::function<MESSAGE *(StaticJsonDocument<200>)>>{
        /******************************************************************/
        {"Authorize",
         [](StaticJsonDocument<200> payloadObj)
         {
             Serial.print("NOT IMPLEMENTED");
             return new MESSAGE(3);
         }},
        /******************************************************************/
        {"BootNotification",
         [](StaticJsonDocument<200> payloadObj)
         {
             Serial.print("NOT IMPLEMENTED");
             return new MESSAGE(3);
         }},
        /******************************************************************/
    };
};
