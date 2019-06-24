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
  //gb.display.setColor(RED);
  //gb.display.printf("CPU : %d \n", gb.getCpuLoad());
  //gb.display.printf("RAM : %d \n", gb.getFreeRam());
  
  /*
   * generate pattern curve : 
   * 
   
   if(gb.buttons.pressed(BUTTON_B)) {
      for(int8_t x=-10; x<10;x++) {
      float y = -(x * x) / 4.0;
      SerialUSB.println(y);
    }
    
  }*/
  
  
}
