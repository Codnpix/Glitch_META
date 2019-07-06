#ifndef GLITCH_CHARACTER_H_
#define GLITCH_CHARACTER_H_

#include <Gamebuino-Meta.h>
#include "constants.h"
#include "mvtPatterns.h"
#include "Space.h"

class Character 
{
  private:
    float x;
    float y;
    float vx;
    float vy;
    
    char reqXMarker;//X moves request marker
    char reqYMarker;//Y moves request marker

    char* animationState;
    uint8_t moveStateY;
    
    bool collidesRight;
    bool collidesLeft;
    bool isOnGround;
    uint8_t grabState;
    
    uint8_t yToClimb;
    bool climbplayed;
    bool climbInitialized;
    
    char direction;
    uint8_t jumpFrame;
    uint8_t climbFrame;
    bool nextFrame;
    uint8_t yGround;//y coordinate of the current ground
    float G_resistance;

    void playJump();
    void playPatternJump(uint8_t frame);
    void playClimb();
    void playPatternClimb(uint8_t frame);
    
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
    
  public:
    void reqWalkRight();
    void reqWalkLeft();
    void reqJump();
    void reqStand();
    void reqEnterDoor();
    
    void update(Space* space);
     
    float getX();
    float getY();
    float getVx();
    float getVy();
    char getDirection();
    void setPosition(float x, float y);

    void init(uint8_t spawnX, uint8_t spawnY);
    char* getAnimationState();
};
#endif
