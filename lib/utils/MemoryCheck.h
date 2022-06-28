#pragma once

#include "Arduino.h"

class MemoryCheck
{
    static int objectsOnHeap;
    static unsigned long MAX_OBJECTS;

public:
    MemoryCheck();
    ~MemoryCheck();
    static void newnew();
    static void freeOne();
};
