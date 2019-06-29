#ifndef GLITCH_SPACE_H_
#define GLITCH_SPACE_H_

#include <Gamebuino-Meta.h>
#include "logicAssets.h"
#include "constants.h"
#include "Doors.h"

class Space 
{
  private:
    uint8_t index;
    
    char logicMap[16][30];
    Door doors[4];
    
  public:
    uint8_t getIndex();
    void setIndex(uint8_t index);
    char getLogic(uint8_t row, uint8_t col);
    void setLogic();
    void setDoors();
    Door getDoors(uint8_t index);
    uint8_t getSpawnX();
    uint8_t getSpawnY();
};
#endif
