#ifndef GLITCH_OBJECT_H_
#define GLITCH_OBJECT_H_

#include <Gamebuino-Meta.h>
#include "constants.h"
#include "logicAssets.h"

typedef struct Object {
  uint8_t x;
  uint8_t y;
  uint8_t spaceIndex;
  char id;
  uint8_t state;//1, 0 or 2, 1 Object has been picked up, 0 it's on the ground, 2 it's in container
};

class ObjectCollection
{
  private:
    Object objects[TOTAL_OBJECTS];
    void initAllObjects();
    uint8_t currentSpaceIndex;
  public:
    ObjectCollection();
    ~ObjectCollection() {};
    Object getObject(uint8_t index);
    Object checkCharacterObjectOverlap(uint8_t x, uint8_t y, uint8_t currentSpaceIndex);
    void setState(Object obj, bool state);
    void dropObject(uint8_t x, uint8_t y, uint8_t id, uint8_t spaceIndex, bool toContainer);
    void reset();
};
#endif
