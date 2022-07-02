#include <map>
#include <functional>
#include "MESSAGE.h"
#include "CustomImplementation.h"
#include "WebsocketConnection.h"
#include "BootNotificationRequest.h"
#include "HeartbeatRequest.h"
#include "AuthorizeRequest.h"

class MY_OCPP : public CustomImplementation
{
public:
    MY_OCPP(WebsocketConnection _ws);
    void setup() override;
    void loop() override;
    std::map<String, std::function<MESSAGE *(StaticJsonDocument<200>)>> *getRequestHandlers() override;
};