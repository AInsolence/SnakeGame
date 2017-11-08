/*
	Level class is used to create level with borders, walls and other kind of obstacles for the game.
	Consists of Block objects.
*/
#pragma once
#include "Block.h"

class Level
{
public:
	Level(float XScale, float YScale);
	~Level();

	void SetMainBorder(int32 MAIN_WINDOW_WIDTH, int32 MAIN_WINDOW_HIGHT, float XScale, float YScale);
	std::vector<Block*> GetMainBorder ();

private:
	std::vector<Block*> MainBorder;// stores blocks represents main border of the level
};

