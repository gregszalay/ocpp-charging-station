#include "Message.h"

Message::Message(int messageTypeId, const char *action)
    : messageTypeId(messageTypeId), action(action)
{
    uint8_t uuid_array[16];
    ESPRandom::uuid4(uuid_array);
    messageId = ESPRandom::uuidToString(uuid_array).c_str();
    Serial.println("UUID generated:");
    Serial.println(messageId);
};

Message::~Message(){};

String Message::createMessage(){};

int Message::getMessageTypeId()
{
    return this->messageTypeId;
};

const char *Message::getMessageId()
{
    return this->messageId;
};

const char *Message::getAction()
{
    return this->action;
};
