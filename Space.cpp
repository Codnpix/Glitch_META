#include "Space.h"

void Space::init(uint8_t index)
{
  this->setIndex(index);
  this->setLogic();
  this->setDoors();
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
  uint8_t x;
  for (uint8_t row = 0; row < LOGIC_ROWS; row++) 
  {
    for (uint8_t col = 0; col < LOGIC_COLS; col++) 
    {
      char tile = this->getLogic(row, col);
      if (tile == 'c') 
      {
        x = LOGIC_TILE_W * col;
      }
    }
  }
  return x;
}

uint8_t Space::getSpawnY() 
{
  for (uint8_t row = 0; row < LOGIC_ROWS; row++) 
  {
    for (uint8_t col = 0; col < LOGIC_COLS; col++) 
    {
      if (this->getLogic(row, col) == 'c') 
      {
        return (LOGIC_TILE_H * row) + LOGIC_TILE_H - CHARACTER_H;
      }
    }
  }
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
