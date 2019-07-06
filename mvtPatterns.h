#ifndef GLITCH_MVT_PATTERNS_H_
#define GLITCH_MVT_PATTERNS_H_

//hyberbole y values for y = -x*x / 4
static const float JUMP_VY_PATTERN[13] = 
{
  -0.03, 
  -0.05, 
  -0.10, 
  -0.10,
  -4.40, 
  -2.48, 
  -1.10, 
  -0.28, 
  0.00, 
  0.28, 
  1.10, 
  2.48, 
  4.40
};

static const float CLIMB_SPEED = -3.65;

#endif
