#pragma once
#include "MESSAGE.h"

/******************************************************************************/

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

/******************************************************************************/

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