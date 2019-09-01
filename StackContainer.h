#ifndef GLITCH_STACK_CONTAINER_H_
#define GLITCH_STACK_CONTAINER_H_

#include <Gamebuino-Meta.h>
#include "constants.h"

class StackContainer
{
    private:
        char objectsSequence[NB_STACK_FRAGMENTS];//objects ids
        void resetSequence();
    public:
        StackContainer();
        ~StackContainer() {};
        bool stackIsFull();
        void addObject(char objId);
        bool validateSequence();
        bool characterIsFacingContainer(uint8_t charX, uint8_t charY, uint8_t currentSpaceIndex);
        uint8_t getNextEmptySlotX();
        uint8_t getNextEmptySlotY();
        void reset();
};
#endif
