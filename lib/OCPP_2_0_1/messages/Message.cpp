#include "Message.h"

Message::Message(int messageTypeId, String action)
    : messageTypeId(messageTypeId), action(action)
{
    std::vector<uint8_t> uuid_vector = ESPRandom::uuid4();
    this->messageId = ESPRandom::uuidToString(uuid_vector);
    Serial.println("UUID generated:");
    Serial.println(messageId);
/*     createMessage(message);
    Serial.println("message");
    Serial.println(message); */
};

Message::~Message(){};

int Message::getMessageTypeId() const
{
    return this->messageTypeId;
};

String Message::getMessageId() const
{
    return this->messageId;
};

String Message::getAction() const
{
    return this->action;
};

String Message::getMessage() const
{
    return this->message;
};
