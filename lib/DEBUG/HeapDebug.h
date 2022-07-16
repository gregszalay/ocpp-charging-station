#pragma once
#include "Debug.h"
#include <cstdlib>
#include <new>

uint64_t HEAP_OBJECTS;
uint64_t last_print = millis();

void *operator new(std::size_t size)
{
    if (size == 0)
        ++size; // avoid std::malloc(0) which may return nullptr on success

    if (void *ptr = std::malloc(size))
    {
        ++HEAP_OBJECTS;
        return ptr;
    }
    throw std::bad_alloc{}; // required by [new.delete.single]/3
}

void operator delete(void *p)
{
    std::free(p);
    --HEAP_OBJECTS;
}

#ifdef HEAP_DEBUG
#define DEBUG_LN_HEAP(minIntervalMillis)               \
    {                                                  \
        if (millis() - last_print < minIntervalMillis) \
            return;                                    \
        DEBUG_LN("[HEAP OBJECTS:] %u", HEAP_OBJECTS)   \
        last_print = millis();                         \
    }
#define DEBUG_HEAP()              \
    {                             \
        DEBUG("%u", HEAP_OBJECTS) \
    }
#else
#define DEBUG_LN_HEAP() \
    {                   \
    }
#define DEBUG_HEAP() \
    {                \
    }
#endif