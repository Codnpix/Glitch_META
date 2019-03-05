#include "View.h"

#include "graphicAssets.h"
#include "constants.h"

void View::draw(float charX, float charY, Space* space) {
  this->followCharacter(charX, charY);

  gb.display.clear();
  //background
  for (uint8_t tile = 0; tile < 8; tile++) {
    gb.display.drawImage(this->cameraPosX + tile * BACKGROUND_TILE_W, 0 / 1.5, backgrounds[this->spaceIndex]);
  }
  //decorPart1
  gb.display.drawImage(this->cameraPosX, this->cameraPosY, decorMaps[this->spaceIndex][0]);
  //decorPart2
  gb.display.drawImage(this->cameraPosX + DECOR_TILE_W, this->cameraPosY, decorMaps[this->spaceIndex][1]);

//TEMPORAIRE draw logictiles
  for (uint8_t row = 0; row < LOGIC_ROWS; row ++) {
    for (uint8_t col = 0; col < LOGIC_COLS; col++) {

      char tile = space->getLogic(row, col);
      
      if (tile == 's') {
        
        int16_t tileX, tileY;
        uint8_t tileW, tileH;
        tileX = cameraPosX + (SPACE_W / LOGIC_COLS) * col;
        tileY = cameraPosY + (SPACE_H / LOGIC_ROWS) * row;
        tileH = SPACE_H / LOGIC_ROWS;
        tileW = SPACE_W / LOGIC_COLS;
        
        gb.display.setColor(GREEN);//tmp
        gb.display.fillRect(tileX, tileY, tileW, tileH);//tmp
        
      }
    }
  }

  
  //character
  gb.display.drawImage(this->cameraPosX + charX, this->cameraPosY + charY, charSprite, CHARACTER_W, CHARACTER_H);

  
}

void View::followCharacter(float charX, float charY) {
  if (charX + CHARACTER_W / 2 <= SCREEN_W / 2) this->setCameraPosX(0);
  else if (charX + CHARACTER_W / 2 >= SPACE_W - SCREEN_W / 2) this->setCameraPosX(-SPACE_W + SCREEN_W);
  else this->setCameraPosX(SCREEN_W / 2 - charX - CHARACTER_W / 2);

  if (charY + CHARACTER_H / 2 >= DECOR_TILE_H - SCREEN_H / 2) this->setCameraPosY(-(DECOR_TILE_H - SCREEN_H));
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
