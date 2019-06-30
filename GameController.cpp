#include "GameController.h"
#include "constants.h"

#define STREET 0
#define STORE 1

GameController::GameController(Character* character, Space* space, View* view) 
{
  this->character = character;
  this->space = space;
  this->view = view;
}

void GameController::initGame() 
{
  this->loadSpace(STREET);
}

void GameController::initCharacter() 
{
  this->character->init(this->space->getSpawnX(), this->space->getSpawnY());
}

void GameController::initSpace()
{
  this->space->init(this->currentSpace);
}

void GameController::loadSpace(uint8_t spaceIndex)
{
  this->setSpace(spaceIndex);
  this->initSpace();
  this->initCharacter();
}

void GameController::getInputs() 
{
  
//to come : conditions gameon, dashboard, menu, glitch, etc..

  if(gb.buttons.repeat(BUTTON_RIGHT, 1))
  {
    this->character->reqWalkRight();
  }
  if(gb.buttons.repeat(BUTTON_LEFT, 1))
  {
    this->character->reqWalkLeft();
  }
  if(gb.buttons.pressed(BUTTON_A)) 
  {
    this->character->reqJump();
  }
  if(gb.buttons.pressed(BUTTON_UP)) 
  {
    this->enterDoor();
    //this->character->reqEnterDoor();
  }
  if(gb.buttons.repeat(BUTTON_DOWN, 1)) 
  {
    //this->character->reqDown();
  }

  if(gb.buttons.released(BUTTON_UP) 
  || gb.buttons.released(BUTTON_DOWN)) 
  {
    //this->character->reqStopY();
  }
  
  if(gb.buttons.released(BUTTON_LEFT) 
  || gb.buttons.released(BUTTON_RIGHT)) 
  {
    this->character->reqStand();
  }
}

void GameController::updateGame() 
{
  this->getInputs();
  this->character->update(this->space);
}


void GameController::draw() 
{
  uint8_t spaceIndex;
  float charX = this->character->getX();
  float charY = this->character->getY();
  spaceIndex = this->space->getIndex();
  this->view->setSpaceIndex(spaceIndex);
  this->view->draw(this->space, this->character);
}

uint8_t GameController::getCurrentSpace() 
{
  return this->currentSpace;
}

void GameController::setSpace(uint8_t spaceIndex)
{
  this->currentSpace = spaceIndex;
}

void GameController::enterDoor()
{
  Door door;
  for (uint8_t i = 0; i < NB_DOORS_PER_SPACE; i++)
  {
    if (this->isCharacterFacingDoor(this->space->getDoor(i)))
    {
      door = this->space->getDoor(i);
      this->loadSpace(door.destinationSpace);
      break;
      }
  }
}

bool GameController::isCharacterFacingDoor(Door door)
{
  uint8_t charLeft, charRight, charTop, charBottom;
  charLeft = (uint8_t)this->character->getX();
  charRight = charLeft + CHARACTER_W;
  charTop = (uint8_t)this->character->getY();
  charBottom = charTop + CHARACTER_H;

  if (charLeft <= door.x + door.w
      && charRight >= door.x
      && charTop <= door.y + door.h
      && charBottom >= door.y) 
      {
        return true;
      } else return false;
}
