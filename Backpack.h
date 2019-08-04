#ifndef GLITCH_BACKPACK_H_
#define GLITCH_BACKPACK_H_

#include "Object.h"

class Backpack
{
  private:
    Object objects[TOTAL_OBJECTS];
    uint8_t nbObjects;
  public:
    Backpack();
    void addObject(Object obj);
};
#endif
