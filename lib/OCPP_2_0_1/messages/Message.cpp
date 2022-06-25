#include "Message.h"

Message::Message(int messageTypeId, const char *action)
    : messageTypeId(messageTypeId), action(action)
{
    std::vector<uint8_t> uuid_vector = ESPRandom::uuid4();
    Serial.println("UUID V4:");
    Serial.println(ESPRandom::uuidToString(uuid_vector));
   // uint8_t uuid_array[16];
    //ESPRandom::uuid1(uuid_array);
    this->messageId = ESPRandom::uuidToString(uuid_vector);
    Serial.println("UUID generated:");
    Serial.println(messageId);
};

Message::~Message(){};

int Message::getMessageTypeId()
{
    return this->messageTypeId;
};

String Message::getMessageId()
{
    return this->messageId;
};

const char *Message::getAction()
{
    return this->action;
};
