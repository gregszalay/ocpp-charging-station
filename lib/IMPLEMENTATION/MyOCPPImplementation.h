#pragma once
#include <map>
#include <functional>
#include "MESSAGE.h"
#include "VirtualOCPP.h"
#include "B_Provisioning.h"
#include "G_Availability.h"
#include "C_Authorization.h"
#include "VirtualRequestHandlerRepository.h"
#include "SentMessageRepository.h"

class MyOCPPImplementation : public VirtualOCPP
{
public:
    MyOCPPImplementation(OCPPWebsocketVirtual *_wsImpl, SentMessageRepository *_sentMessagesRepo, VirtualRequestHandlerRepository *_reqHandlerRepo);
    void setup() override;
    void loop() override;
};