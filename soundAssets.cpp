#include "soundAssets.h"

const Gamebuino_Meta::Sound_FX jump_fx[] =
{
    {Gamebuino_Meta::Sound_FX_Wave::NOISE,1,0,12,65,112,2},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,105,-6,-78,142,6},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,58,-3,127,636,2},
};

const Gamebuino_Meta::Sound_FX climb_fx[] =
{
    {Gamebuino_Meta::Sound_FX_Wave::NOISE,1,0,3,-30,112,4},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,31,2,-127,179,11},
    {Gamebuino_Meta::Sound_FX_Wave::NOISE,0,0,2,0,128,3},
};

const Gamebuino_Meta::Sound_FX apple_fx[] =
{
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,25,17,-25,106,3},
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,64,-6,-24,50,7},
};

const Gamebuino_Meta::Sound_FX take_frag_fx[] =
{
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,2,11,-42,100,3},
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,84,0,0,80,2},
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,64,0,0,67,2},
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,104,0,0,89,1},
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,74,0,0,67,1},
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,34,0,0,60,1},
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,30,0,0,67,1},
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,26,-5,10,56,5},
};

const Gamebuino_Meta::Sound_FX drop_frag_fx[] =
{
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,52,10,0,169,2},
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,76,0,0,150,2},
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,70,0,0,189,1},
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,62,0,0,179,1},
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,48,0,0,238,1},
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,40,0,0,212,1},
};

const Gamebuino_Meta::Sound_FX drop_frag1_ctnr_fx[] =
{
	{Gamebuino_Meta::Sound_FX_Wave::NOISE,1,0,3,70,112,11},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,255,0,0,378,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,185,0,0,357,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,175,0,0,378,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,155,0,0,357,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,83,0,0,378,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,55,0,0,357,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,30,0,0,378,0},
};

const Gamebuino_Meta::Sound_FX drop_frag2_ctnr_fx[] =
{
    {Gamebuino_Meta::Sound_FX_Wave::NOISE,1,0,2,70,112,11},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,255,0,0,283,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,195,0,0,253,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,145,0,0,283,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,105,0,0,253,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,85,0,0,283,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,55,0,0,253,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,24,0,0,283,0},
};

const Gamebuino_Meta::Sound_FX drop_frag3_ctnr_fx[] =
{
    {Gamebuino_Meta::Sound_FX_Wave::NOISE,1,0,2,70,112,11},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,225,0,0,169,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,174,0,0,150,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,155,0,0,169,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,144,0,0,150,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,95,0,0,169,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,65,0,0,150,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,65,0,0,169,0},
};

const Gamebuino_Meta::Sound_FX drop_frag4_ctnr_fx[] =
{
  	{Gamebuino_Meta::Sound_FX_Wave::NOISE,1,0,2,73,64,10},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,195,0,0,126,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,195,0,0,113,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,155,0,0,126,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,115,0,0,113,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,75,0,0,126,1},
  	//{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,64,0,0,113,1},//end of original last container slot sfx
    //{Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,75,0,0,126,0},
    {Gamebuino_Meta::Sound_FX_Wave::NOISE,1,0,39,-20,176,50},//replaced by end of full stack sfx
    {Gamebuino_Meta::Sound_FX_Wave::NOISE,0,190,0,0,64,53},
};

const Gamebuino_Meta::Sound_FX lose_fx[] =
{
	{Gamebuino_Meta::Sound_FX_Wave::NOISE,0,190,2,127,0,200},
};

const Gamebuino_Meta::Sound_FX win_fx[] =
{
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,165,-2,0,67,5},
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,125,-2,0,53,5},
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,125,-2,0,45,5},
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,135,-2,0,60,5},
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,114,-2,0,50,5},
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,165,-2,0,40,5},
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,154,-2,0,30,19},
};

const Gamebuino_Meta::Sound_FX door_fx[] =
{
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,25,-1,0,189,4},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,40,-1,0,169,4},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,40,-1,0,159,4},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,40,-1,0,134,27},
};
