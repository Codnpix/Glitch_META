#include "StackContainer.h"

//constant values to check on for detecting character presence
#define STACK_COORD_X 52 //au pif, à voir plus tard
#define STACK_COORD_Y 52//idem
#define STACK_W 16
#define STACK_H 32
#define STACK_SPACE_LOCATION 2 //the lab

StackContainer::StackContainer()
{
    this->resetSequence();
}

void StackContainer::resetSequence()
{
    for (uint8_t i = 0; i < NB_STACK_FRAGMENTS; i++)
    {
        this->objectsSequence[i] = '0';
    }
}

void StackContainer::addObject(char objId)
{
    for (uint8_t i = 0; i < NB_STACK_FRAGMENTS; i++)
    {
        if (this->objectsSequence[i] == '0')
        {
            this->objectsSequence[i] = objId;
            break;
        }
    }
}

bool StackContainer::stackIsFull()
{
    for (uint8_t i = 0; i < NB_STACK_FRAGMENTS; i++)
    {
        if (this->objectsSequence[i] == '0') return false;//we found an empty slot
    }
    return true;
}

bool StackContainer::validateSequence()
{
    for (uint8_t i = 0; i < NB_STACK_FRAGMENTS; i++)
    {
        if (this->objectsSequence[i] != STACK_SEQUENCE[i]) return false;
    }
    return true;
}

bool StackContainer::characterIsFacingContainer(uint8_t charX, uint8_t charY, uint8_t currentSpaceIndex)
{
    uint8_t charleft, charright, chartop, charbottom, stackleft, stackright, stacktop, stackbottom;

    charleft = charX;
    charright = charX + CHARACTER_W;
    chartop = charY;
    charbottom = charY + CHARACTER_H;

    stackleft = STACK_COORD_X;
    stackright = STACK_COORD_X + STACK_W;
    stacktop = STACK_COORD_Y;
    stackbottom = STACK_COORD_Y + STACK_H;

    if (charleft <= stackright
    && charright >= stackleft
    && chartop <= stackbottom
    && charbottom >= stacktop
    && currentSpaceIndex == STACK_SPACE_LOCATION)
    {
        return true;
    }
    else {
        return false;
    }
}
