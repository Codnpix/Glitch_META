#ifndef GLITCH_BACKPACK_H_
#define GLITCH_BACKPACK_H_

#include "Object.h"

class Backpack
{
  private:
    Object objects[3];
    uint8_t nbObjects;
  public:
    Backpack();
    void pickObject(Object obj);
};
#endif
