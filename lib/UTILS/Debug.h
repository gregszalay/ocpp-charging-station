
#pragma once
#include <Arduino.h>
#include <string.h>

#define __FILENAME_LINUX__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define __FILENAME_LINUX_WIN__ (strrchr(__FILENAME_LINUX__, '\\') ? strrchr(__FILENAME_LINUX__, '\\') + 1 : __FILENAME_LINUX__)

#define FSTR(s) (s)

#ifdef DEBUG_ESP_PORT
#define DEBUG_LN(FORMAT, ...)                             \
    {                                                     \
        DEBUG_ESP_PORT.print("[");                        \
        DEBUG_ESP_PORT.print(__FILENAME_LINUX_WIN__);     \
        DEBUG_ESP_PORT.print(":");                        \
        DEBUG_ESP_PORT.print(__LINE__);                   \
        DEBUG_ESP_PORT.print("] ");                       \
        DEBUG_ESP_PORT.printf(FSTR(FORMAT), __VA_ARGS__); \
        DEBUG_ESP_PORT.println();                         \
        DEBUG_ESP_PORT.flush();                           \
    }
#define DEBUG(FORMAT, ...)                                \
    {                                                     \
        DEBUG_ESP_PORT.printf(FSTR(FORMAT), __VA_ARGS__); \
        DEBUG_ESP_PORT.flush();                           \
    }
#else
#define DEBUG_LN(FORMAT, ...)                     \
    {                                             \
        Serial.print("[");                        \
        Serial.print(__FILENAME_LINUX_WIN__);     \
        Serial.print(":");                        \
        Serial.print(__LINE__);                   \
        Serial.print("] ");                       \
        Serial.printf(FSTR(FORMAT), __VA_ARGS__); \
        Serial.println();                         \
        Serial.flush();                           \
    }
#define DEBUG(FORMAT, ...)                        \
    {                                             \
        Serial.printf(FSTR(FORMAT), __VA_ARGS__); \
        Serial.flush();                           \
    }
#endif