#include "CALLERROR.h"

CALLERROR::CALLERROR(
    String _messageId,
    String _errorCode,
    String _errorDescription) : MESSAGE(4, _messageId)
{
    this->messageId = _messageId;
    this->errorCode = _errorCode;
}

void CALLERROR::buildPayload()
{
    jsonDoc.add(this->errorCode);
    jsonDoc.add(this->errorDescription);
    jsonDoc.add("");
}