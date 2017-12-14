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

	void SetMainBorder(int MAIN_WINDOW_WIDTH, int MAIN_WINDOW_HIGHT, float XScale, float YScale);
	std::vector<Block*> GetMainBorder () const;

private:
	std::vector<Block*> MainBorder;// stores blocks represents main border of the level
};

