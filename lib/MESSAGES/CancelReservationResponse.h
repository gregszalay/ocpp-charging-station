#pragma once
#include "MESSAGE.h"

class CancelReservationResponse : public CALLRESULT
{
    ENUMERATIONS::CancelReservationStatusEnumType status;
    DATATYPES::StatusInfoType statusInfo;
    void buildPayload() override;

public:
    CancelReservationResponse(
        String _messageId,
        ENUMERATIONS::CancelReservationStatusEnumType _status,
        DATATYPES::StatusInfoType _statusInfo);
    ~CancelReservationResponse();
};