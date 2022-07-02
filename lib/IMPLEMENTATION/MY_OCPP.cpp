#include "MY_OCPP.h"


MY_OCPP::MY_OCPP(WebsocketConnection _ws) : CustomImplementation(_ws){};

void MY_OCPP::setup()
{
    ws.open();

    // Bootnotification
    Serial.println("bootNotification...");
    BootNotificationRequest *bootNotificationRequest = new BootNotificationRequest(
        ENUMERATIONS::BootReasonEnumType::PowerUp,
        "001",
        "RevolutionCharger",
        "chargerevolution.net");
    MemoryCheck::newnew();
    this->sendMessage(bootNotificationRequest, [](StaticJsonDocument<200> payloadObj)
                      {
                 Serial.print("Reason:   ");
                 Serial.println((const char *)payloadObj[3]["reason"]);
                 return new MESSAGE(3); });

    // AuthorizeReq
    Serial.println("authorize...");
    DATATYPES::IdTokenType idTokenZ("abcd", ENUMERATIONS::IdTokenEnumType::ISO14443);
    AuthorizeRequest *authorizeRequest = new AuthorizeRequest(idTokenZ);
    MemoryCheck::newnew();
    this->sendMessage(authorizeRequest, [](StaticJsonDocument<200> payloadObj)
                      {
                 Serial.print("Id token:   ");
                 Serial.println((const char *)payloadObj[3]["idToken"]["idToken"]);
                 Serial.println((const char *)payloadObj[3]["idToken"]["type"]);
                 return new MESSAGE(3); });
}

void MY_OCPP::loop()
{
    ws.loop();

    if (millis() - lastMessageSentMillis >= 3000)
    {
        HeartbeatRequest *heartbeatRequest = new HeartbeatRequest;
        MemoryCheck::newnew();
        this->sendMessage(heartbeatRequest, [](StaticJsonDocument<200> payloadObj)
                          { Serial.print("chargerTime:    ");
                                    Serial.println((long)payloadObj[3]["chargerTime"]); });

        lastMessageSentMillis = millis();
    }
}

std::map<String, std::function<MESSAGE *(StaticJsonDocument<200>)>> *MY_OCPP::getRequestHandlers()
{
    return new std::map<String, std::function<MESSAGE *(StaticJsonDocument<200>)>>{
        /******************************************************************/
        {"Authorize",
         [](StaticJsonDocument<200> payloadObj)
         {
             Serial.print("Id token:   ");
             Serial.println((const char *)payloadObj[3]["idToken"]["idToken"]);
             Serial.println((const char *)payloadObj[3]["idToken"]["type"]);
             return new MESSAGE(3);
         }},
        /******************************************************************/
        {"BootNotification",
         [](StaticJsonDocument<200> payloadObj)
         {
             Serial.print("Reason:   ");
             Serial.println((const char *)payloadObj[3]["reason"]);
             return new MESSAGE(3);
         }},
        /******************************************************************/
    };
}
