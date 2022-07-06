#include "OCPPEventHandlers.h"

OCPPEventHandlers::OCPPEventHandlers(
    SentMessageRepository *_sentMessagesRepo,
    VirtualRequestHandlerRepository *_reqHandlerRepo)
    : sentMessagesRepo(_sentMessagesRepo),
      reqHandlerRepo(_reqHandlerRepo)
{
}

OCPPEventHandlers::~OCPPEventHandlers()
{
}

void OCPPEventHandlers::handleOutgoingMessage(MESSAGE *message)
{
    if (message->getMessageTypeId() == MESSAGE_TYPE_ID_ENUM::CALL_TYPE)
    {
        CALL *callMessage = (CALL *)message;
        (*this->sentMessagesRepo->getSentMessages())[message->getMessageId()] = (MESSAGE *)callMessage;
    }
}

void OCPPEventHandlers::handleIncomingMessage(uint8_t *payload)
{
    Serial.println("Received message:");
    Serial.println((const char *)(payload));
    
    deserializeJson(this->incomingMessageJSON, payload);
    int messageTypeId = incomingMessageJSON[0];
    switch (messageTypeId)
    {
    case MESSAGE_TYPE_ID_ENUM::CALL_TYPE:
        //Only commented out while testing!
        //this->handleCALL();
        //break;
    case MESSAGE_TYPE_ID_ENUM::CALLRESULT_TYPE:
        this->handleCALLRESULT();
        break;
    case MESSAGE_TYPE_ID_ENUM::CALLERROR_TYPE:
        this->handleCALLERROR();
        break;
    default:
        break;
    }
}

void OCPPEventHandlers::handleError(String errorDescription)
{
    Serial.printf("Error: %s \n", errorDescription.c_str());
}

void OCPPEventHandlers::handleCALL()
{
    String action = incomingMessageJSON[2];
    std::map<String, std::function<MESSAGE *(StaticJsonDocument<200>)>> handlers =
        *this->reqHandlerRepo->getRequestHandlers();
    if (handlers[action] == nullptr)
    {
        Serial.printf("Response not implemented for message %s!", action.c_str());
        return;
    }
    handlers[action](incomingMessageJSON);
}

void OCPPEventHandlers::handleCALLRESULT()
{
    String messageId = incomingMessageJSON[1];
    std::map<String, MESSAGE *> *sentMessagesMapPtr = this->sentMessagesRepo->getSentMessages();

    if ((*sentMessagesMapPtr)[messageId])
    {
        MESSAGE *msgPtr = (*sentMessagesMapPtr)[messageId];
        if (msgPtr->getMessageTypeId() == MESSAGE_TYPE_ID_ENUM::CALL_TYPE)
        {
            CALL *callMsgPtr = (CALL *)msgPtr;
            // invoke callback
            callMsgPtr->getCallback()(incomingMessageJSON);
        }
        else
        {
            Serial.println("Error: Cannot handle CALLRESULT. Original message has wrong type.");
        }
        // remove from sentmessages map
        sentMessagesMapPtr->erase(sentMessagesMapPtr->find(messageId));
        // delete unnecessary object
        delete msgPtr;
    }
}

void OCPPEventHandlers::handleCALLERROR()
{
    Serial.println("We got an error!");
}