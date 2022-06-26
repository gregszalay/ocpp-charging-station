#include "CALL_Message.h"

CALL_Message::CALL_Message(uint8_t messageTypeId, String action)
    : messageTypeId(messageTypeId), action(action)
{
    std::vector<uint8_t> uuid_vector = ESPRandom::uuid4();
    messageId = ESPRandom::uuidToString(uuid_vector);
};

uint8_t CALL_Message::getMessageTypeId() const
{
    return this->messageTypeId;
};

String CALL_Message::getMessageId() const
{
    return this->messageId;
};

String CALL_Message::getAction() const
{
    return this->action;
};

String CALL_Message::getMessage()
{
    buildMessage();
    serializeJson(jsonDoc, message);
    return message;
};

void CALL_Message::buildMessage()
{
    buildFrame();
    buildPayload();
}

void CALL_Message::buildFrame()
{
    jsonDoc.add(messageTypeId);
    jsonDoc.add(messageId);
    jsonDoc.add(action);
}
