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

String MESSAGE::toJSONString(bool prettyJson)
{
    buildMessage();
    prettyJson ? serializeJsonPretty(jsonDoc, message) : serializeJson(jsonDoc, message);
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

CALL::CALL(String _action, std::function<void(StaticJsonDocument<200>)> _onResponse)
    : MESSAGE(MESSAGE_TYPE_ID_ENUM::CALL_TYPE), action(_action), onResponse(_onResponse)
{
    std::vector<uint8_t> uuid_vector = ESPRandom::uuid4();
    messageId = ESPRandom::uuidToString(uuid_vector);
};

String CALL::getAction() const
{
    return this->action;
};

std::function<void(StaticJsonDocument<200>)> CALL::getCallback() const
{
    return this->onResponse;
};

void CALL::buildFrame()
{
    MESSAGE::buildFrame();
    jsonDoc.add(this->action);
}

/******************************* CALLRESULT *******************************/

CALLRESULT::CALLRESULT(String _messageId)
    : MESSAGE(MESSAGE_TYPE_ID_ENUM::CALLRESULT_TYPE, _messageId) {}

/******************************* CALLERROR *******************************/

CALLERROR::CALLERROR(
    String _messageId,
    String _errorCode,
    String _errorDescription) : MESSAGE(MESSAGE_TYPE_ID_ENUM::CALLERROR_TYPE, _messageId),
                                errorCode(_errorCode),
                                errorDescription(_errorDescription)
{
}

void CALLERROR::buildPayload()
{
    jsonDoc.add(this->errorCode);
    jsonDoc.add(this->errorDescription);
    jsonDoc.add("");
}