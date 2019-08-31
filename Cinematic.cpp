#include "Cinematic.h"

Cinematic::Cinematic()
{
  this->fadeFrame = 1;
  this->chrono = 0;
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
  if (this->chrono <= 4)
  {
    this->chrono++;
    return true;
  } else
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
      this->chrono = 0;
      return false;
    }
    else return true;
  }
}

void Cinematic::playWin()
{
    gb.display.clear();
    gb.display.setColor(YELLOW);
    gb.display.print("YOU WIN ! \n");

    this->displayPressA();
    
}
void Cinematic::playLose()
{
    gb.display.clear();
    gb.display.setColor(BLUE);
    gb.display.print("YOU LOSE ! \n");

    this->displayPressA();
}

void Cinematic::displayPressA()
{
    gb.display.setColor(WHITE);
    gb.display.setCursor(SCREEN_W - 30, SCREEN_H - 8);
    this->chrono ++;
    if (this->chrono >= 12) gb.display.print("PRESS A\n");
    if (this->chrono >=24) this->chrono = 0;
}
