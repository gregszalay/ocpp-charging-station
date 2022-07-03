#include "MESSAGE.h"

/******************************* MESSAGE *******************************/

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

/******************************* CALL *******************************/

CALL::CALL(String _action)
    : MESSAGE(MESSAGE_TYPE_ID_ENUM::CALL_TYPE)
{
    std::vector<uint8_t> uuid_vector = ESPRandom::uuid4();
    messageId = ESPRandom::uuidToString(uuid_vector);
};

String CALL::getAction() const
{
    return this->action;
};

void CALL::buildFrame()
{
    MESSAGE::buildFrame();
    jsonDoc.add(action);
}

/******************************* CALLRESULT *******************************/

CALLRESULT::CALLRESULT(uint8_t _messageTypeId, String _messageId)
    : MESSAGE(MESSAGE_TYPE_ID_ENUM::CALLRESULT_TYPE, _messageId) {}

/******************************* CALLERROR *******************************/

CALLERROR::CALLERROR(
    String _messageId,
    String _errorCode,
    String _errorDescription) : MESSAGE(MESSAGE_TYPE_ID_ENUM::CALLERROR_TYPE, _messageId)
{
    this->messageId = _messageId;
    this->errorCode = _errorCode;
}

void CALLERROR::buildPayload()
{
    jsonDoc.add(this->errorCode);
    jsonDoc.add(this->errorDescription);
    jsonDoc.add("");
}