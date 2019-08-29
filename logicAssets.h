#ifndef GLITCH_LOGIC_ASSETS_H_
#define GLITCH_LOGIC_ASSETS_H_

#include "constants.h"

typedef struct Tile
{
    uint8_t left;
    uint8_t top;
    uint8_t right;
    uint8_t bottom;
    char type;
};
//the "d" type tiles won't be used, Doors are handled with a specific struct in Door.h. They're just here as landmarks.
static const char logicMaps[NB_OF_SPACES][LOGIC_ROWS][LOGIC_COLS] =
{
  {
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ','d','d',' ',' ',' ',' ',' ','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ','s',' ',' ',' ',' ',' ',' ',' ','s','s','s','s','s','s','s',' ',' ',' ',' ','s'},
    {'s','s','s','s','s',' ',' ',' ',' ',' ','s','s','s','s','a',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ','s','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s','s','s',' ',' ',' ',' ','s'},
    {'s','s','s','s','s','s','s','s','s','s','s','s','s','s',' ',' ',' ',' ',' ','s',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ','d','d','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s','s','s','s','s','s',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ','d','d','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s','s','s',' ',' ','d','d','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s','s','s'},
    {'s',' ',' ',' ',' ','d','d','d','d',' ',' ','1',' ',' ','s','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s'}
  },
  {
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d',' ',' ',' ',' ',' ','s'},
    {'s',' ','s','s',' ',' ',' ',' ',' ','d','d','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d',' ',' ',' ',' ',' ','s'},
    {'s','2',' ',' ',' ','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d',' ',' ',' ',' ',' ','s'},
    {'s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s',' ',' ','s'},
    {'s','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','a',' ',' ',' ','s'},
    {'s','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s',' ',' ',' ','s'},
    {'s','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s',' ',' ',' ',' ',' ',' ',' ','s',' ',' ',' ',' ',' ','s'},
    {'s','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s'}
  },
  {
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d','d',' ',' ',' ',' ',' ','s'},
    {'s','s','s',' ',' ',' ','d','d',' ',' ',' ',' ','s',' ',' ',' ',' ',' ',' ','s',' ',' ',' ',' ',' ',' ',' ',' ','3','s'},
    {'s','s','s','s','s','s','s','s','s','s',' ',' ',' ',' ',' ',' ','s','s',' ',' ',' ',' ','s','s','s','s','s','s','s','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d',' ','s'},
    {'s','a',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d',' ','s'},
    {'s','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s','s','s','s','s','s',' ',' ',' ',' ','d','d',' ','s'},
    {'s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s'}
  },
  {
    {'s',' ',' ',' ','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ','s','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ','s','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ','s',' ',' ',' ','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ','s','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ','s',' ',' ',' ',' ','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ','s',' ',' ',' ','s','s','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s','d','d','d','s','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s','d','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s','d','d','d',' ',' ',' ',' ','s','s','s','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s','d','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s','s',' ',' ',' ',' ','s'},
    {'s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s'}
  },
  {
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s','s','s','s','s',' ',' ',' ',' ',' ',' ','s','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','a',' ',' ','s'},
    {'s',' ',' ','s','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s',' ',' ','s','s','s','s','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','4',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ','d','d','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ','d','d','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s','s','s',' ',' ','d','d','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ','d','d','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s','s',' ',' ','s'},
    {'s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s'}
  },
  {
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d',' ',' ',' ',' ',' ','s'},
    {'s',' ','s','s',' ',' ',' ',' ',' ',' ','s','s','s','s','s','s',' ',' ',' ',' ',' ',' ','d','d',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d',' ',' ',' ',' ',' ','s'},
    {'s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s',' ',' ',' ','s'},
    {'s','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s',' ',' ',' ',' ','s'},
    {'s','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s',' ',' ',' ',' ',' ','s'},
    {'s','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s'}
  },
  {
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s','s','s','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d','d',' ',' ',' ',' ',' ',' ','s',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d','d',' ',' ',' ',' ',' ','s',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','a','s'},
    {'s',' ',' ',' ','s','s','s','s','s',' ',' ',' ',' ',' ','d','d','d',' ',' ',' ',' ','s','s',' ','d','d',' ','s','s','s'},
    {'s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s','s','s','s','s','s',' ',' ',' ','s',' ','d','d',' ','s','s','s'},
    {'s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s'}
  },
  {
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d','d',' ','s'},
    {'s',' ',' ',' ',' ',' ','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d','d',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s','s',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ','d','d','d',' ',' ',' ',' ','s','s',' ',' ',' ','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ','d','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ','d','d','d',' ',' ',' ',' ',' ',' ','s','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ','d','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ','d','d','d',' ',' ',' ',' ',' ','s',' ',' ',' ',' ','s',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s'}
  }
};

#endif
