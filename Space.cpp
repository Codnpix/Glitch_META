#include "Space.h"

uint8_t Space::getIndex() {
  return this->index;
}

void Space::setIndex(uint8_t index) {
  this->index = index;
}

void Space::setLogic() {
  for (uint8_t row = 0; row < 10; row++) {
    for (uint8_t col = 0; col < 30; col++) {
      this->logicMap[row][col] = logicMaps[this->index][row][col];
    }
  }
}

char Space::getLogic(uint8_t row, uint8_t col) {
  return this->logicMap[row][col];
}

uint8_t Space::getSpawnX() {
  uint8_t x;
  for (uint8_t row = 0; row < LOGIC_ROWS; row++) {
    for (uint8_t col = 0; col < LOGIC_COLS; col++) {
      char tile = this->getLogic(row, col);
      if (tile == 'c') {
        x = (SPACE_W / LOGIC_COLS) * col;
      }
    }
  }
  return x;
}

uint8_t Space::getSpawnY() {
  for (uint8_t row = 0; row < LOGIC_ROWS; row++) {
    for (uint8_t col = 0; col < LOGIC_COLS; col++) {
      if (this->getLogic(row, col) == 'c') {
        return ((SPACE_H / LOGIC_ROWS) * row) + LOGIC_TILE_H - CHARACTER_H;
      }
    }
  }
}
