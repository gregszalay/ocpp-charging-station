#include "MyArduinoWebsocketsAdapter.h"
#include "DebugWebsocket.h"

MyArduinoWebsocketsAdapter::MyArduinoWebsocketsAdapter(WebsocketServerAddress &_wsAddress, OCPPEventHandlers *_eventHandlersPtr)
    : OCPPWebsocketVirtual(_wsAddress, _eventHandlersPtr)
{
}

MyArduinoWebsocketsAdapter::~MyArduinoWebsocketsAdapter()
{
}

void MyArduinoWebsocketsAdapter::open()
{

    OCPP_NETWORK()->setup();

    // server address, port and URL
    webSocket.begin(
        this->wsAddress.serverAddr,
        this->wsAddress.port,
        this->wsAddress.URL,
        this->wsAddress.protocol);

    webSocket.onEvent([this](WStype_t type, uint8_t *payload, size_t length)
                      {    
        switch (type)
        {
        case WStype_DISCONNECTED:
            DEBUG_WEBSOCKET("%s", "[WSc] Disconnected!\n");
            this->webSocket.disconnect();
            break;
        case WStype_CONNECTED:
            DEBUG_WEBSOCKET("[WSc] Connected to url: %s\n", payload);
            // send message to server when Connected
            // webSocket.sendTXT("Connected");

            break;
        case WStype_TEXT:
            //USE_DEBUG_WEBSOCKETf("[WSc] get text: %s\n", payload);
            DEBUG_WEBSOCKET("%s", "[WSc] DiscWStype_TEXT!\n");
            DEBUG_WEBSOCKET("[WSc] Payload ptr: %p\n", payload);
            if(payload == nullptr){
                break;
            }
            eventHandlersPtr->handleIncomingMessage(payload);
            // send message to server
            // webSocket.sendTXT("message here");
            break;
        case WStype_BIN:
            DEBUG_WEBSOCKET("[WSc] get binary length: %u\n", length);
            this->hexdump(payload, length);

            // send data to server
            // webSocket.sendBIN(payload, length);
            break;
        case WStype_ERROR:
        case WStype_FRAGMENT_TEXT_START:
        case WStype_FRAGMENT_BIN_START:
        case WStype_FRAGMENT:
        case WStype_FRAGMENT_FIN:
            break;
        } });

    // use HTTP Basic Authorization this is optional remove if not needed
    //  webSocket.setAuthorization("", "");

    webSocket.setReconnectInterval(5000);
    // webSocket.enableHeartbeat(15000, 3000, 2);

    DEBUG_WEBSOCKET("%s", "Connecting to websocket server...");
    while (!webSocket.isConnected())
    {
        webSocket.loop();
        DEBUG_WEBSOCKET("%s", ".");
        delay(500);
    }
}

void MyArduinoWebsocketsAdapter::close()
{
    this->webSocket.disconnect();
}

void MyArduinoWebsocketsAdapter::sendMessage(MESSAGE *message)
{
    String payloadTemp = (*message);
    DEBUG_WEBSOCKET("\n -->--> SENDING: \n %s \n\n", payloadTemp.c_str());
    this->webSocket.sendTXT(payloadTemp);
    this->eventHandlersPtr->handleOutgoingMessage(message);
}

void MyArduinoWebsocketsAdapter::loop()
{
    OCPP_NETWORK()->loop();
    webSocket.loop();
    if (!this->webSocket.isConnected())
    {
        DEBUG_LN_WEBSOCKET("%s", "Websocket connection lost. Rebooting...");
        delay(1000);
        ESP.restart();
    }
}

void MyArduinoWebsocketsAdapter::hexdump(const void *mem, uint32_t len, uint8_t cols)
{
    const uint8_t *src = (const uint8_t *)mem;
    DEBUG_WEBSOCKET("\n[HEXDUMP] Address: 0x%08X len: 0x%X (%d)", (ptrdiff_t)src, len, len);
    for (uint32_t i = 0; i < len; i++)
    {
        if (i % cols == 0)
        {
            DEBUG_WEBSOCKET("\n[0x%08X] 0x%08X: ", (ptrdiff_t)src, i);
        }
        DEBUG_WEBSOCKET("%02X ", *src);
        src++;
    }
    DEBUG_WEBSOCKET("%s", "\n");
}
