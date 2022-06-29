#include "BootReasonEnumType.h"
#include <map>

std::map<BootReasonEnumType, String> myMap2;
std::map<BootReasonEnumType, String>& BOOT_REASON_ENUM_TYPE()
{
    myMap2[BootReasonEnumType::ApplicationReset] = "ApplicationReset";
    myMap2[BootReasonEnumType::FirmwareUpdate] = "FirmwareUpdate";
    myMap2[BootReasonEnumType::LocalReset] = "LocalReset";
    myMap2[BootReasonEnumType::PowerUp] = "PowerUp";
    myMap2[BootReasonEnumType::RemoteReset] = "RemoteReset";
    myMap2[BootReasonEnumType::ScheduledReset] = "ScheduledReset";
    myMap2[BootReasonEnumType::Triggered] = "Triggered";
    myMap2[BootReasonEnumType::Unknown] = "Unknown";
    myMap2[BootReasonEnumType::Watchdog] = "Watchdog";
    return myMap2;
}
