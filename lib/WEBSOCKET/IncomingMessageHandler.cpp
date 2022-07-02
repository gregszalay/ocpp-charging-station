#include "IncomingMessageHandler.h"

IncomingMessageHandler::IncomingMessageHandler(CustomImplementation _customImplementation)
    : customImpl(_customImplementation)
{
}
IncomingMessageHandler::~IncomingMessageHandler()
{
}
void IncomingMessageHandler::processMessage(uint8_t *payload)
{
    Serial.println("Received message:");
    Serial.println((const char *)(payload));
    deserializeJson(this->incomingMessageJSON, payload);
    switch (String((const char *)incomingMessageJSON[0]).toInt())
    {
    case MESSAGE_TYPE_ID_ENUM::CALL_TYPE:
        processCALL();
        break;
    case MESSAGE_TYPE_ID_ENUM::CALLRESULT_TYPE:
        processCALLRESULT();
        break;
    case MESSAGE_TYPE_ID_ENUM::CALLERROR_TYPE:
        processCALLERROR();
        break;
    default:
        break;
    }
}

void IncomingMessageHandler::processCALL()
{
    String action = incomingMessageJSON[2];
    if (this->customImpl.getRequestHandlers()[action] == nullptr)
    {
        Serial.printf("Response not implemented for message %s!", action);
        return;
    }
    std::function<MESSAGE *(StaticJsonDocument<200>)> handler = *(this->customImpl.getRequestHandlers())[action];
    handler(incomingMessageJSON);
}

void IncomingMessageHandler::processCALLRESULT()
{
    String messageId = incomingMessageJSON[1];
    if (!this->customImpl.sentMessages[messageId])
    {
        Serial.printf("Response callback not found for message %s!", messageId);
    }
    else
    {
        std::function<void(StaticJsonDocument<200>)> handler = this->customImpl.sentMessages[messageId];
        handler(incomingMessageJSON);
    }
}

void IncomingMessageHandler::processCALLERROR()
{
    Serial.println("We got an error!");
}