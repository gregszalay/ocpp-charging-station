#include "ENUMERATIONS.h"

/******************************************************************************/

std::map<BootReasonEnumType, String> BOOT_REASON_MAP;
std::map<BootReasonEnumType, String> &BOOT_REASON_ENUM_TYPE()
{
    BOOT_REASON_MAP[BootReasonEnumType::ApplicationReset] = "ApplicationReset";
    BOOT_REASON_MAP[BootReasonEnumType::FirmwareUpdate] = "FirmwareUpdate";
    BOOT_REASON_MAP[BootReasonEnumType::LocalReset] = "LocalReset";
    BOOT_REASON_MAP[BootReasonEnumType::PowerUp] = "PowerUp";
    BOOT_REASON_MAP[BootReasonEnumType::RemoteReset] = "RemoteReset";
    BOOT_REASON_MAP[BootReasonEnumType::ScheduledReset] = "ScheduledReset";
    BOOT_REASON_MAP[BootReasonEnumType::Triggered] = "Triggered";
    BOOT_REASON_MAP[BootReasonEnumType::Unknown] = "Unknown";
    BOOT_REASON_MAP[BootReasonEnumType::Watchdog] = "Watchdog";
    return BOOT_REASON_MAP;
}

/******************************************************************************/

std::map<IdTokenEnumType, String> ID_TOKEN_MAP;
std::map<IdTokenEnumType, String> &ID_TOKEN_ENUM_TYPE()
{
    ID_TOKEN_MAP[IdTokenEnumType::Central] = "Central";
    ID_TOKEN_MAP[IdTokenEnumType::eMAID] = "eMAID";
    ID_TOKEN_MAP[IdTokenEnumType::ISO14443] = "ISO14443";
    ID_TOKEN_MAP[IdTokenEnumType::ISO15693] = "ISO15693";
    ID_TOKEN_MAP[IdTokenEnumType::KeyCode] = "KeyCode";
    ID_TOKEN_MAP[IdTokenEnumType::Local] = "Local";
    ID_TOKEN_MAP[IdTokenEnumType::MacAddress] = "MacAddress";
    ID_TOKEN_MAP[IdTokenEnumType::NoAuthorization] = "NoAuthorization";
    return ID_TOKEN_MAP;
}

/******************************************************************************/