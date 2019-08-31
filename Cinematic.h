#ifndef GLITCH_CINEMATIC_H
#define GLITCH_CINEMATIC_H

#include <Gamebuino-Meta.h>
#include "constants.h"

class Cinematic
{
  private:
    uint8_t fadeFrame;
    bool fadeNextFrame;
    uint8_t chrono;
  public:
    Cinematic();
    ~Cinematic() {};
    bool playFadeIn();
    bool playFadeOut();
    void playClear();
    void playWin();
    void playLose();
    void displayPressA();
};
#endif
