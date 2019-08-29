#ifndef GLITCH_VIEW_H_
#define GLITCH_VIEW_H_

#include <Gamebuino-Meta.h>
#include "Space.h"
#include "Character.h"
#include "Cinematic.h"
#include "Object.h"

class View
{
  private:
    int16_t cameraPosX;
    int16_t cameraPosY;
    uint8_t spaceIndex;
    uint8_t charWalkClock;
    uint8_t charAnimFrame;

    void followCharacter(float charX, float charY);
    void handleCharacterAnimation(Character* character);
    void drawCharacter(float charX, float charY,Character* character, int8_t charW, uint8_t charH);
    void drawObjects(ObjectCollection * objCol);
    void setSpriteSheet(Character* character);

  public:
    Image spriteSheet;
    void draw(Space* space, Character* character, ObjectCollection* objCol);
    void setCameraPosX(int16_t x);
    void setCameraPosY(int16_t y);
    void setSpaceIndex(uint8_t index);
};
#endif
