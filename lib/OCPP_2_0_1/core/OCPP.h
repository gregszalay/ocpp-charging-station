/* #include <Arduino.h>
#include "FS.h"
#include <LITTLEFS.h>

#include <WebsocketToCSMS.h>
//#include <config.h>
#include <ArduinoJson.h>
#include "messages/BootNotificationRequest.h"
#include "messages/HeartbeatRequest.h"
#include "enums/BootReasonEnumType.h"
#include <map> */

class OCPP
{

public:
    OCPP();
    ~OCPP();
    void setup();
    void loop();
};
