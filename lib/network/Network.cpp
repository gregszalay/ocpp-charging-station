#include "Network.h"
#include <config.h>

Network *NETWORK()
{
    return Network::getInstance();
}

Network *Network::instance = nullptr;

void Network::setup()
{
    Serial.print("Connecting...");

    WiFi.begin(SSID, WIFIPASSWORD);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void Network::loop()
{
    if (WiFi.status() != WL_CONNECTED)
    {
        Serial.print("Network disconnected. Rebooting...");
        delay(1000);
        ESP.restart();
    }
}

Network::Network()
{
}

Network::~Network()
{
    MemoryCheck::freeOne();
}
