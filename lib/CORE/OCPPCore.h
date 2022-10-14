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
        this->wsImpl->open();
        this->ocppImplementation->setup();
    };
    void loop()
    {
        this->wsImpl->loop();
        this->ocppImplementation->loop();
        vTaskDelay(5);
        delay(5);
    };
};