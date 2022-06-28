#include "WebsocketToCSMS.h"

WebsocketToCSMS::WebsocketToCSMS(String serverAddr, uint16_t port,
                                                 String URL, String protocol)
{
    this->serverAddr = serverAddr;
    this->port = port;
    this->URL = URL;
    this->protocol = protocol;
}

WebsocketToCSMS::~WebsocketToCSMS()
{
}

void WebsocketToCSMS::processResponse(uint8_t *payload)
{
    StaticJsonDocument<200> responseObject;
    deserializeJson(responseObject, payload);
    if (sentMessages[responseObject[1]])
    {
        CALL_Message *msgPtr = sentMessages[responseObject[1]];
        msgPtr->getResponseCallback()(responseObject);
        sentMessages.erase(sentMessages.find(responseObject[1]));
        delete msgPtr;
    }
}

void WebsocketToCSMS::open()
{

    NETWORK()->setup();

    // server address, port and URL
    webSocket.begin(this->serverAddr, this->port, this->URL, this->protocol);

    webSocket.onEvent([this](WStype_t type, uint8_t *payload, size_t length)
    {    
        switch (type)
        {
        case WStype_DISCONNECTED:
            USE_SERIAL.printf("[WSc] Disconnected!\n");
            this->webSocket.disconnect();
            break;
        case WStype_CONNECTED:
            USE_SERIAL.printf("[WSc] Connected to url: %s\n", payload);
            // send message to server when Connected
            // webSocket.sendTXT("Connected");

            break;
        case WStype_TEXT:
            USE_SERIAL.printf("[WSc] get text: %s\n", payload);
            this->processResponse(payload);
        
            // send message to server
            // webSocket.sendTXT("message here");
            break;
        case WStype_BIN:
            USE_SERIAL.printf("[WSc] get binary length: %u\n", length);
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

    Serial.print("Connecting to websocket server...");
    while (!webSocket.isConnected())
    {
        webSocket.loop();
        Serial.print(".");
        delay(500);
    }
}
void WebsocketToCSMS::loop()
{
    NETWORK()->loop();
    webSocket.loop();
    if (!this->webSocket.isConnected())
    {
        Serial.println("Websocket connection lost. Rebooting...");
        delay(1000);
        ESP.restart();
    }
}

void WebsocketToCSMS::hexdump(const void *mem, uint32_t len, uint8_t cols)
{
    const uint8_t *src = (const uint8_t *)mem;
    USE_SERIAL.printf("\n[HEXDUMP] Address: 0x%08X len: 0x%X (%d)", (ptrdiff_t)src, len, len);
    for (uint32_t i = 0; i < len; i++)
    {
        if (i % cols == 0)
        {
            USE_SERIAL.printf("\n[0x%08X] 0x%08X: ", (ptrdiff_t)src, i);
        }
        USE_SERIAL.printf("%02X ", *src);
        src++;
    }
    USE_SERIAL.printf("\n");
}

void WebsocketToCSMS::sendRequest(CALL_Message *message)
{
    sentMessages[message->getMessageId()] = message;
    String payloadTemp = message->getMessage();
    this->webSocket.sendTXT(payloadTemp);
}
