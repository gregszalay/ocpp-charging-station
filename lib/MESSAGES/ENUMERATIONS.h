#pragma once
#include <Arduino.h>
#include <map>

namespace ENUMERATIONS
{
    /******************************************************************************/

    enum BootReasonEnumType
    {
        /** @brief The Charging Station rebooted due to an application error.*/
        ApplicationReset,
        /** @brief The Charging Station rebooted due to a firmware update.*/
        FirmwareUpdate,
        /** @brief The Charging Station rebooted due to a local reset command.*/
        LocalReset,
        /** @brief The Charging Station powered up and registers itself with the CSMS.*/
        PowerUp,
        /** @brief The Charging Station rebooted due to a remote reset command.*/
        RemoteReset,
        /** @brief The Charging Station rebooted due to a scheduled reset command.*/
        ScheduledReset,
        /** @brief Requested by the CSMS via a TriggerMessage*/
        Triggered,
        /** @brief The boot reason is unknown.*/
        Unknown,
        /** @brief The Charging Station rebooted due to an elapsed watchdog timer.*/
        Watchdog,
    };
    std::map<BootReasonEnumType, String> &BOOT_REASON_ENUM_TYPE();

    /******************************************************************************/

    enum IdTokenEnumType
    {
        /** @brief A centrally, in the CSMS (or other server) generated id (for example used for a remotely started transaction
         * that is activated by SMS). No format defined, might be a UUID*/
        Central,
        /** @brief Electro-mobility account id as defined in ISO 15118 */
        eMAID,
        /** @brief ISO 14443 UID of RFID card. It is represented as an array of 4 or 7 bytes in hexadecimal representation. */
        ISO14443,
        /** @brief ISO 15693 UID of RFID card. It is represented as an array of 8 bytes in hexadecimal representation. */
        ISO15693,
        /** @brief User use a private key-code to authorize a charging transaction. For example: Pin-code */
        KeyCode,
        /** @brief A locally generated id (e.g. internal id created by the Charging Station). No format defined, might be a UUID */
        Local,
        MacAddress,
        /** @brief Transaction is started and no authorization possible. Charging Station only has a start button or mechanical
         * key etc. IdToken field SHALL be left empty.
         */
        NoAuthorization,

    };
    std::map<IdTokenEnumType, String> &ID_TOKEN_ENUM_TYPE();

    /******************************************************************************/

    enum CancelReservationStatusEnumType
    {
        /** @brief Reservation for the identifier has been canceled. */
        CancelReservationStatusEnumType__Accepted,
        /** @brief Reservation could not be canceled, because there is no reservation active for the identifier. */
        CancelReservationStatusEnumType__Rejected,
    };
    std::map<CancelReservationStatusEnumType, String> &CANCEL_RESERVATION_STATUS_ENUM_TYPE();

    /******************************************************************************/

    enum RequestStartStopStatusEnumType
    {
        /** @brief Command will be executed. */
        RequestStartStopStatus__Accepted,
        /** @brief Command will not be executed. */
        RequestStartStopStatus__Rejected,
    };
    std::map<RequestStartStopStatusEnumType, String> &REQUEST_START_STOP_STATUS_ENUM_TYPE();

    /******************************************************************************/

} // ENUMERATIONS