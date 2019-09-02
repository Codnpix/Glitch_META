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
// a b c e f ... o, p , q are for apples
//s for everything solid and used for collision detection
//1 2 3 4 are the 4 quantic stack fragments.
static const char logicMaps[NB_OF_SPACES][LOGIC_ROWS][LOGIC_COLS] =
{
  {
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ','d','d',' ',' ',' ',' ',' ','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ','s',' ','b',' ',' ',' ',' ',' ','s','s','s','s','s','s','s',' ',' ',' ',' ','s'},
    {'s','s','s','s','s',' ',' ',' ',' ',' ','s','s','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ','c',' ',' ',' ',' ',' ',' ',' ',' ','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ','s','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s','s','s',' ',' ',' ',' ','s'},
    {'s','s','s','s','s','s','s','s','s','s','s','s','s','s',' ',' ',' ',' ',' ','s',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ','d','d','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s','s','s','s','s','s',' ',' ',' ',' ','s'},
    {'s','a',' ',' ',' ','d','d','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s','s','s',' ',' ','d','d','d','d',' ',' ',' ',' ',' ',' ','1',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s','s','s'},
    {'s',' ',' ',' ',' ','d','d','d','d',' ',' ',' ',' ',' ','s','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s'}
  },
  {
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d',' ',' ',' ',' ',' ','s'},
    {'s',' ','s','s',' ',' ',' ',' ',' ','d','d','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d','e',' ',' ',' ',' ','s'},
    {'s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s',' ',' ','s'},
    {'s','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s',' ',' ',' ','s'},
    {'s','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s',' ',' ',' ',' ',' ',' ',' ','s',' ',' ',' ',' ',' ','s'},
    {'s','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s'}
  },
  {
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s','g',' ',' ',' ',' ','d','d',' ',' ',' ',' ','q',' ',' ',' ',' ',' ',' ',' ',' ','d','d','d',' ',' ',' ',' ',' ','s'},
    {'s','s','s',' ',' ',' ','d','d',' ',' ',' ',' ','s',' ',' ',' ',' ','h',' ','s',' ',' ',' ',' ',' ',' ',' ','2',' ','s'},
    {'s','s','s','s','s','s','s','s','s','s',' ',' ',' ',' ',' ',' ','s','s',' ',' ',' ',' ','s','s','s','s','s','s','s','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ','&','&','&',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ','&','&','&',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d',' ','s'},
    {'s',' ','f',' ',' ',' ',' ',' ',' ',' ','&','&','&',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d',' ','s'},
    {'s','s','s',' ',' ',' ',' ',' ',' ',' ','&','&','&',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ','&','&','&',' ',' ','s','s','s','s','s','s','s',' ',' ',' ',' ','d','d',' ','s'},
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
    {'s','d','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s','s',' ',' ','i',' ','s'},
    {'s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s'}
  },
  {
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s','s','s','s','s',' ',' ',' ',' ',' ',' ','s','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','j',' ',' ',' ','s'},
    {'s',' ',' ','s','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s',' ',' ','s','s','s','s','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ','s',' ',' ',' ',' ',' ',' ',' ',' ',' ','k',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ','d','d','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ','d','d','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s','s','s',' ',' ','d','d','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','3',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ','d','d','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s','s',' ',' ','s'},
    {'s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s'}
  },
  {
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','l',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d',' ',' ',' ',' ',' ','s'},
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
    {'s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d','d',' ',' ',' ',' ',' ','s',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ','n',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','m','s'},
    {'s',' ',' ',' ','s','s','s','s','s',' ',' ',' ',' ',' ','d','d','d',' ',' ',' ',' ','s','s',' ','d','d',' ','s','s','s'},
    {'s','s',' ',' ',' ',' ',' ',' ',' ',' ','4',' ','s','s','s','s','s','s','s',' ',' ',' ','s',' ','d','d',' ',' ',' ','s'},
    {'s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s'}
  },
  {
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d','d',' ','s'},
    {'s',' ',' ',' ',' ',' ','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d','d','d',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','p',' ','s','s','s',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','o',' ',' ',' ',' ',' ',' ','s','s',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ','d','d','d',' ',' ',' ',' ','s','s',' ',' ',' ','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ','d','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ','d','d','d',' ',' ',' ',' ',' ',' ','s','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ','d','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ','d','d','d',' ',' ',' ',' ',' ','s',' ',' ',' ',' ','s',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s'}
  }
};

#endif
