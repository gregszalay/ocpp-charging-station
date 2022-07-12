#include "RequestStartTransactionResponse.h"

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
    messageCore["status"] = ENUMERATIONS::REQUEST_START_STOP_STATUS_ENUM_TYPE()[this->status];
    JsonObject statusInfo = messageCore.createNestedObject("statusInfo");
    messageCore["reasonCode"] = this->statusInfo.getReasonCode();
    messageCore["additionalInfo"] = this->statusInfo.getAdditionalInfo();
}