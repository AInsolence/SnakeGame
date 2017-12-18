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

void Level::SetMainBorder(float MAIN_WINDOW_WIDTH, float MAIN_WINDOW_HIGHT, float XScale, float YScale)
{
	const float BLOCK_X = BASE_SPRITE_SIZE * XScale;
	const float BLOCK_Y = BASE_SPRITE_SIZE * YScale;
	// fill border with blocks
	for (float x = 0; x < MAIN_WINDOW_WIDTH; x += BLOCK_X)
	{
		for (float y = 0; y < MAIN_WINDOW_HIGHT; y += BLOCK_Y)
		{
			if (x == 0 || x == MAIN_WINDOW_WIDTH - BLOCK_X)
			{
				MainBorder.push_back(new Block("Block", x, y, XScale, YScale));
			}
			if (y == 0 || y == MAIN_WINDOW_HIGHT - BLOCK_Y)
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
