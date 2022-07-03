#include "VirtualOCPP.h"

VirtualOCPP::VirtualOCPP(
    OCPPWebsocketVirtual *_wsImpl,
    SentMessageRepository *_sentMessagesRepo,
    VirtualRequestHandlerRepository *_reqHandlerRepo)
    : wsImpl(_wsImpl),
      sentMessagesRepo(_sentMessagesRepo),
      reqHandlerRepo(_reqHandlerRepo) {}

void VirtualOCPP::setup()
{
}

void VirtualOCPP::loop()
{
}
