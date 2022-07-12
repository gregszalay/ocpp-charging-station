#include "H_Reservation.h"

CancelReservationResponse::CancelReservationResponse(
    String _messageId,
    ENUMERATIONS::CancelReservationStatusEnumType _status,
    DATATYPES::StatusInfoType _statusInfo) : CALLRESULT(_messageId),
                                             status(_status),
                                             statusInfo(_statusInfo)
{
}

CancelReservationResponse::~CancelReservationResponse() {}

void CancelReservationResponse::buildPayload()
{
    JsonObject messageCore = jsonDoc.createNestedObject();
    messageCore["status"] = ENUMERATIONS::CANCEL_RESERVATION_STATUS_ENUM_TYPE()[this->status];
    JsonObject statusInfo = messageCore.createNestedObject("statusInfo");
    messageCore["reasonCode"] = this->statusInfo.getReasonCode();
    messageCore["additionalInfo"] = this->statusInfo.getAdditionalInfo();
}