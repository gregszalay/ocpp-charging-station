#include "enums/BootReasonEnumType.h"

std::map<BootReasonEnumType, String> BOOT_REASON_ENUM_TYPE()
{
    std::map<BootReasonEnumType, String> myMap;
    map_init(myMap)(ApplicationReset, "ApplicationReset")(FirmwareUpdate, "FirmwareUpdate")(LocalReset, "LocalReset")(PowerUp, "PowerUp")(RemoteReset, "RemoteReset")(ScheduledReset, "ScheduledReset")(Triggered, "Triggered")(Unknown, "Unknown")(Watchdog, "Watchdog");
    return myMap;
}
