#include "RequestStopTransactionResponse.h"

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