#include "Object.h"

void ObjectCollection::clear()
{
  for (uint8_t i = 0; i < MAX_SPACE_OBJECTS_NB; i++)
  {
    Object nullObj;
    this->objects[i] = nullObj;
  }
}

void ObjectCollection::setObject(Object obj, uint8_t index)
{
  if (index > MAX_SPACE_OBJECTS_NB) return;
  this->objects[index] = obj;
}

Object ObjectCollection::getObject(uint8_t index)
{
  return this->objects[index];
}
