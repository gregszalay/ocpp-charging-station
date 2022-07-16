
#pragma once
#include <Arduino.h>
#include <string.h>
#include "Debug.h"

#ifdef CORE_DEBUG
#define DEBUG_LN_CORE(FORMAT, ...)    \
    {                                 \
        DEBUG_LN(FORMAT, __VA_ARGS__) \
    }
#define DEBUG_CORE(FORMAT, ...)    \
    {                              \
        DEBUG(FORMAT, __VA_ARGS__) \
    }
#else
#define DEBUG_LN_CORE(FORMAT, ...) \
    {                              \
    }
#define DEBUG_CORE(FORMAT, ...) \
    {                           \
    }
#endif