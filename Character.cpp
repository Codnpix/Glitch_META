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

void Character::reqJump() {
  this->reqYMarker = 'j';
}

void Character::reqFall() {
  this->reqYMarker = 'f';
}

void Character::applyMove() {
  this->x += this->vx;
  this->y += this->vy;
}

void Character::update(Space* space) {

  this->checkCollisions(space);
  
  //unlock collisions for not getting stuck if character wants to get away from collision
  if (this->collidesLeft && this->vx > 0) this->collidesLeft = false;
  if (this->collidesRight && this->vx < 0) this->collidesRight = false;

  //X moves
  if (this->reqXMarker == 'r') {
    
    if (!this->collidesRight) this->vx = 1;
    else this->vx = 0;
    
  } else if (this->reqXMarker == 'l') {
    
    if (!this->collidesLeft) this->vx = -1;
    else this->vx = 0;
    
  } else if (this->reqXMarker == 'n') this->vx = 0;


  //update the ground constraint for Y moves
  
  if(this->isOnGround && !this->isJumping) {
    this->G_resistance = - GRAVITY;
  }
  
  if(this->isOnGround && this->vy > 0) {
    this->isJumping = false;
    this->reqYMarker = 'n';
    this->jumpFrame = 0;
    this->G_resistance = - GRAVITY;
  }
  
  if (this->reqYMarker == 'j' && !this->isClimbing) {
    this->isJumping = true;
    this->trigJump();
  } else if(this->reqYMarker == 'n' && !this->isOnGround) {
    this->G_resistance = 0;
  }

  /*if (this->collidesTop && this->isJumping) {
    this->isJumping = false;
  }*/

  //climbing test
  if((this->canGrabLeft && this->reqXMarker == 'l')
  || (this->canGrabRight && this->reqXMarker == 'r')){

    
    
    
    if (this->y + CHARACTER_H > this->yToClimb) {
      this->isClimbing == true;
      this->isJumping == false;
      //set a playClimbPattern method that run only if isClimbing is true instead of this :
      this->G_resistance = - GRAVITY - 1.2; //TMP , set a constant instead of 1.2, or a pattern array
    }
    if (this->y + CHARACTER_H <= this->yToClimb) {
      //this->isClimbing = false;
      //this->wasClimbing = true;
      this->reqXMarker = 'n';
      this->reqYMarker = 'n';
    }
  }

  //correction, set the character right on the floor e.g. if he stops one pixel too low
  if (this->isOnGround) {
    this->y = yGround - CHARACTER_H;
  }
  
  this->vy = GRAVITY + this->G_resistance;

  this->applyMove();
  
  gb.display.setColor(RED);
  if (this->canGrabLeft) gb.display.println("GRAB LEFT");
  if (this->canGrabRight) gb.display.println("GRAB RIGHT");
  gb.display.println(this->yGround);
  
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
  } else if ((this->collides(nTiles[4]) && nTiles[4].type == ' ') 
  || (this->collides(nTiles[5]) && nTiles[5].type == ' ')) {
    this->isOnGround = false;
  }
  //right or left collision test
  if ((this->collides(nTiles[1]) && nTiles[1].type == 's')
  || (this->collides(nTiles[3]) && nTiles[3].type == 's')) {
    this->collidesRight = true;
  } else if ((this->collides(nTiles[1]) && nTiles[1].type == ' ')
  && (this->collides(nTiles[3]) && nTiles[3].type == ' ')) {
    this->collidesRight = false;
  }
  
  if ((this->collides(nTiles[0]) && nTiles[0].type == 's')
  || (this->collides(nTiles[2]) && nTiles[2].type == 's')) {
    this->collidesLeft = true;
  } else if ((this->collides(nTiles[0]) && nTiles[0].type == ' ')
  && (this->collides(nTiles[2]) && nTiles[2].type == ' ')) {
    this->collidesLeft = false;
  }

  //tests if character can grab ground above him
  if (this->collidesLeft && nTiles[0].type == ' ' && this->direction == 'l') {
    this->canGrabLeft = true;
    this->yToClimb = nTiles[2].top;
  } else this->canGrabLeft = false;
  
  if (this->collidesRight && nTiles[1].type == ' ' && this->direction == 'r') {
    this->canGrabRight = true;
    this->yToClimb = nTiles[3].top;
  } else this->canGrabRight = false;

  //top collision test
  /*if ((this->collides(nTiles[0]) && nTiles[0].type == 's' && this->y + CHARACTER_H > nTiles[0].bottom)
  || (this->collides(nTiles[1]) && nTiles[1].type == 's' && this->y + CHARACTER_H > nTiles[1].bottom)) {
    this->collidesTop = true;
  } else if ((this->collides(nTiles[0]) && nTiles[0].type == ' ')
  || (this->collides(nTiles[1]) && nTiles[1].type == ' ')) {
    this->collidesTop = false;
  }*/
}

//TESTING
bool Character::collides(Tile aTile) {
  float charLeft, charRight, charTop, charBottom;
  charLeft = this->x;
  charRight = charLeft + CHARACTER_W;
  charTop = this->y;
  charBottom = charTop + CHARACTER_H;

  if (charLeft <= aTile.right - 1
      && charRight >= aTile.left + 1
      && charTop <= aTile.bottom
      && charBottom >= aTile.top) {
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

void Character::climb() {
  /*if (this->y + CHARACTER_H > yToClimb) {
    this->G_resistance = 4 - GRAVITY; //TMP , set a constant for 4, or a pattern array
  }*/
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
