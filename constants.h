#ifndef GLITCH_CONSTANTS_H_
#define GLITCH_CONSTANTS_H_
#pragma once 

static const uint8_t SCREEN_W = 80;
static const uint8_t SCREEN_H = 64;

static const uint8_t CHARACTER_W = 6;
static const uint8_t CHARACTER_GRAPHIC_WIDTH = 10;
static const uint8_t CHARACTER_H = 14;
static const uint8_t JUMP_PATTERN_LENGTH = 13;
static const uint8_t CLIMB_PATTERN_LENGTH = 12;
static const uint8_t CHARACTER_WALK_SPEED = 4;//1 is max speed, more is slower. 0 is no animation.
static const uint8_t CHARACTER_WALK_FRAMES_NB = 4;//nb of frame in the "walk" spritesheet
static const uint8_t CHARACTER_JUMP_FRAMES_NB = 13;//nb of frame in the "jump" spritesheet
static const uint8_t CHARACTER_CLIMB_FRAMES_NB = 12;//nb of frame in the "climb" spritesheet

static const uint8_t NB_OF_SPACES = 8;
static const uint8_t SPACE_W = 240;
static const uint8_t SPACE_H = 128;
static const uint8_t LOGIC_ROWS = 16;
static const uint8_t LOGIC_COLS = 30;
static const uint8_t LOGIC_TILE_H = 8;
static const uint8_t LOGIC_TILE_W = 8;
static const uint8_t NB_DOORS_PER_SPACE = 4;

static const uint8_t GRAVITY = 3;

static const uint8_t FADE_LENGTH = 15;

static const uint8_t NB_STACK_FRAGMENTS = 4;
static const uint8_t NB_TOTAL_BONUS = 2;//? we'll see..
static const uint8_t TOTAL_OBJECTS = NB_STACK_FRAGMENTS + NB_TOTAL_BONUS;
static const uint8_t OBJECT_W = 8;
static const uint8_t OBJECT_H = 8;
static const char STACK_SEQUENCE[NB_STACK_FRAGMENTS] = {'1','2','3','4'};//yellow red green violet

#endif
