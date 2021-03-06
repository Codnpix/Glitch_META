#ifndef GLITCH_GAME_CONTROLLER_H_
#define GLITCH_GAME_CONTROLLER_H_

#include <Gamebuino-Meta.h>
#include "View.h"//includes character.h=>(with space.h, constants.h), Cinematic.h
#include "Backpack.h"
#include "Object.h"
#include "StackContainer.h"
#include "Sfx.h"

class GameController
{
    private:
        Character * character;
        Space * space;
        View * view;
        Cinematic* cinematic;
        Backpack * backpack;
        ObjectCollection * objCol;
        StackContainer * stkCtnr;
        Sfx * sfx;
        
        uint8_t currentSpace;
        bool cinematicMode;
        uint8_t cinematicIndex;
        uint8_t cinematicSeq;
        bool nextFrame;
        uint8_t nextSpaceIndex;
        uint8_t nextDoorIndex;
        uint8_t bonusCount;
        bool gameWon;
        bool gameLost;
        uint16_t chrono;
        
        void initSpace(uint8_t doorIndex);
        void initCharacter();
        void getInputs();
        void enterDoor();
        bool isCharacterFacingDoor(Door door);
        void setSpace(uint8_t spaceIndex);
        void loadSpace(uint8_t spaceIndex, uint8_t doorIndex);
        void changeSpace(uint8_t spaceIndex, uint8_t doorIndex);
        
        void handleCinematic();
        void handleChangeSpace();
        void handleAction();
        void pickObject(Object obj);
        void dropObject(uint8_t objId, bool toContainer);
        void handleEndGame();
        void handleWin();
        void handleLose();
        void resetGame();
        void playFx(uint8_t fxId);
    
    public:
        GameController();
        void initGame();
        void updateGame();
        void draw();
        uint8_t getCurrentSpace();
};
#endif
