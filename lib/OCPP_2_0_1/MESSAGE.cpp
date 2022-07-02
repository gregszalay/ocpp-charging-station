#include "MESSAGE.h"

MESSAGE::MESSAGE(uint8_t _messageTypeId, String _messageId)
    : messageTypeId(_messageTypeId), messageId(_messageId){};

uint8_t MESSAGE::getMessageTypeId() const
{
    return this->messageTypeId;
};

String MESSAGE::getMessageId() const
{
    return this->messageId;
};

String MESSAGE::getMessage()
{
    buildMessage();
    serializeJson(jsonDoc, message);
    return message;
};

void MESSAGE::buildMessage()
{
    buildFrame();
    buildPayload();
}

void MESSAGE::buildFrame()
{
    jsonDoc.add(messageTypeId);
    jsonDoc.add(messageId);
}
