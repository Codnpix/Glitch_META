#include "Character.h"

void Character::init(uint16_t spawnX, uint16_t spawnY) {
  this->reqXMarker = 'n';
  this->setPosition(spawnX, spawnY);
  //this->setPosition(50.0,50.0);
  this->isJumping = false;
}

void Character::reqWalkRight() {
  this->reqXMarker = 'r';
}

void Character::reqWalkLeft() {
  this->reqXMarker = 'l';
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
  
  if (this->reqYMarker == 'j') {
    this->isJumping = true;
    this->trigJump();
  } else if(this->reqYMarker == 'n' && !this->isOnGround) {
    this->G_resistance = 0;
  }

  if (this->isOnGround) {
    this->y = yGround - CHARACTER_H;
  }
  
  this->vy = GRAVITY + this->G_resistance;

  this->applyMove();
  
}

void Character::checkCollisions(Space* space) {
  //parse logic map, check collisions :

  uint8_t colNum = floor((this->x) / (SPACE_W / LOGIC_COLS));
  uint8_t rowNum = floor((this->y) / (SPACE_H / LOGIC_ROWS));
  int16_t tileX, tileY;
  uint8_t tileW, tileH;
  tileH = SPACE_H / LOGIC_ROWS;
  tileW = SPACE_W / LOGIC_COLS;
  
  Tile nTiles[2 * 3];//the 6 tiles around the character
  
  uint8_t i;
  i = 0;
  
  for (uint8_t row = rowNum; row < rowNum + 3; row++) {
    for (uint8_t col = colNum; col < colNum + 2; col ++) {
      
      tileX = (SPACE_W / LOGIC_COLS) * col;
      tileY = (SPACE_H / LOGIC_ROWS) * row;
      
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
  }
  if ((this->collides(nTiles[0]) && nTiles[0].type == 's')
  || (this->collides(nTiles[2]) && nTiles[2].type == 's')) {
    this->collidesLeft = true;
  }
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
  if (frame < 10) {
    this->G_resistance = JUMP_VY_PATTERN[frame] / 3 - GRAVITY;
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
