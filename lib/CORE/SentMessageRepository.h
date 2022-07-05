#pragma once
#include "Arduino.h"
#include "MESSAGE.h"

class SentMessageRepository
{

    /**
     * @brief Map of sent message ids to sent json messages.
     *
     */
    std::map<String, MESSAGE*> sentMessages;

public:
    std::map<String, MESSAGE*> *getSentMessages()
    {
        return &this->sentMessages;
    };
};