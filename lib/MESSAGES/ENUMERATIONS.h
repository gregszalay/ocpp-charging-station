#pragma once
#include <Arduino.h>
#include <map>

namespace ENUMERATIONS
{
    /******************************************************************************/

    enum BootReasonEnumType
    {

        ApplicationReset, // The Charging Station rebooted due to an application error.
        FirmwareUpdate,   // The Charging Station rebooted due to a firmware update.
        LocalReset,       // The Charging Station rebooted due to a local reset command.
        PowerUp,          // The Charging Station powered up and registers itself with the CSMS.
        RemoteReset,      // The Charging Station rebooted due to a remote reset command.
        ScheduledReset,   // The Charging Station rebooted due to a scheduled reset command.
        Triggered,        // Requested by the CSMS via a TriggerMessage
        Unknown,          // The boot reason is unknown.
        Watchdog          // The Charging Station rebooted due to an elapsed watchdog timer.

    };
    std::map<BootReasonEnumType, String> &BOOT_REASON_ENUM_TYPE();

    /******************************************************************************/

    enum IdTokenEnumType
    {

        Central,        // A centrally, in the CSMS (or other server) generated id (for example used for a remotely started transaction
                        // that is activated by SMS). No format defined, might be a UUID
        eMAID,          // Electro-mobility account id as defined in ISO 15118
        ISO14443,       // ISO 14443 UID of RFID card. It is represented as an array of 4 or 7 bytes in hexadecimal representation.
        ISO15693,       // ISO 15693 UID of RFID card. It is represented as an array of 8 bytes in hexadecimal representation.
        KeyCode,        // User use a private key-code to authorize a charging transaction. For example: Pin-code
        Local,          // A locally generated id (e.g. internal id created by the Charging Station). No format defined, might be a UUID
        MacAddress,     //
        NoAuthorization // Transaction is started and no authorization possible. Charging Station only has a start button or mechanical
                        // key etc. IdToken field SHALL be left empty.

    };
    std::map<IdTokenEnumType, String> &ID_TOKEN_ENUM_TYPE();

    /******************************************************************************/

} // ENUMERATIONS