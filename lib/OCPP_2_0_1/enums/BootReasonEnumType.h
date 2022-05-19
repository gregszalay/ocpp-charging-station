#pragma once

#include <Arduino.h>

#include <config.h>
#include "common/map_init_helper.h"

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

std::map<BootReasonEnumType, const char *> BOOT_REASON_ENUM_TYPE();

