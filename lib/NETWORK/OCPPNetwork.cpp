#include "OCPPNetwork.h"
#include "PRIVATE.h"

OCPPNetwork *OCPP_NETWORK()
{
    return OCPPNetwork::getInstance();
}

OCPPNetwork *OCPPNetwork::instance = nullptr;

void OCPPNetwork::setup()
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

void OCPPNetwork::loop()
{
    if (WiFi.status() != WL_CONNECTED)
    {
        Serial.print("OCPPNetwork disconnected. Rebooting...");
        delay(1000);
        ESP.restart();
    }
}

OCPPNetwork::OCPPNetwork()
{
}

OCPPNetwork::~OCPPNetwork()
{
}
