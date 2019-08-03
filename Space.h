#ifndef GLITCH_SPACE_H_
#define GLITCH_SPACE_H_

#include <Gamebuino-Meta.h>
#include "logicAssets.h"
#include "Doors.h"
#include "Object.h"

class Space 
{
  private:
    uint8_t index;
    char logicMap[16][30];
    Door doors[4];
    uint8_t spawnX;
    uint8_t spawnY;

    ObjectCollection * objCol;

    void setIndex(uint8_t index);
    void setLogic();
    void setDoors();
    void setObjects();
    
  public:
    Space();
    void init(uint8_t index, uint8_t spawnDoorIndex);
    uint8_t getIndex();
    char getLogic(uint8_t row, uint8_t col);
    Door getDoor(uint8_t index);
    uint8_t getSpawnX();
    uint8_t getSpawnY();
    void setSpawn(uint8_t doorIndex);
    ObjectCollection * getObjectCollection();
};
#endif
