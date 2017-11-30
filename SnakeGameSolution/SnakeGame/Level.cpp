#pragma once
#include "stdafx.h"
#include "Level.h"


Level::Level(float XScale, float YScale)
{
	SetMainBorder(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HIGHT, XScale, YScale);
}


Level::~Level()
{
	for (auto block : MainBorder)
	{
		delete block;
	}
}

void Level::SetMainBorder(int32 MAIN_WINDOW_WIDTH, int32 MAIN_WINDOW_HIGHT, float XScale, float YScale)
{
	const float DISTANCE_BETWEEN_BLOCKS_X = BASE_SPRITE_SIZE * XScale;
	const float DISTANCE_BETWEEN_BLOCKS_Y = BASE_SPRITE_SIZE * YScale;
	// TODO bug with another scale of the game level border block need t fix
	//std::cout << "x = " << DISTANCE_BETWEEN_BLOCKS_X << " y = " << DISTANCE_BETWEEN_BLOCKS_Y << std::endl;
	// fill border with blocks
	for (float x = 0; x < MAIN_WINDOW_WIDTH; x += DISTANCE_BETWEEN_BLOCKS_X)
	{
		for (float y = 0; y < MAIN_WINDOW_HIGHT; y += DISTANCE_BETWEEN_BLOCKS_Y)
		{
			if (x == 0 || x == MAIN_WINDOW_WIDTH - DISTANCE_BETWEEN_BLOCKS_X)
			{
				MainBorder.push_back(new Block("Block", x, y, XScale, YScale));
			}
			if (y == 0 || y == MAIN_WINDOW_HIGHT - DISTANCE_BETWEEN_BLOCKS_Y)
			{
				MainBorder.push_back(new Block("Block", x, y, XScale, YScale));
			}
		}
	}
}

std::vector<Block*> Level::GetMainBorder() const// returns main border of the level
{
	return MainBorder;
}
