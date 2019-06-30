#ifndef GLITCH_GAME_CONTROLLER_H_
#define GLITCH_GAME_CONTROLLER_H_

#include <Gamebuino-Meta.h>

#include "Character.h"
#include "Space.h"
#include "View.h"

class GameController 
{
  
  private:
    Character* character;
    Space* space;
    View* view;
    uint8_t currentSpace;

    void initSpace();
    void initCharacter();
    void getInputs();
    void enterDoor();
    bool isCharacterFacingDoor(Door door);
    void setSpace(uint8_t spaceIndex);
    void loadSpace(uint8_t spaceIndex);

  public:
    GameController(Character* character, Space* space, View* view);
    void initGame();
    void updateGame();
    void draw();
    uint8_t getCurrentSpace();
};
#endif
