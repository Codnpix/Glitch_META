#include "View.h"

#include "graphicAssets.h"
#include "constants.h"

void View::draw(Space* space, Character* character) {
  float charX = character->getX();
  float charY = character->getY();
  this->followCharacter(charX, charY);

  gb.display.clear();
  
  //decor
  gb.display.setPalette(DECOR_PALETTE);
  gb.display.drawImage(this->cameraPosX, this->cameraPosY, decorMaps[this->spaceIndex]);

//TEMPORAIRE draw logictiles
  for (uint8_t row = 0; row < LOGIC_ROWS; row ++) {
    for (uint8_t col = 0; col < LOGIC_COLS; col++) {

      char tile = space->getLogic(row, col);
      
      if (tile == 's') {
        
        int16_t tileX, tileY;
        tileX = cameraPosX + LOGIC_TILE_W * col;
        tileY = cameraPosY + LOGIC_TILE_H * row;
        
        //gb.display.setColor(GREEN);//tmp
        //gb.display.fillRect(tileX, tileY, LOGIC_TILE_W, LOGIC_TILE_H);//tmp
        
      }
    }
  }

  
  //character
  int8_t charWdir;
  charWdir = (character->getDirection() == 'r') ? -CHARACTER_W : CHARACTER_W;
  this->drawCharacter(this->cameraPosX + charX, this->cameraPosY + charY, character->animationState, charWdir, CHARACTER_H);
}

void View::followCharacter(float charX, float charY) {
  if (charX + CHARACTER_W / 2 <= SCREEN_W / 2) this->setCameraPosX(0);
  else if (charX + CHARACTER_W / 2 >= SPACE_W - SCREEN_W / 2) this->setCameraPosX(-SPACE_W + SCREEN_W);
  else this->setCameraPosX(SCREEN_W / 2 - charX - CHARACTER_W / 2);

  if (charY + CHARACTER_H / 2 >= SPACE_H - SCREEN_H / 2) this->setCameraPosY(-(SPACE_H - SCREEN_H));
  else if (charY + CHARACTER_H / 2 <= SCREEN_H / 2) this->setCameraPosY(0);
  else this->setCameraPosY(SCREEN_H / 2 - charY - CHARACTER_H / 2);
}

void View::setSpaceIndex(uint8_t index) {
  this->spaceIndex = index;
}

void View::setCameraPosX(int16_t x) {
  this->cameraPosX = x;
}

void View::setCameraPosY(int16_t y) {
  this->cameraPosY = y;
}

void View::drawCharacter(float X, float Y, char* state, int8_t charW, uint8_t charH) {
  gb.display.setPalette(CHAR_SPRITE_PALETTE);
  if (state == "STAND") {
    gb.display.drawImage(X, Y, charSpriteStand, charW, charH);
  } else if (state == "WALK") {
    gb.display.drawImage(X, Y, charSpriteWalk, charW, charH);
  }
}
