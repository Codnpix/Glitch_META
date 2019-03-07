#include "GameController.h"
#include "constants.h"

GameController::GameController(Character* character, Space* space, View* view) {
  this->character = character;
  this->space = space;
  this->view = view;
}

void GameController::initGame() {
  this->initSpace();
  this->initCharacter();
}

void GameController::initCharacter() {
  this->character->init(this->space->getSpawnX(), this->space->getSpawnY());
}

void GameController::initSpace()  {
  this->space->setIndex(0);//tmp
  this->space->setLogic();
}

void GameController::getInputs() {
//to come : conditions gameon, dashboard, menu, glitch, etc..

  //this->character->reqFall();

  if(gb.buttons.repeat(BUTTON_RIGHT, 1)){
    this->character->reqWalkRight();
  }
  if(gb.buttons.repeat(BUTTON_LEFT, 1)){
    this->character->reqWalkLeft();
  }
  if(gb.buttons.pressed(BUTTON_A)) {
    this->character->reqJump();
  }
  /*if(gb.buttons.repeat(BUTTON_DOWN, 1)) {
    this->character->reqFall();
  } à voir plus tard... peut-être pas utiliser reqFall() mais un truc plus adapté genre reqGetDown() pour descendre une échelle par ex.. pas forcément lié à la gravité*/
  if(gb.buttons.released(BUTTON_LEFT) || gb.buttons.released(BUTTON_RIGHT)) {
    this->character->reqStand();
  }

  
}

void GameController::updateGame() {

  this->getInputs();
  this->character->update(this->space);
  
}


void GameController::draw() {
  uint8_t spaceIndex;

  float charX = this->character->getX();
  float charY = this->character->getY();
  
  spaceIndex = this->space->getIndex();
  this->view->setSpaceIndex(spaceIndex);
  
  this->view->draw(this->space, this->character);
  // faire plutôt: this->view->draw(this->space, this->character);
  // et dans view : View::draw(Space* space, Character* character);
}
