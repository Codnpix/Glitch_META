#ifndef GLITCH_VIEW_H_
#define GLITCH_VIEW_H_

#include <Gamebuino-Meta.h>
#include "Space.h"//tmp

class View {

  private:

    int16_t cameraPosX;
    int16_t cameraPosY;
    uint8_t spaceIndex;

    void followCharacter(float charX, float charY);

  public:
    void test();
    void draw(float charX, float charY, Space* space);
    void setCameraPosX(int16_t x);
    void setCameraPosY(int16_t y);
    void setSpaceIndex(uint8_t index);
  
};
#endif
