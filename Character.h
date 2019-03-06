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
    bool isJumping;
    float G_resistance;
    bool isOnGround;
    uint8_t jumpFrame;
    bool nextFrame;
    uint8_t yGround;//y coordinate of the current ground

    void trigJump();
    void playPatternJump(uint8_t frame);
    
    void applyMove();
    
    void checkCollisions(Space* space);
    bool collides(Tile aTile);

  public:
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
    void setPosition(float x, float y);

    void init(uint16_t spawnX, uint16_t spawnY);
    
};
#endif
