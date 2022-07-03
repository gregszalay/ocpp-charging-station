#include "OCPPWebsocketVirtual.h"

WebsocketServerAddress::WebsocketServerAddress(
    String _serverAddr,
    uint16_t _port,
    String _URL,
    String _protocol) : serverAddr(_serverAddr),
                        port(_port),
                        URL(_URL),
                        protocol(_protocol) {}

WebsocketServerAddress::~WebsocketServerAddress() {}

OCPPWebsocketVirtual::OCPPWebsocketVirtual(WebsocketServerAddress &_wsAddress, OCPPEventHandlers *_eventHandlersPtr)
    : wsAddress(_wsAddress), eventHandlersPtr(_eventHandlersPtr)
{
}
