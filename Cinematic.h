#ifndef GLITCH_CINEMATIC_H
#define GLITCH_CINEMATIC_H

#include <Gamebuino-Meta.h>
#include "constants.h"

class Cinematic
{
  private:
    uint8_t fadeFrame;
    bool fadeNextFrame;
  public:
    Cinematic();
    bool playFadeIn();
    bool playFadeOut();
    void playClear();
    void playWin();
    void playLose();
};
#endif
