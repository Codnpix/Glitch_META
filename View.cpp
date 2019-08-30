#include "View.h"
#include "graphicAssets.h"

void View::draw(Space* space, Character* character, ObjectCollection * objCol)
{
  float charX = character->getX();
  float charY = character->getY();
  this->followCharacter(charX, charY);

  gb.display.clear();

  //decor
  gb.display.setPalette(DECOR_PALETTES[this->spaceIndex]);
  gb.display.drawImage(this->cameraPosX, this->cameraPosY, decorMaps[this->spaceIndex]);

  /*
  //debug : draw logic tiles...
  for (uint8_t row = 0; row < LOGIC_ROWS; row ++)
  {
    for (uint8_t col = 0; col < LOGIC_COLS; col++)
    {
      char tile = space->getLogic(row, col);
      if (tile == 's')
      {
        int16_t tileX, tileY;
        tileX = this->cameraPosX + LOGIC_TILE_W * col;
        tileY = this->cameraPosY + LOGIC_TILE_H * row;
      }
    }
  }
  */

  //character
  int8_t charWdir;
  uint8_t wDif = (CHARACTER_GRAPHIC_WIDTH - CHARACTER_W) / 2 ;
  charWdir = (character->getDirection() == 'r') ? -CHARACTER_GRAPHIC_WIDTH : CHARACTER_GRAPHIC_WIDTH;
  this->setSpriteSheet(character);
  this->handleCharacterAnimation(character);
  this->drawObjects(objCol);
  this->drawCharacter(this->cameraPosX + charX - wDif, this->cameraPosY + charY, character, charWdir, CHARACTER_H);
}

void View::followCharacter(float charX, float charY)
{
  if (charX + CHARACTER_W / 2 <= SCREEN_W / 2) this->setCameraPosX(0);
  else if (charX + CHARACTER_W / 2 >= SPACE_W - SCREEN_W / 2) this->setCameraPosX(-SPACE_W + SCREEN_W);
  else this->setCameraPosX(SCREEN_W / 2 - charX - CHARACTER_W / 2);

  if (charY + CHARACTER_H / 2 >= SPACE_H - SCREEN_H / 2) this->setCameraPosY(-(SPACE_H - SCREEN_H));
  else if (charY + CHARACTER_H / 2 <= SCREEN_H / 2) this->setCameraPosY(0);
  else this->setCameraPosY(SCREEN_H / 2 - charY - CHARACTER_H / 2);
}

void View::setSpaceIndex(uint8_t index)
{
  this->spaceIndex = index;
}

void View::setCameraPosX(int16_t x)
{
  this->cameraPosX = x;
}

void View::setCameraPosY(int16_t y) {
  this->cameraPosY = y;
}

void View::setSpriteSheet(Character* character)
{
  if (character->getAnimationState() == "WALK" )
  {
    this->spriteSheet = charSpriteWalk;
  } else if (character->getAnimationState() == "JUMP"
  || character->getAnimationState() == "FALL")
  {
    this->spriteSheet = charSpriteJump;
  } else if (character->getAnimationState() == "CLIMB")
  {
    this->spriteSheet = charSpriteClimb;
  } else if (character->getAnimationState() == "STAND")
  {
    this->spriteSheet = charSpriteBase;
  }
}

void View::handleCharacterAnimation(Character* character)
{
  if(character->getAnimationState() == "WALK")
  {
    this->charWalkClock = this->charWalkClock ?: 0;
    this->charWalkClock++;
    if (this->charWalkClock == CHARACTER_WALK_SPEED)
    {
      this->charAnimFrame = ++this->charAnimFrame % CHARACTER_WALK_FRAMES_NB;
      this->charWalkClock = 0;
    }
  }
  else if(character->getAnimationState() == "STAND")
  {
    this->charAnimFrame = 0;
  }
  else if (character->getAnimationState() == "JUMP")
  {
    if (character->getAnimationFrame() < CHARACTER_JUMP_FRAMES_NB)
    {
      this->charAnimFrame = character->getAnimationFrame();
    }
    else
    {
      this->charAnimFrame = CHARACTER_JUMP_FRAMES_NB;
    }
  }
  else if (character->getAnimationState() == "CLIMB")
  {
    if (character->getAnimationFrame() < CHARACTER_CLIMB_FRAMES_NB)
    {
      this->charAnimFrame = character->getAnimationFrame();
    }
    else
    {
      this->charAnimFrame = CHARACTER_CLIMB_FRAMES_NB;
    }
  }
  else if (character->getAnimationState() == "FALL")
  {
    this->charAnimFrame = CHARACTER_JUMP_FRAMES_NB;
  }
}

void View::drawCharacter(float X, float Y, Character* character, int8_t charW, uint8_t charH)
{
  gb.display.setPalette(CHAR_SPRITE_PALETTE);
  this->spriteSheet.setFrame(this->charAnimFrame);
  gb.display.drawImage(X, Y, this->spriteSheet, charW, charH);
}

void View::drawObjects(ObjectCollection * objCol)
{
  gb.display.setColor(RED);
  for (uint8_t i = 0; i < TOTAL_OBJECTS; i++)
  {
    if(objCol->getObject(i).spaceIndex == this->spaceIndex
    && (objCol->getObject(i).state == 0 || objCol->getObject(i).state == 2)
    && objCol->getObject(i).id != '0')
    {
        if (isDigit(objCol->getObject(i).id))//it's a stack fragment
        {
            //pick the corresponding image
            gb.display.fillRect(objCol->getObject(i).x + this->cameraPosX, objCol->getObject(i).y + this->cameraPosY, 8,8);//TMP
        }
        else //it's an apple
        {
            //pick the apple image
            gb.display.setPalette(APPLE_PALETTE);
            gb.display.drawImage(objCol->getObject(i).x + this->cameraPosX, objCol->getObject(i).y + this->cameraPosY, apple_img);
        }

    }
  }
}

void View::drawObjectsOverview(Backpack * backpack, uint8_t bonusCount)
{
    gb.display.setColor(YELLOW);
    uint8_t seq[TOTAL_OBJECTS];
    for (uint8_t i = 0; i < TOTAL_OBJECTS; i++)
    {
        seq[i] = backpack->getObject(i).id;
    }
    gb.display.printf("%c,%c,%c,%c \n", seq[0], seq[1], seq[2], seq[3]);//tmp
    
    gb.display.setPalette(APPLE_PALETTE);
    gb.display.drawImage(1, 6, apple_small_img);
    gb.display.setCursorX(8);
    gb.display.printf("%d/%d \n", bonusCount, NB_TOTAL_BONUS);//tmp
}

void View::_debug_drawObjCol(ObjectCollection * objCol)
{
  gb.display.setColor(RED);
  gb.display.printf("obj: %d,%d,%d,%d,%d,%d \n",
  objCol->getObject(0).state,
  objCol->getObject(1).state,
  objCol->getObject(2).state,
  objCol->getObject(3).state,
  objCol->getObject(4).state,
  objCol->getObject(5).state);
}
