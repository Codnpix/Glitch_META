#ifndef GLITCH_OBJECT_H_
#define GLITCH_OBJECT_H_

#include <Gamebuino-Meta.h>
#include "constants.h"

typedef struct Object {
  uint8_t x;
  uint8_t y;
  bool pickedUp;
  bool revealed;
};

class ObjectCollection
{
  private:
    Object objects[MAX_SPACE_OBJECTS_NB];
  public:
    void setObject(Object obj, uint8_t index);
    Object getObject(uint8_t index);
    void clear();
};
#endif
