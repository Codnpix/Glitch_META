#include "Space.h"

void Space::init(uint8_t index, uint8_t spawnDoorIndex)
{
  this->setIndex(index);
  this->setLogic();
  this->setDoors();
  this->setSpawn(spawnDoorIndex);
}

void Space::setSpawn(uint8_t doorIndex)
{
  Door door = spacesDoors[this->index][doorIndex];
  this->spawnX = door.x + (door.w / 2);
  this->spawnY = door.y + door.h - CHARACTER_H;
}

uint8_t Space::getIndex()
{
  return this->index;
}

void Space::setIndex(uint8_t index)
{
  this->index = index;
}

void Space::setLogic()
{
  for (uint8_t row = 0; row < LOGIC_ROWS; row++)
  {
    for (uint8_t col = 0; col < LOGIC_COLS; col++)
    {
      this->logicMap[row][col] = logicMaps[this->index][row][col];
    }
  }
}

char Space::getLogic(uint8_t row, uint8_t col)
{
  return this->logicMap[row][col];
}

uint8_t Space::getSpawnX()
{
  return this->spawnX;
}

uint8_t Space::getSpawnY()
{
  return this->spawnY;
}

void Space::setDoors()
{
  for (uint8_t i = 0; i < NB_DOORS_PER_SPACE; i++)
  {
    this->doors[i] = spacesDoors[this->index][i];
  }
}

Door Space::getDoor(uint8_t index)
{
  return this->doors[index];
}
