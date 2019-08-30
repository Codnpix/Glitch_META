#include "Backpack.h"

Backpack::Backpack()
{
  this->objectsCount = 0;
  for (uint8_t i = 0; i < TOTAL_OBJECTS; i++)
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
