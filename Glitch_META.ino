#include <Gamebuino-Meta.h>
#include "GameController.h"

GameController* gameController;

void setup() 
{
  gb.begin();
  
  gameController = new GameController();

  gameController->initGame();
  gameController->draw();
}

void loop() 
{
  gb.waitForUpdate();
  
  gameController->draw();
  gameController->updateGame();

  /*
  gb.display.setColor(RED);
  gb.display.printf("CPU : %d \n", gb.getCpuLoad());
  gb.display.printf("RAM : %d \n", gb.getFreeRam());
  */
  
}
