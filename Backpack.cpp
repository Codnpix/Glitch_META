#include "Backpack.h"

Backpack::Backpack()
{
    this->objectsCount = 0;
    for (uint8_t i = 0; i < NB_STACK_FRAGMENTS; i++)
    {
        this->objects[i].id = '0';
    }
}

void Backpack::addObject(Object obj)
{
  this->objects[this->objectsCount] = obj;
  this->objectsCount ++;
}

uint8_t Backpack::getObjectCount()
{
    return this->objectsCount;
}

Object Backpack::getObject(uint8_t i)
{
    return this->objects[i];
}

bool Backpack::isEmpty()
{
    for (uint8_t i = 0; i < NB_STACK_FRAGMENTS; i++)
    {
        if (this->objects[i].id != '0') return false;//we found at least one object
    }
    return true;
}

uint8_t Backpack::dropLastObject()
{
    uint8_t lastObjectId;
    for (uint8_t i = NB_STACK_FRAGMENTS - 1; i >= 0; i--)
    {
        if (this->objects[i].id != '0')
        {
            lastObjectId = this->objects[i].id;//save the object id to return
            this->objects[i].id = '0';//drop object
            this->objectsCount--;
            return lastObjectId;
        }
    }
}
