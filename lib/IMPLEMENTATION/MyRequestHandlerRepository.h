#include "Arduino.h"
#include "VirtualRequestHandlerRepository.h"
#include "MESSAGE.h"

class MyRequestHandlerRepository : public VirtualRequestHandlerRepository
{
    /**
     * @brief Map of request actions to handler functions.
     * Initialized with default callback functions.
     *
     */
    std::map<String, std::function<MESSAGE *(StaticJsonDocument<200>)>> *requestHandlerMap =
        new std::map<String, std::function<MESSAGE *(StaticJsonDocument<200>)>>{
            /******************************************************************/
            {"Authorize",
             [](StaticJsonDocument<200> payloadObj)
             {
                 Serial.print("Id token:   ");
                 Serial.println((const char *)payloadObj[3]["idToken"]["idToken"]);
                 Serial.println((const char *)payloadObj[3]["idToken"]["type"]);
                 return new MESSAGE(3);
             }},
            /******************************************************************/
            {"BootNotification",
             [](StaticJsonDocument<200> payloadObj)
             {
                 Serial.print("Reason:   ");
                 Serial.println((const char *)payloadObj[3]["reason"]);
                 return new MESSAGE(3);
             }},
            /******************************************************************/
            {"RequestStartTransaction",
             [](StaticJsonDocument<200> payloadObj)
             {
                 Serial.print("Received RequestStartTransaction Request");
                 return new MESSAGE(3);
             }},
            /******************************************************************/
            {"RequestStopTransaction",
             [](StaticJsonDocument<200> payloadObj)
             {
               Serial.print("Received RequestStopTransaction Request");
                 return new MESSAGE(3);
             }},
            /******************************************************************/
        };

public:
    std::map<String, std::function<MESSAGE *(StaticJsonDocument<200>)>> *getRequestHandlers() override
    {
        return this->requestHandlerMap;
    }
};