//#pragma once

#include "Arduino.h"
#include "MemoryCheck.h"
/* #include "FS.h"
#include <LITTLEFS.h> */
#include <WiFi.h>
#include <WiFiClientSecure.h>

class OCPPNetwork
{
    static OCPPNetwork *instance;
    OCPPNetwork();

public:
    static OCPPNetwork *getInstance()
    {
        if (!OCPPNetwork::instance)
        {
            instance = new OCPPNetwork;
              MemoryCheck::newnew();

        }
        return instance;
    }

    ~OCPPNetwork();
    void setup();
    void loop();
};

OCPPNetwork *OCPP_NETWORK();