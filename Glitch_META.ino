#include <Gamebuino-Meta.h>

#include "GameController.h"
#include "Character.h"
#include "Space.h"
#include "View.h"

GameController* gameController;
Character* character;
Space* space;
View* view;

void setup() {
  gb.begin();
  character = new Character();
  space = new Space();
  view = new View();
  gameController = new GameController(character, space, view);

  gameController->initGame();
  gameController->draw();
}

void loop() {
  while(!gb.update());
  
  gameController->draw();
  gameController->updateGame();
  gb.display.println(gb.getCpuLoad());
  //gb.display.println(gb.getFreeRam());
  
  /*
   * generate pattern hyperbole : 
   * 
   if(gb.buttons.pressed(BUTTON_B)) {
      for(int8_t x=-11; x<12;x++) {
      int8_t y = -(x*x);
      SerialUSB.println(y);
    }
  }
  
  */
}
