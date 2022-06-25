//#pragma once

#include "Arduino.h"
/* #include "FS.h"
#include <LITTLEFS.h> */
#include <WiFi.h>
#include <WiFiClientSecure.h>

class Network
{
    static Network *instance;
    Network();

public:
    static Network *getInstance()
    {
        if (!Network::instance)
            instance = new Network;
        return instance;
    }

    ~Network();
    void setup();
    void loop();
};

Network *NETWORK();