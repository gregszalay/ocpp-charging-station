#pragma once
#include "Arduino.h"
#include "MESSAGE.h"

class SentMessageRepository
{

    /**
     * @brief Map of sent message ids to sent json messages.
     *
     */
    std::map<String, std::function<void(StaticJsonDocument<200>)>> sentMessages;

public:
    std::map<String, std::function<void(StaticJsonDocument<200>)>> *getSentMessages()
    {
        return &this->sentMessages;
    };
};