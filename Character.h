#ifndef GLITCH_CHARACTER_H_
#define GLITCH_CHARACTER_H_

#include <Gamebuino-Meta.h>
#include "constants.h"
#include "mvtPatterns.h"
#include "Space.h"
#include "Sfx.h"

class Character
{
    private:
        Sfx * sfx;
        float x;
        float y;
        float vx;
        float vy;

        char reqXMarker;//X moves request marker
        char reqYMarker;//Y moves request marker

        uint8_t animationState;
        uint8_t moveStateY;
        float G_acceleration;

        bool collidesRight;
        bool collidesLeft;
        bool isOnGround;
        uint8_t grabState;

        uint8_t yToClimb;
        bool climbInitialized;
        bool jumpInitialized;

        char direction;
        uint8_t jumpFrame;
        uint8_t climbFrame;
        uint8_t skipFrame;
        bool nextFrame;
        uint8_t yGround;//y coordinate of the current ground
        float G_resistance;

        void playJump();
        void playPatternJump(uint8_t frame);
        void playClimb();
        void playPatternClimb();

        void applyMove();
        void updateAnimationState();

        void checkCollisions(Space* space);
        bool checkGrab();
        bool collides(Tile aTile);

        void handleXReqs();
        void handleGround();
        void handleYReqs(char req);

        Tile nTiles[2 * 3];
        void setNTiles(Space * space);

        void playFx(uint8_t fxId);

    public:
        Character();
        ~Character() {};
        void reqWalkRight();
        void reqWalkLeft();
        void reqJump();
        void reqStand();
        void reqEnterDoor();
        void reqTake();

        void update(Space * space);

        float getX();
        float getY();
        float getVx();
        float getVy();
        char getDirection();
        void setPosition(float x, float y);

        void init(uint8_t spawnX, uint8_t spawnY);
        uint8_t getAnimationState();
        uint8_t getAnimationFrame();
};
#endif
