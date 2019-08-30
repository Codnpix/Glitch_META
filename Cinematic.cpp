#include "Cinematic.h"

Cinematic::Cinematic()
{
  this->fadeFrame = 1;
}

bool Cinematic::playFadeIn()
{
  gb.display.setColor(BLACK);
  gb.display.fillRect(0,0,SCREEN_W, SCREEN_H / this->fadeFrame );
  gb.display.fillRect(0,SCREEN_H / 4, SCREEN_W, SCREEN_H / this->fadeFrame );
  gb.display.fillRect(0,SCREEN_H / 2, SCREEN_W, SCREEN_H / this->fadeFrame );
  gb.display.fillRect(0,3 * (SCREEN_H / 4),SCREEN_W, SCREEN_H / this->fadeFrame );
  this->fadeFrame++;
  if (this->fadeFrame >= FADE_LENGTH)
  {
    this->fadeFrame = 1;
    return false;
  }
  else return true;
}

void Cinematic::playClear()
{
  gb.display.setColor(BLACK);
  gb.display.fillRect(0,0,SCREEN_W, SCREEN_H);
}

bool Cinematic::playFadeOut()
{
  gb.display.setColor(BLACK);
  gb.display.fillRect(0,0,SCREEN_W, this->fadeFrame );
  gb.display.fillRect(0,SCREEN_H / 4, SCREEN_W, this->fadeFrame);
  gb.display.fillRect(0,SCREEN_H / 2, SCREEN_W, this->fadeFrame);
  gb.display.fillRect(0,3 * (SCREEN_H / 4),SCREEN_W, this->fadeFrame);
  this->fadeFrame++;
  if (this->fadeFrame >= FADE_LENGTH)
  {
    this->fadeFrame = 1;
    return false;
  }
  else return true;
}

void Cinematic::playWin()
{
    gb.display.clear();
    gb.display.setColor(YELLOW);
    gb.display.print("YOU WIN ! \n");
}
void Cinematic::playLose()
{
    gb.display.clear();
    gb.display.setColor(BLUE);
    gb.display.print("YOU LOSE ! \n");
}
