#include "CALL_Message.h"

CALL_Message::CALL_Message(String _action)
    : MESSAGE(2)
{
    std::vector<uint8_t> uuid_vector = ESPRandom::uuid4();
    messageId = ESPRandom::uuidToString(uuid_vector);
};

String CALL_Message::getAction() const
{
    return this->action;
};

void CALL_Message::buildFrame()
{
    MESSAGE::buildFrame();
    jsonDoc.add(action);
}
