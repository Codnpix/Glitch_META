#ifndef GLITCH_SPACE_H_
#define GLITCH_SPACE_H_

#include <Gamebuino-Meta.h>
#include "logicAssets.h"
#include "constants.h"

class Space {
  private:
    uint8_t index;
    
    char logicMap[16][30];
    
  public:
    uint8_t getIndex();
    void setIndex(uint8_t index);
    char getLogic(uint8_t row, uint8_t col);
    void setLogic();
    uint8_t getSpawnX();
    uint8_t getSpawnY();
};
#endif
