#include "MemoryCheck.h"

int MemoryCheck::objectsOnHeap = 0;
unsigned long MemoryCheck::MAX_OBJECTS = 15;

MemoryCheck::MemoryCheck()
{
}

MemoryCheck::~MemoryCheck()
{
}

void MemoryCheck::newnew()
{
    MemoryCheck::objectsOnHeap++;
    Serial.printf("ADDED OBJECT. HEAP OBJECTS: %d \n", MemoryCheck::objectsOnHeap);

    if (MemoryCheck::objectsOnHeap > MAX_OBJECTS)
    {
        Serial.println("*****//////------|||||||++++++++;;;;;;;;;;;;");
        Serial.println("MAX HEAP OBJECTS EXCEEDED!!");
        Serial.println("*****//////------|||||||++++++++;;;;;;;;;;;;");
    }
}
void MemoryCheck::freeOne()
{
    MemoryCheck::objectsOnHeap--;
    Serial.printf("DELETED OBJECT. HEAP OBJECTS: %d \n", MemoryCheck::objectsOnHeap);
}
