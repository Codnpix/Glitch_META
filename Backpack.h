#ifndef GLITCH_BACKPACK_H_
#define GLITCH_BACKPACK_H_

#include "Object.h"

class Backpack
{
  private:
    Object objects[TOTAL_OBJECTS];
    uint8_t objectsCount;
  public:
    Backpack();
    void addObject(Object obj);
    uint8_t getObjectCount();
    Object getObject(uint8_t i);
};
#endif
