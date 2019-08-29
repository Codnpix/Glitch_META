#ifndef GLITCH_OBJECT_H_
#define GLITCH_OBJECT_H_

#include <Gamebuino-Meta.h>
#include "constants.h"
#include "logicAssets.h"

typedef struct Object {
  uint8_t x;
  uint8_t y;
  uint8_t spaceIndex;
  uint8_t id;
  bool state;//1 or 0, 1 Object has been picked up, 0 it's on the ground
};

class ObjectCollection
{
  private:
    Object objects[TOTAL_OBJECTS];
    void initAllObjects();
    uint8_t currentSpaceIndex;
  public:
    //Object objects[TOTAL_OBJECTS];//tmp
    ObjectCollection();
    Object getObject(uint8_t index);
};
#endif
