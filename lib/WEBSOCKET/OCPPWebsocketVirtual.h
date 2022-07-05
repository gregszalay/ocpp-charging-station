#pragma once
#include <Arduino.h>
#include <ArduinoJson.h>
#include "OCPPEventHandlers.h"
#include "VirtualRequestHandlerRepository.h"

class WebsocketServerAddress
{
public:
    String serverAddr;
    uint16_t port;
    String URL;
    String protocol;
    WebsocketServerAddress(
        String _serverAddr,
        uint16_t _port,
        String _URL,
        String _protocol);
    ~WebsocketServerAddress();
};

class OCPPWebsocketVirtual
{
protected:
    WebsocketServerAddress &wsAddress;
    OCPPEventHandlers *eventHandlersPtr = nullptr;

public:
    OCPPWebsocketVirtual(WebsocketServerAddress &wsAddress, OCPPEventHandlers *eventHandlersPtr);
    virtual ~OCPPWebsocketVirtual(){};
    virtual void open() = 0;
    virtual void close() = 0;
    virtual void loop(){};
    virtual void sendMessage(MESSAGE *message) = 0;
};