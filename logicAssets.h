#ifndef GLITCH_LOGIC_ASSETS_H_
#define GLITCH_LOGIC_ASSETS_H_

#include "constants.h"

typedef struct Tile {
    uint8_t left;
    uint8_t top;
    uint8_t right;
    uint8_t bottom;
    char type;
};

static const char logicMaps[NB_OF_SPACES][16][30] = {
  {
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','d',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s','s','s','s','s','s',' ',' ',' ',' ','s'},
    {'s','s','s','s','s',' ',' ',' ',' ',' ',' ','s','s','s',' ',' ',' ',' ','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ','s','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s',' ',' ','d','d',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ','s','s','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s',' ',' ','d','d',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s','e','s','s','s','s',' ',' ',' ',' ','s'},
    {'s','s','s','s','s','s','s','s','s','s','s','s','s','s',' ',' ',' ',' ','s',' ','e',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ','d','d','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s','s','s','s','s','s',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ','d','d','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','c','s'},
    {'s','s','s',' ',' ','d','d','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s','s','s'},
    {'s','s','s',' ',' ','d','d','d','d',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s','s','s','s'},
    {'s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s'}
  }
};

#endif
