#include "MyOCPPImplementation.h"
#include "H_Reservation.h"
#include "F_RemoteControl.h"
#include "F_RemoteControl.h"

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
    Serial.println("Creating BootNotificationRequest...");
    BootNotificationRequest *bootNotificationRequest = new BootNotificationRequest(
        ENUMERATIONS::BootReasonEnumType::PowerUp,
        "001",
        "Home Charging Station",
        "Gergely Szalay",
        [](StaticJsonDocument<200> payloadObj)
        {
            Serial.println("Received BootNotificationResponse");
        });

    this->wsImpl->sendMessage(bootNotificationRequest);
    delay(3000);

    // AuthorizeReq
    Serial.println("Creating AuthorizeRequest...");
    DATATYPES::IdTokenType idTokenZ("1234", ENUMERATIONS::IdTokenEnumType::ISO14443);
    AuthorizeRequest *authorizeRequest =
        new AuthorizeRequest(idTokenZ, [](StaticJsonDocument<200> payloadObj)
                             { Serial.println("Received AuthorizeResponse"); });
    this->wsImpl->sendMessage(authorizeRequest);
    delay(3000);

    // // CancelReservationResponse
    // Serial.println("CancelReservationResponse...");
    // DATATYPES::StatusInfoType statusInfo_1("dfvdfv", "jhg");
    // CancelReservationResponse *cancelReserve =
    //     new CancelReservationResponse(
    //         "6b654278-5836-4989-843f-378e99999999",
    //         ENUMERATIONS::CancelReservationStatusEnumType::CancelReservationStatusEnumType__Accepted,
    //         statusInfo_1);
    // this->wsImpl->sendMessage(cancelReserve);

    // // RequestStartTransactionResponse
    // Serial.println("RequestStartTransactionResponse...");
    // DATATYPES::StatusInfoType statusInfo_2("dfvdfvfvfdv", "jhdfvdfg");
    // RequestStartTransactionResponse *remoteStartResponse =
    //     new RequestStartTransactionResponse(
    //         "6b654278-5836-4989-843f-378e99999944",
    //         ENUMERATIONS::RequestStartStopStatusEnumType::RequestStartStopStatus__Accepted,
    //         "XYtransactionId",
    //         statusInfo_2);
    // this->wsImpl->sendMessage(remoteStartResponse);

    // // RequestStopTransactionResponse
    // Serial.println("RequestStopTransactionResponse...");
    // DATATYPES::StatusInfoType statusInfo_3("dfvdfvfvfdv3", "jhdfvdfg");
    // RequestStopTransactionResponse *remoteStopResponse =
    //     new RequestStopTransactionResponse(
    //         "6b654278-5836-4989-843f-378e99999955",
    //         "XYtransactionId2",
    //         ENUMERATIONS::RequestStartStopStatusEnumType::RequestStartStopStatus__Accepted,
    //         statusInfo_3);
    // this->wsImpl->sendMessage(remoteStopResponse);
}

void MyOCPPImplementation::loop()
{
    if (millis() - lastMessageSentMillis >= 10000)
    {
        HeartbeatRequest *heartbeatRequest =
            new HeartbeatRequest([](StaticJsonDocument<200> payloadObj)
                                 { Serial.println("Received HeartbeatResponse"); });
        this->wsImpl->sendMessage(heartbeatRequest);

        lastMessageSentMillis = millis();
    }
}