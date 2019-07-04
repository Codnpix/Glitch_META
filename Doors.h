#ifndef GLITCH_DOORS_H
#define GLITCH_DOORS_H

#include "constants.h"

typedef struct Door 
{
    uint8_t x;
    uint8_t w;
    uint8_t y;
    uint8_t h;
    uint8_t destinationSpace;
    uint8_t destinationDoor;
};

static const Door spacesDoors[NB_OF_SPACES][NB_DOORS_PER_SPACE] = 
{
  //SPACE 1, The Street
  {
    {//door bottom left on space 1
      5 * LOGIC_TILE_W,//x
      4 * LOGIC_TILE_W,//width
      SPACE_H - (5 * LOGIC_TILE_H),//y
      4 * LOGIC_TILE_H,//height
      1, //destination space
      0,//destination door
    },
    {//door middle right on space 1
      21 * LOGIC_TILE_W,//x
      2 * LOGIC_TILE_W,//w
      6 * LOGIC_TILE_H,//y
      2 * LOGIC_TILE_H,//h
      1, //destination space
      1,//destination door
    }, 
    {//door top right on space 1
      22 * LOGIC_TILE_W,//x
      LOGIC_TILE_W,//w
      0,//y
      2 * LOGIC_TILE_H,//h
      1, //destination space
      0,//destination door
    }, 
    {//door top left on space 1
      3 * LOGIC_TILE_W,//x
      2 * LOGIC_TILE_W,//w
      2 * LOGIC_TILE_H,//y
      LOGIC_TILE_H,//h
      1, //destination space
      0,//destination door
    }
  },
  //SPACE 2, The Store
  {
    {//door bottom left on space 2
      LOGIC_TILE_W,//x
      LOGIC_TILE_W,//width
      SPACE_H - (6 * LOGIC_TILE_H),//y
      5 * LOGIC_TILE_H,//height
      0, //destination space
      0,//destination door
    },
    {//door top right on space 2
      22 * LOGIC_TILE_W,//x
      2 * LOGIC_TILE_W,//w
      LOGIC_TILE_H,//y
      4 * LOGIC_TILE_H,//h
      0, //destination space
      0,//destination door
    }, 
    {//door top middle on space 2
      9 * LOGIC_TILE_W,//x
      2 * LOGIC_TILE_W,//w
      2 * LOGIC_TILE_H,//y
      2 * LOGIC_TILE_H,//h
      0, //destination space
      0,//destination door
    }, 
    {//door top left on space 2
      2 * LOGIC_TILE_W,//x
      2 * LOGIC_TILE_W,//w
      LOGIC_TILE_H,//y
      2 * LOGIC_TILE_H,//h
      0, //destination space
      0,//destination door
    }
  }
};
#endif
