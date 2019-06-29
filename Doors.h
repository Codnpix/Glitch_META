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
};

static const Door spacesDoors[NB_OF_SPACES][NB_DOORS_PER_SPACE] = 
{
  {
    {//door bottom left on space 1
      5 * LOGIC_TILE_W,//x
      4 * LOGIC_TILE_W,//width
      SPACE_H - (5 * LOGIC_TILE_H),//y
      4 * LOGIC_TILE_H,//height
      1 //destination space
    },
    {//door middle right on space 1
      21 * LOGIC_TILE_W,//x
      2 * LOGIC_TILE_W,//w
      6 * LOGIC_TILE_H,//y
      2 * LOGIC_TILE_H,//h
      2 //destination space
    }, 
    {//door top right on space 1
      22 * LOGIC_TILE_W,//x
      LOGIC_TILE_W,//w
      0,//y
      2 * LOGIC_TILE_H,//h
      3 //destination space
    }, 
    {//door top left on space 1
      3 * LOGIC_TILE_W,//x
      2 * LOGIC_TILE_W,//w
      2 * LOGIC_TILE_H,//y
      LOGIC_TILE_H,//h
      4 //destination space
    }
  }
};
#endif
