#include "GameController.h"

//cinematics
#define CHANGE_SPACE 11
#define WIN 12
#define LOSE 13 //bad luck !!

//cinematic sequences steps
//change space
#define FADE_OUT 0
#define LOAD_SPACE 1
#define FADE_IN 2

//object states
#define PICKED 1
#define DROPED 0

GameController::GameController()
{
  this->character = new Character();
  this->space = new Space();
  this->view = new View();
  this->cinematic = new Cinematic();
  this->backpack = new Backpack();
  this->objCol = new ObjectCollection();
  this->stkCtnr = new StackContainer();
}

void GameController::initGame()
{
  //uint8_t defaultSpawnDoorIndex = 0;
  this->cinematicMode = false;
  this->loadSpace(0, 0);
  this->bonusCount = 0;
}

void GameController::initCharacter()
{
  this->character->init(this->space->getSpawnX(), this->space->getSpawnY());
}

void GameController::initSpace(uint8_t doorIndex)
{
  this->space->init(this->currentSpace, doorIndex);
}

void GameController::loadSpace(uint8_t spaceIndex, uint8_t doorIndex)
{
    this->setSpace(spaceIndex);
    this->initSpace(doorIndex);
    this->initCharacter();
}

void GameController::changeSpace(uint8_t spaceIndex, uint8_t doorIndex)
{
  this->cinematicMode = true;
  this->nextSpaceIndex = spaceIndex;
  this->nextDoorIndex = doorIndex;
  this->cinematicSeq = CHANGE_SPACE;
  this->cinematicIndex = FADE_OUT;//initialize sequence first step
}

void GameController::handleCinematic()
{
  switch(this->cinematicSeq)
  {
    case CHANGE_SPACE:
        this->handleChangeSpace();
        break;
    case WIN:
        //win sequence
        break;
    case LOSE:
        //lose sequence
        break;
  }
}

void GameController::handleChangeSpace()
{
  switch(this->cinematicIndex)
    {
      case FADE_OUT:
        if (!this->cinematic->playFadeOut())
        {
            this->cinematicIndex++;
        }
        break;
      case LOAD_SPACE:
        this->loadSpace(this->nextSpaceIndex, this->nextDoorIndex);
        this->cinematic->playClear();
        this->cinematicIndex++;
        break;
      case FADE_IN:
        if (!this->cinematic->playFadeIn())
        {
          this->cinematicMode = false;
        }
        break;
    }
}

void GameController::pickObject(Object obj)
{
    if (isDigit(obj.id) && obj.state == 0
    && obj.spaceIndex == this->currentSpace)
    //For some reason we have to check again if the object is available in that space, otherwise it gets buggy...
    {
        //this is a quantic stack fragment, add it to the backpack
        this->backpack->addObject(obj);
        this->objCol->setState(obj, PICKED);
    }
    else //it's an apple, add bonus to bonus count
    {
        if (obj.state == 0 && obj.spaceIndex == this->currentSpace)
        {
        this->bonusCount++;
        this->objCol->setState(obj, PICKED);
        }
    }
}

void GameController::dropObject(uint8_t objId, bool toContainer)
{
    uint8_t x, y;
    if (toContainer)
    {
        x = this->stkCtnr->getNextEmptySlotX();
        y = this->stkCtnr->getNextEmptySlotY();
    }
    else
    {
        x = (uint8_t)this->character->getX();
        y = (uint8_t)(this->character->getY() + CHARACTER_H - OBJECT_H);
    }
    this->objCol->dropObject(x, y, objId, this->currentSpace, toContainer);
    this->stkCtnr->addObject(objId);
}

void GameController::handleAction()
{
    Object obj = this->objCol->checkCharacterObjectOverlap(this->character->getX(), this->character->getY(), this->currentSpace);
    if (obj.id != '0') //we got a real object available
    {
        this->pickObject(obj);
        return;
    }
    if (!this->backpack->isEmpty())
    {
        //first check if we are facing the quantic stack container
        bool facingCtnr =
        this->stkCtnr->characterIsFacingContainer(this->character->getX(), this->character->getY(), this->currentSpace);
        uint8_t droppedObjId = this->backpack->dropLastObject();
        this->dropObject(droppedObjId, facingCtnr);
    }
}

void GameController::getInputs()
{
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
  if(gb.buttons.pressed(BUTTON_B))
  {
      this->handleAction();
  }
  if(gb.buttons.pressed(BUTTON_UP))
  {
    this->enterDoor();
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
  this->view->draw(this->space, this->character, this->objCol);
  this->view->drawObjectsOverview(this->backpack, this->bonusCount);
  //this->view->_debug_drawObjCol(this->objCol);
  if(this->cinematicMode) this->handleCinematic();
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
      //this->character->reqEnterDoor(); //play animation character facing door
      door = this->space->getDoor(i);
      this->changeSpace(door.destinationSpace, door.destinationDoor);
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
