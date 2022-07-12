#include "F_RemoteControl.h"

/******************************************************************************/

RequestStartTransactionResponse::RequestStartTransactionResponse(
    String _messageId,
    ENUMERATIONS::RequestStartStopStatusEnumType _status,
    String _transactionId,
    DATATYPES::StatusInfoType _statusInfo) : CALLRESULT(_messageId),
                                             status(_status),
                                             transactionId(_transactionId),
                                             statusInfo(_statusInfo)
{
}

RequestStartTransactionResponse::~RequestStartTransactionResponse() {}

void RequestStartTransactionResponse::buildPayload()
{
    JsonObject messageCore = jsonDoc.createNestedObject();
    messageCore["transactionId"] = this->transactionId;
    messageCore["status"] = ENUMERATIONS::REQUEST_START_STOP_STATUS_ENUM_TYPE()[this->status];
    JsonObject statusInfo = messageCore.createNestedObject("statusInfo");
    messageCore["reasonCode"] = this->statusInfo.getReasonCode();
    messageCore["additionalInfo"] = this->statusInfo.getAdditionalInfo();
}

/******************************************************************************/

RequestStopTransactionResponse::RequestStopTransactionResponse(
    String _messageId,
    String _transactionId,
    ENUMERATIONS::RequestStartStopStatusEnumType _status,
    DATATYPES::StatusInfoType _statusInfo) : CALLRESULT(_messageId),
                                             transactionId(_transactionId),
                                             status(_status),
                                             statusInfo(_statusInfo)
{
}

RequestStopTransactionResponse::~RequestStopTransactionResponse() {}

void RequestStopTransactionResponse::buildPayload()
{
    JsonObject messageCore = jsonDoc.createNestedObject();
    messageCore["transactionId"] = this->transactionId;
    messageCore["status"] = ENUMERATIONS::REQUEST_START_STOP_STATUS_ENUM_TYPE()[this->status];
    JsonObject statusInfo = messageCore.createNestedObject("statusInfo");
    messageCore["reasonCode"] = this->statusInfo.getReasonCode();
    messageCore["additionalInfo"] = this->statusInfo.getAdditionalInfo();
}