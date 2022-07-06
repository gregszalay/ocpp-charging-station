#pragma once
#include <Arduino.h>
#include <string.h>
#include "Debug.h"

#define WEBSOCKET_DEBUG true

#if WEBSOCKET_DEBUG
#define DEBUG_LN_WEBSOCKET(FORMAT, ...) \
    {                                   \
        DEBUG_LN(FORMAT, __VA_ARGS__)   \
    }
#define DEBUG_WEBSOCKET(FORMAT, ...) \
    {                                \
        DEBUG(FORMAT, __VA_ARGS__)   \
    }
#else
#define DEBUG_LN_WEBSOCKET(FORMAT, ...) \
    {                                   \
    }
#define DEBUG_WEBSOCKET(FORMAT, ...) \
    {                                \
    }
#endif