#pragma once
#include "OCPPWebsocketVirtual.h"
#include "VirtualOCPP.h"
#include "OCPPEventHandlers.h"

class OCPPCore
{
    VirtualOCPP *ocppImplementation = nullptr;
    OCPPWebsocketVirtual *wsImpl = nullptr;

public:
    OCPPCore(VirtualOCPP *_ocppImplementation, OCPPWebsocketVirtual *_wsImpl);
    ~OCPPCore();
    void setup()
    {
        this->ocppImplementation->setup();
        this->wsImpl->open();
    };
    void loop()
    {
        this->ocppImplementation->loop();
        this->wsImpl->loop();
    };
};