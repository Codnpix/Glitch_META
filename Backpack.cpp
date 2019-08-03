#include "Backpack.h"

Backpack::Backpack()
{
  this->nbObjects = 0;
}

void Backpack::pickObject(Object obj)
{
  this->objects[this->nbObjects] = obj;
  this->nbObjects ++;
}
