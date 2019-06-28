#ifndef GLITCH_CONSTANTS_H_
#define GLITCH_CONSTANTS_H_

static const uint8_t SCREEN_W = 80;
static const uint8_t SCREEN_H = 64;

static const uint8_t CHARACTER_W = 6;
static const uint8_t CHARACTER_GRAPHIC_WIDTH = 10;
static const uint8_t CHARACTER_H = 14;
static const uint8_t JUMP_PATTERN_LENGTH = 13;
static const uint8_t CHARACTER_WALK_SPEED = 4;//1 is max speed, more is slower. 0 is no animation.
static const uint8_t CHARACTER_WALK_FRAMES_NB = 4;//nb of frame in the "walk" spritesheet
static const uint8_t CHARACTER_JUMP_FRAMES_NB = 13;//nb of frame in the "jump" spritesheet
static const uint8_t CHARACTER_CLIMB_FRAMES_NB = 12;//nb of frame in the "climb" spritesheet

static const uint8_t NB_OF_SPACES = 1;
static const uint8_t SPACE_W = 240;
static const uint8_t SPACE_H = 128;
static const uint8_t LOGIC_ROWS = 16;
static const uint8_t LOGIC_COLS = 30;
static const uint8_t LOGIC_TILE_H = 8;
static const uint8_t LOGIC_TILE_W = 8;
static const uint8_t GRAVITY = 3;

#endif
