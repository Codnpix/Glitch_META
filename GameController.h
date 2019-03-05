#ifndef GLITCH_GAME_CONTROLLER_H_
#define GLITCH_GAME_CONTROLLER_H_

#include <Gamebuino-Meta.h>

#include "Character.h"
#include "Space.h"
#include "View.h"

class GameController {
  
  private:
    Character* character;
    Space* space;
    View* view;

    void initSpace();
    void initCharacter();
    void getInputs();

  public:
    GameController(Character* character, Space* space, View* view);
    void initGame();
    void updateGame();
    void draw();
};
#endif
