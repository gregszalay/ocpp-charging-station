/**
 * @file MESSAGE.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-02
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once
#include <Arduino.h>
#include <ArduinoJson.h>
#include <ESPRandom.h>
#include "MemoryCheck.h"
#include "ENUMERATIONS.h"
#include "DATATYPES.h"

enum MESSAGE_TYPE_ID_ENUM
{
    CALL = 2,       // Request
    CALLRESULT = 3, // Reply
    CALLERROR = 4,  // Error message
};

/*******************************************************************************
 * @brief General message (pure virtual)
 */
class MESSAGE
{
protected:
    uint8_t messageTypeId;
    String messageId;
    String message;
    StaticJsonDocument<500> jsonDoc;
    virtual void buildPayload() = 0;
    void buildMessage();

public:
    void buildFrame();
    MESSAGE(uint8_t _messageTypeId, String _messageId = "");
    virtual ~MESSAGE() { MemoryCheck::freeOne(); }
    virtual std::function<void(StaticJsonDocument<200>)> getResponseCallback() const = 0;
    uint8_t getMessageTypeId() const;
    String getMessageId() const;
    String getMessage();
    operator String() { return getMessage(); }
};

/*******************************************************************************
 * @brief General CALL message
 * Reference:
 * [OCPP 2.0.1][Part 4 - JSON over WebSockets implementation guide][4.2.1]
 */
class CALL : public MESSAGE
{
protected:
    String action;

public:
    void buildFrame();
    CALL(String _action);
    String getAction() const;
};

/*******************************************************************************
 * @brief General CALLRESULT message
 * Reference:
 * [OCPP 2.0.1][Part 4 - JSON over WebSockets implementation guide][4.2.2]
 */
class CALLRESULT : public MESSAGE
{
public:
    CALLRESULT(uint8_t _messageTypeId, String _messageId);
};

/*******************************************************************************
 * @brief General CALLERROR message
 * Reference:
 * [OCPP 2.0.1][Part 4 - JSON over WebSockets implementation guide][4.2.3]
 */
class CALLERROR : public MESSAGE
{
protected:
    String errorCode;
    String errorDescription;
    void buildPayload() override;

public:
    void buildFrame();
    CALLERROR(String _messageId, String _errorCode, String _errorDescription);
    String getErrorCode() const { return this->errorCode; }
    String getErrorDescription() const { return this->errorDescription; }
};
