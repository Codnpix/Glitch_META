#include "Character.h"

//Y move states
#define CLIMBING 0
#define JUMPING 1
//grab state
#define CAN_GRAB_LEFT 0
#define CAN_GRAB_RIGHT 1

#define NONE 2

void Character::init(uint8_t spawnX, uint8_t spawnY) 
{
  this->reqXMarker = 'n';
  this->setPosition(spawnX, spawnY);
  this->moveStateY = NONE;
  this->direction = 'r';
  this->animationState = "STAND";
}

void Character::reqWalkRight() 
{
  this->reqXMarker = 'r';
  this->direction = 'r';
}

void Character::reqWalkLeft() 
{
  this->reqXMarker = 'l';
  this->direction = 'l';
}

void Character::reqStand() 
{
  this->reqXMarker = 'n';
}

void Character::reqJump() 
{
  this->reqYMarker = this->moveStateY == JUMPING && this->checkGrab() ? 'c' : 'j';
}

void Character::reqEnterDoor()
{
  //this will be just an animation state change, character will show his back, facing the door
}

void Character::applyMove() 
{
  this->x += this->vx;
  this->y += this->vy;
  if (this->isOnGround) 
  {
    this->y = yGround - CHARACTER_H;//correction, set the character right on the floor e.g. if he stops one pixel too low
  }
}

void Character::updateAnimationState() 
{
  if (this->vx != 0 && this->isOnGround)
  {
    this->animationState = "WALK";
  } 
  else if (this->vx == 0 && this->isOnGround)
  {
    this->animationState = "STAND";
  }
  else if (this->moveStateY == JUMPING)
  {
    this->animationState = "JUMP";
  } 
  else if (this->moveStateY == CLIMBING) 
  {
    this->animationState = "CLIMB";
  } 
  else if ((this->moveStateY == JUMPING || this->moveStateY == NONE)&& this->vy > 0)
  {
    this->animationState = "FALL";
  }
}

void Character::update(Space* space) 
{
  //collisions
  this->setNTiles(space);//update collision testing space around sprite
  this->checkCollisions(space);
  //moves
  this->handleXReqs();
  this->handleGround();//update the ground constraint for Y moves
  this->handleYReqs(this->reqYMarker);
  this->vy = GRAVITY + this->G_resistance;//apply gravity resistance calculation on  vertical speed vy
  this->applyMove();//apply speed to position
  //animation
  this->updateAnimationState();

  //debugging
  gb.display.setColor(RED);
  if (this->isOnGround) gb.display.println("GROUND");
  //if (this->canGrabLeft) gb.display.println("CAN GRAB LEFT");
  //if (this->canGrabRight) gb.display.println("CAN GRAB RIGHT");
  //if (this->isClimbing) gb.display.println("CLIMBING");
  //if (this->collidesLeft || this->collidesRight) gb.display.println("COLLIDES");
  //gb.display.printf("Y TO CLIMB : %d \n",this->yToClimb);
  //gb.display.printf("Y MARKER : %c \n",this->reqYMarker);
  //gb.display.printf("X MARKER : %c \n",this->reqXMarker);
  gb.display.printf("STATE : %s",this->animationState);
}

void Character::handleXReqs() 
{
  if (this->reqXMarker == 'r') 
  {
    if (!this->collidesRight) this->vx = 1;
    else this->vx = 0;
  } 
  else if (this->reqXMarker == 'l') 
  {
    if (!this->collidesLeft) this->vx = -1;
    else this->vx = 0;
  } 
  else if (this->reqXMarker == 'n') this->vx = 0;
}

void Character::handleGround() 
{
  if(this->isOnGround && this->reqYMarker == 'n') 
  {
    this->G_resistance = - GRAVITY;
  }
  if(this->isOnGround && this->vy > 0) 
  {
    this->moveStateY = NONE;
    this->reqYMarker = 'n';
    this->jumpFrame = 0;
    this->G_resistance = - GRAVITY;
  }
}

void Character::handleYReqs(char req) 
{
  //jumping
  if (req == 'j') 
  {
    //this->isJumping = true;
    this->moveStateY = JUMPING;
    this->playJump();
  } 
  else if(req == 'n' && !this->isOnGround) 
  {
    this->G_resistance = 0;
  }
  //climbing
  if (req == 'c')
  {
    this->moveStateY = CLIMBING;
    this->playClimb();
  }
}

void Character::setNTiles(Space* space)
{//set the 6 tiles array around the sprite
  //parse logic map, check collisions :
  uint8_t colNum = floor((this->x) / LOGIC_TILE_W);
  uint8_t rowNum = floor((this->y) / LOGIC_TILE_H);
  int16_t tileX, tileY;
  uint8_t tileW, tileH;
  tileH = LOGIC_TILE_H;
  tileW = LOGIC_TILE_W;
  
  //Tile nTiles[2 * 3];//the 6 tiles around the sprite
  
  uint8_t i = 0;
  
  for (uint8_t row = rowNum; row < rowNum + 3; row++) 
  {
    for (uint8_t col = colNum; col < colNum + 2; col++) 
    {
      tileX = LOGIC_TILE_W * col;
      tileY = LOGIC_TILE_H * row;
      
      char tileType = space->getLogic(row, col);
      
      Tile tile;
      tile.left = tileX;
      tile.right = tileX + tileW;
      tile.top = tileY;
      tile.bottom = tileY + tileH;
      tile.type = tileType;
      this->nTiles[i] = tile;
      i++;
    }
  }
}

void Character::checkCollisions(Space* space) 
{
  //ground collision test
  if ((this->collides(this->nTiles[4]) && this->nTiles[4].type == 's' && (this->x <= this->nTiles[4].right - 2)) 
  || (this->collides(this->nTiles[5]) && this->nTiles[5].type == 's' && (this->x+CHARACTER_W >= this->nTiles[5].left + 2))) 
  {//right+2 and left-2 is because we have to bite the ground on 2px min to be onGround
    this->isOnGround = true;
    this->yGround = this->nTiles[4].top;
  }
  else this->isOnGround = false;
  
  //right or left collision test
 if ((this->collides(this->nTiles[1]) && this->nTiles[1].type == 's')
  || (this->collides(this->nTiles[3]) && this->nTiles[3].type == 's')) 
  {
    this->collidesRight = true;
  } 
  else if ((this->collides(this->nTiles[1]) && this->nTiles[1].type != 's')
  && (this->collides(this->nTiles[3]) && this->nTiles[3].type != 's')) 
  {
    this->collidesRight = false;
  }
  
  if ((this->collides(this->nTiles[0]) && this->nTiles[0].type == 's')
  || (this->collides(this->nTiles[2]) && this->nTiles[2].type == 's')) 
  {
    this->collidesLeft = true;
  } 
  else if ((this->collides(this->nTiles[0]) && this->nTiles[0].type != 's')
  && (this->collides(this->nTiles[2]) && this->nTiles[2].type != 's')) 
  {
    this->collidesLeft = false;
  }
  //unlock collisions for not getting stuck if character wants to get away from collision
  if (this->collidesLeft && this->vx > 0) this->collidesLeft = false;
  if (this->collidesRight && this->vx < 0) this->collidesRight = false;
}

bool Character::checkGrab()
{
  if (this->collidesLeft
  && this->nTiles[0].type == ' '
  && this->nTiles[4].type == ' '//platform is at least one step above ground
  && this->direction == 'l'
  && this->reqXMarker == 'l') 
  {
    //this->canGrabLeft = true;
    this->grabState = CAN_GRAB_LEFT;
    this->yToClimb = this->nTiles[2].top;
    return true;
  }
  else if 
  (this->collidesRight
  && this->nTiles[1].type == ' '
  && this->nTiles[5].type == ' '
  && this->direction == 'r'
  && this->reqXMarker == 'r') 
  {
    this->grabState = CAN_GRAB_RIGHT;
    this->yToClimb = this->nTiles[3].top;
    return true;
  }
  else return false;
}

bool Character::collides(Tile tile) 
{  
  uint8_t charLeft, charRight, charTop, charBottom;
  charLeft = (uint8_t)this->x;
  charRight = (uint8_t)(this->x + CHARACTER_W);
  charTop = (uint8_t)this->y;
  charBottom = (uint8_t)this->y + CHARACTER_H;

  if (charLeft <= tile.right
      && charRight >= tile.left
      && charTop <= tile.bottom
      && charBottom >= tile.top) 
      {
        return true;
      } else return false;
}

void Character::playJump() 
{
  if (this->isOnGround)
  {
    this->jumpFrame = 0;
    this->isOnGround = false;
  }
  this->nextFrame = false;
  this->playPatternJump(this->jumpFrame);
  if(!this->nextFrame) 
  {
    this->jumpFrame++;
    this->nextFrame = true;
  }
}

void Character::playPatternJump(uint8_t frame) 
{
  if (frame < JUMP_PATTERN_LENGTH) 
  {
    this->G_resistance = JUMP_VY_PATTERN[frame] - GRAVITY;
  }
}

void Character::playClimb() 
{
  if(this->reqXMarker == 'n') 
  {
    this->G_resistance = 0;
    this->reqYMarker = 'n';
    this->climbInitialized = false;
    this->climbplayed = false;
    this->moveStateY = NONE;
    return;
  }
  if (!this->climbplayed) 
  {
    this->climbFrame = 0;
    this->climbplayed = true;
  }
  this->nextFrame = false;
  this->playPatternClimb(this->climbFrame);
  if (!this->nextFrame) 
  {
    this->climbFrame++;
    this->nextFrame = true;
  }
}

void Character::playPatternClimb(uint8_t frame) 
{
  if (!this->climbInitialized) 
  {
    this->y = this->yToClimb;//? ajust...
    this->climbInitialized = true;
  }
  if (this->climbInitialized) 
  {
    this->G_resistance = -4;//tmp ?
    if(this->y <= this->yToClimb - CHARACTER_H)
    {
      this->moveStateY = NONE;
      this->reqYMarker = 'n';  
    }
  }
}

float Character::getX() 
{
  return this->x;
}

float Character::getY() 
{
  return this->y;
}

void Character::setPosition(float x, float y) 
{
  this->x = x;
  this->y = y;
}

float Character::getVx() 
{
  return this->vx;
}

float Character::getVy() 
{
  return this->vy;
}

char Character::getDirection() 
{
  return this->direction;
}

char* Character::getAnimationState()
{
  return this->animationState;
}
