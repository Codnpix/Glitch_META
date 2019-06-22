#include "Character.h"

void Character::init(uint8_t spawnX, uint8_t spawnY) {
  this->reqXMarker = 'n';
  this->setPosition(spawnX, spawnY);
  this->isJumping = false;
  this->isClimbing = false;
  this->direction = 'r';
}

void Character::reqWalkRight() {
  this->reqXMarker = 'r';
  this->direction = 'r';
}

void Character::reqWalkLeft() {
  this->reqXMarker = 'l';
  this->direction = 'l';
}

void Character::reqStand() {
  this->reqXMarker = 'n';
}

void Character::reqStopY() {
  if(this->reqYMarker == 'u' || this->reqYMarker == 'd') this->reqYMarker = 's';
}

void Character::reqJump() {
  this->reqYMarker = 'j';
}

void Character::applyMove() {
  
  this->x += this->vx;
  this->y += this->vy;
  
  if (this->isOnGround) {
    this->y = yGround - CHARACTER_H;//correction, set the character right on the floor e.g. if he stops one pixel too low
  }
}

void Character::update(Space* space) {

  this->checkCollisions(space);

  this->handleXReqs();

  //update the ground constraint for Y moves :
  this->handleGround();

  //handle Y moves requests if character is on a ladder
  //if (this->isOnLadder) this->handleLadderYReqs(this->reqYMarker);
  
  //handle Y moves requests in normal conditions
  this->handleYReqs(this->reqYMarker);
  
  this->vy = GRAVITY + this->G_resistance;

  this->applyMove();

  //debugging
  gb.display.setColor(RED);
  //if (this->isOnGround) gb.display.println("GROUND");
  //if (this->canGrabLeft) gb.display.println("CAN GRAB LEFT");
  
  //if (this->canGrabRight) gb.display.println("CAN GRAB RIGHT");
  //if (this->isClimbing) gb.display.println("CLIMBING");
  //if (this->collidesLeft || this->collidesRight) gb.display.println("COLLIDES");
  //gb.display.printf("Y TO CLIMB : %d \n",this->yToClimb);
  //gb.display.printf("Y MARKER : %c \n",this->reqYMarker);
  //gb.display.printf("X MARKER : %c \n",this->reqXMarker);
  //gb.display.printf("ON LADDER : %d \n", this->isOnLadder);
  //gb.display.printf("CAN LADDER UP : %d \n", this->canLadderUp);
}

void Character::handleXReqs() {
  if (this->reqXMarker == 'r') {
    
    if (!this->collidesRight) this->vx = 1;
    else {
      this->vx = 0;
    }
    
  } else if (this->reqXMarker == 'l') {
    
    if (!this->collidesLeft) this->vx = -1;
    else {
      this->vx = 0;
    }
    
  } else if (this->reqXMarker == 'n') this->vx = 0;
}

void Character::handleGround() {
  
  if(this->isOnGround && this->reqYMarker == 'n') {
    this->G_resistance = - GRAVITY;
  }
  
  if(this->isOnGround && this->vy > 0) {
    
    this->isJumping = false;
    this->reqYMarker = 'n';
    this->jumpFrame = 0;
    this->G_resistance = - GRAVITY;
  }
}

void Character::handleYReqs(char req) {
  //jumping
  if (req == 'j') {
    
    this->isJumping = true;
    this->trigJump();
    
  } else if(req == 'n' && !this->isOnGround) {
    
    this->G_resistance = 0;
  }

  //climbing
  if (req == 'c') {
    
    this->isJumping == false;
    this->isClimbing == true;
    this->trigClimb();
  }
}

void Character::checkCollisions(Space* space) {
  //parse logic map, check collisions :

  uint8_t colNum = floor((this->x) / LOGIC_TILE_W);
  uint8_t rowNum = floor((this->y) / LOGIC_TILE_H);
  int16_t tileX, tileY;
  uint8_t tileW, tileH;
  tileH = LOGIC_TILE_H;
  tileW = LOGIC_TILE_W;
  
  Tile nTiles[2 * 3];//the 6 tiles around the character
  
  uint8_t i;
  i = 0;
  
  for (uint8_t row = rowNum; row < rowNum + 3; row++) {
    for (uint8_t col = colNum; col < colNum + 2; col ++) {
      
      tileX = LOGIC_TILE_W * col;
      tileY = LOGIC_TILE_H * row;
      
      char tileType = space->getLogic(row, col);
      
      Tile tile;
      tile.left = tileX;
      tile.right = tileX + tileW;
      tile.top = tileY;
      tile.bottom = tileY + tileH;
      tile.type = tileType;
      nTiles[i] = tile;
      
      i++;

    }
  }
  //ground collision test
  if ((this->collides(nTiles[4]) && nTiles[4].type == 's' && (this->x <= nTiles[4].right - 3)) 
  || (this->collides(nTiles[5]) && nTiles[5].type == 's' && (this->x+CHARACTER_W >= nTiles[5].left + 3))) {//you have to bite the ground on 3px min to be onGround
    
    this->isOnGround = true;
    this->yGround = nTiles[4].top;
    
  } else if ((this->collides(nTiles[4]) && nTiles[4].type != 's') 
  || (this->collides(nTiles[5]) && nTiles[5].type != 's')) {
    
    this->isOnGround = false;
    
  }
  
  //right or left collision test
 if ((this->collides(nTiles[1]) && nTiles[1].type == 's')
  || (this->collides(nTiles[3]) && nTiles[3].type == 's')) {
    
    this->collidesRight = true;
    
  } else if ((this->collides(nTiles[1]) && nTiles[1].type != 's')
  && (this->collides(nTiles[3]) && nTiles[3].type != 's')) {
    
    this->collidesRight = false;
    
  }
  
  if ((this->collides(nTiles[0]) && nTiles[0].type == 's')
  || (this->collides(nTiles[2]) && nTiles[2].type == 's')) {
    
    this->collidesLeft = true;
    
  } else if ((this->collides(nTiles[0]) && nTiles[0].type != 's')
  && (this->collides(nTiles[2]) && nTiles[2].type != 's')) {
    
    this->collidesLeft = false;
    
  }

  //tests if character can grab ground above him
  if (this->collidesLeft && nTiles[0].type == ' ' && this->direction == 'l') {
    
    this->canGrabLeft = true;//no need ?
    
    if (this->reqXMarker == 'l') {
      
      this->reqYMarker = 'c';
      this->yToClimb = nTiles[2].top;
      
    }
    
  } else this->canGrabLeft = false;
  
  if (this->collidesRight && nTiles[1].type == ' ' && this->direction == 'r') {
    
    this->canGrabRight = true;//no need ?
    
    if (this->reqXMarker == 'r') {
      
      this->reqYMarker = 'c';
      this->yToClimb = nTiles[3].top;
      
    }
    
  } else this->canGrabRight = false;

  //unlock collisions for not getting stuck if character wants to get away from collision
  if (this->collidesLeft && this->vx > 0) this->collidesLeft = false;
  if (this->collidesRight && this->vx < 0) this->collidesRight = false;

}

bool Character::collides(Tile aTile) {
  
  uint8_t charLeft, charRight, charTop, charBottom;
  
  charLeft = (uint8_t)this->x;
  charRight = (uint8_t)(this->x + CHARACTER_W);
  charTop = (uint8_t)this->y;
  charBottom = (uint8_t)this->y + CHARACTER_H;

  if (charLeft <= aTile.right
      && charRight >= aTile.left
      && charTop <= aTile.bottom
      && charBottom >= aTile.top) {
        
        return true;
        
      } else return false;
      
}

bool Character::isVerticalAlignedWith(Tile aTile) {
  
  uint8_t charLeft, charRight;
  
  charLeft = (uint8_t)this->x;
  charRight = (uint8_t)(this->x + CHARACTER_W);

  if (charRight <= aTile.right 
  && charLeft >= aTile.left) {
    
    return true;
    
  } else return false;
}

void Character::trigJump() {
  
  if (isOnGround) {
    this->jumpFrame = 0;
    this->isOnGround = false;
  }
  
  this->nextFrame = false;
  
  this->playPatternJump(this->jumpFrame);
  
  if(!this->nextFrame) {
    this->jumpFrame++;
    this->nextFrame = true;
  }
  
}

void Character::playPatternJump(uint8_t frame) {
  if (frame < 9) {
    this->G_resistance = JUMP_VY_PATTERN[frame] - GRAVITY;
  }
}

void Character::trigClimb() {
  
  if(this->reqXMarker == 'n') {
    
    this->G_resistance = 0;
    this->reqYMarker = 'n';
    this->climbInitialized = false;
    this->climbTrigged = false;
    this->isClimbing = false;
    return;
  }
  
  if (!this->climbTrigged) {
    
    this->frame = 0;
    this->climbTrigged = true;
  }

  this->nextFrame = false;

  this->playPatternClimb(this->frame);

  if (!this->nextFrame) {
    
    this->frame ++;
    this->nextFrame = true;
  }
  //climb need to stop trigging when reqXmarker == 'n';
}

void Character::playPatternClimb(uint8_t frame) {
  
  if (!this->climbInitialized) {
    
    this->y = this->yToClimb - 4;//? ajuster...
    this->climbInitialized = true;
  }

  if (this->climbInitialized) {
    
    if(this->y + CHARACTER_H >= this->yToClimb) {
      
      if (frame>=9) frame = 8;//prevent pattern array out of bound iteration
      
      this->G_resistance = CLIMB_VY_PATTERN[frame] - GRAVITY;
      
    } else {
      
      this->G_resistance = 0;
      this->reqYMarker = 'n';
      this->climbInitialized = false;
      this->climbTrigged = false;
      this->isClimbing = false;
    }
  }
}

float Character::getX() {
  return this->x;
}

float Character::getY() {
  return this->y;
}

void Character::setPosition(float x, float y) {
  this->x = x;
  this->y = y;
}

float Character::getVx() {
  return this->vx;
}

float Character::getVy() {
  return this->vy;
}

char Character::getDirection() {
  return this->direction;
}
