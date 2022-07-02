#include <Arduino.h>
#include "MemoryCheck.h"
#include "FS.h"
#include <LITTLEFS.h>
#include "WebsocketConnection.h"
#include <ArduinoJson.h>

#include "MY_OCPP.h"
//#include "core/OCPP.h"

// This needs to be the first object created!
static MemoryCheck MEMORY_CHECK;

WebsocketConnection CSMS_GOCPP_VPS("gergelyszalay.hu", 3000, "/echo", "ocpp2.0.1");
MY_OCPP my_ocpp(CSMS_GOCPP_VPS);

void setup()
{
  USE_SERIAL.begin(115200);
  USE_SERIAL.setDebugOutput(true);

  my_ocpp.setup();
}

void loop()
{
  my_ocpp.loop();
}