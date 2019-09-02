#ifndef GLITCH_SFX_H_
#define GLITCH_SFX_H_
#pragma once
#include "soundAssets.h"

class Sfx
{
    public:
        void jump();
        void climb();
        void apple();
        void takeFrag();
        void dropFrag();
        void dropFragCtnr(uint8_t index);
        void lose();
        void win();
};
#endif
