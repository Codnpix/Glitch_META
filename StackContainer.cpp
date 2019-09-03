#include "StackContainer.h"

//constant values to check on for detecting character presence
#define STACK_COORD_X 10 * LOGIC_TILE_W
#define STACK_COORD_Y 10 * LOGIC_TILE_H
#define STACK_GROUND_OFFSET 2 * LOGIC_TILE_H
#define STACK_W 24
#define STACK_H 40
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

void StackContainer::reset()
{
  this->resetSequence();
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
    else
    {
        return false;
    }
}

uint8_t StackContainer::getNextEmptySlotX()
{
    uint8_t x = STACK_COORD_X + LOGIC_TILE_W;
    return x;
}

uint8_t StackContainer::getNextEmptySlotY()
{
    for (uint8_t i = 0; i < NB_STACK_FRAGMENTS; i++)
    {
        if (this->objectsSequence[i] == '0')//first empty slot avaiblable
        {
            uint8_t y =
            STACK_COORD_Y + STACK_H - STACK_GROUND_OFFSET - (i * OBJECT_H);
            return y;
        }
    }
}

uint8_t StackContainer::getStackHeight()
{
    uint8_t stkheight = 0;
    for (uint8_t i = 0; i < NB_STACK_FRAGMENTS; i++)
    {
        if (this->objectsSequence[i] != '0') stkheight++;
    }
    return stkheight;
}
