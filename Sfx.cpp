#include "Sfx.h"

void Sfx::jump()
{
    gb.sound.fx(jump_fx);
}
void Sfx::climb()
{
    gb.sound.fx(climb_fx);
}
void Sfx::apple()
{
    gb.sound.fx(apple_fx);
}
void Sfx::takeFrag()
{
    gb.sound.fx(take_frag_fx);
}
void Sfx::dropFrag()
{
    gb.sound.fx(drop_frag_fx);
}
void Sfx::dropFragCtnr(uint8_t index)
{
    switch(index)
    {
        case 0:
            gb.sound.fx(drop_frag1_ctnr_fx);
            break;
        case 1:
            gb.sound.fx(drop_frag2_ctnr_fx);
            break;
        case 2:
            gb.sound.fx(drop_frag3_ctnr_fx);
            break;
        case 3:
            gb.sound.fx(drop_frag4_ctnr_fx);
            break;
    }
}

void Sfx::lose()
{
    gb.sound.fx(lose_fx);
}
void Sfx::win()
{
    gb.sound.fx(win_fx);
}
void Sfx::door()
{
    gb.sound.fx(door_fx); 
}
