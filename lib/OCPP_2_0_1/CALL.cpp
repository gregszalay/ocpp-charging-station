#include "CALL.h"

CALL::CALL(String _action)
    : MESSAGE(2)
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
