#include "MyOCPPImplementation.h"

MyOCPPImplementation::MyOCPPImplementation(
    OCPPWebsocketVirtual *_wsImpl,
    SentMessageRepository *_sentMessagesRepo,
    VirtualRequestHandlerRepository *_reqHandlerRepo)
    : VirtualOCPP(_wsImpl,
                  _sentMessagesRepo,
                  _reqHandlerRepo){};

void MyOCPPImplementation::setup()
{
    // Bootnotification
    Serial.println("bootNotification...");
    BootNotificationRequest *bootNotificationRequest = new BootNotificationRequest(
        ENUMERATIONS::BootReasonEnumType::PowerUp,
        "001",
        "RevolutionCharger",
        "chargerevolution.net",
        [](StaticJsonDocument<200> payloadObj)
        {
                 Serial.print("Reason:   ");
                 Serial.println((const char *)payloadObj[3]["reason"]);
                 return new MESSAGE(3); });

    MemoryCheck::newnew();
    this->wsImpl->sendMessage(bootNotificationRequest);

    // AuthorizeReq
    Serial.println("authorize...");
    DATATYPES::IdTokenType idTokenZ("abcd", ENUMERATIONS::IdTokenEnumType::ISO14443);
    AuthorizeRequest *authorizeRequest =
        new AuthorizeRequest(idTokenZ, [](StaticJsonDocument<200> payloadObj)
                             {
                 Serial.print("Id token:   ");
                 Serial.println((const char *)payloadObj[3]["idToken"]["idToken"]);
                 Serial.println((const char *)payloadObj[3]["idToken"]["type"]);
                 return new MESSAGE(3); });
    MemoryCheck::newnew();
    this->wsImpl->sendMessage(authorizeRequest);
}

void MyOCPPImplementation::loop()
{
    if (millis() - lastMessageSentMillis >= 3000)
    {
        HeartbeatRequest *heartbeatRequest =
            new HeartbeatRequest([](StaticJsonDocument<200> payloadObj)
                                 { Serial.print("chargerTime:    ");
                                    Serial.println((long)payloadObj[3]["chargerTime"]); });
        MemoryCheck::newnew();
        this->wsImpl->sendMessage(heartbeatRequest);

        lastMessageSentMillis = millis();
    }
}