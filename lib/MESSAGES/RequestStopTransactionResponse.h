#pragma once
#include "MESSAGE.h"

class RequestStopTransactionResponse : public CALLRESULT
{
    String transactionId; // TODO: implement identifierString type
    ENUMERATIONS::RequestStartStopStatusEnumType status;
    DATATYPES::StatusInfoType statusInfo;
    void buildPayload() override;

public:
    RequestStopTransactionResponse(
        String _messageId,
        String _transactionId,
        ENUMERATIONS::RequestStartStopStatusEnumType _status,
        DATATYPES::StatusInfoType _statusInfo);
    ~RequestStopTransactionResponse();
};