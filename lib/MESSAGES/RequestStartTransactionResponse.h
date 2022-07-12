#pragma once
#include "MESSAGE.h"

class RequestStartTransactionResponse : public CALLRESULT
{
    ENUMERATIONS::RequestStartStopStatusEnumType status;
    String transactionId; // TODO: implement identifierString type
    DATATYPES::StatusInfoType statusInfo;
    void buildPayload() override;

public:
    RequestStartTransactionResponse(
        String _messageId,
        ENUMERATIONS::RequestStartStopStatusEnumType _status,
        String _transactionId,
        DATATYPES::StatusInfoType _statusInfo);
    ~RequestStartTransactionResponse();
};