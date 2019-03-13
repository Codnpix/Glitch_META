#ifndef GLITCH_CHARACTER_H_
#define GLITCH_CHARACTER_H_

#include <Gamebuino-Meta.h>
#include "constants.h"
#include "mvtPatterns.h"
#include "Space.h";

class Character {
  private:
    float x;
    float y;
    float vx;
    float vy;
    
    char reqXMarker;//right and left move request marker
    char reqYMarker;//jump and fall request marker
    
    bool collidesRight;
    bool collidesLeft;
    //bool collidesTop; //no need
    bool isOnGround;
    
    bool canGrabLeft;
    bool canGrabRight;
    
    //bool wasClimbing;
    uint8_t yToClimb;
    bool climbTrigged;
    bool climbInitialized;
    
    char direction;
    uint8_t jumpFrame;
    uint8_t frame;
    bool nextFrame;
    uint8_t yGround;//y coordinate of the current ground
    float G_resistance;

    void trigJump();
    void playPatternJump(uint8_t frame);
    void trigClimb();
    void playPatternClimb(uint8_t frame);
    
    void applyMove();
    
    void checkCollisions(Space* space);
    bool collides(Tile aTile);

  public:
    bool isClimbing;
    bool isJumping;
  
    char typeOfCollision;
    void reqWalkRight();
    void reqWalkLeft();
    void reqJump();
    void reqFall();
    void reqStand();
    
    void update(Space* space);
     
    float getX();
    float getY();
    float getVx();
    float getVy();
    char getDirection();
    void setPosition(float x, float y);

    void init(uint8_t spawnX, uint8_t spawnY);
    
};
#endif
