#include "stdafx.h"
#include "Level.h"


Level::Level()
{
	float XScale = 0.2f;
	float YScale = 0.2f;
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
	// fill border with blocks
	for (int32 x = 0; x < MAIN_WINDOW_WIDTH; x += 42)//TODO change 42 to variable SpriteSize
	{
		for (int32 y = 0; y < MAIN_WINDOW_HIGHT; y += 42)
		{
			if (x == 0 || x == MAIN_WINDOW_WIDTH - 42 || y == 0 || y == MAIN_WINDOW_HIGHT - 42)
			{
				MainBorder.push_back(new BorderBlock("Light", x, y, XScale, YScale));
			}
		}
	}
}

std::vector<BorderBlock*> Level::GetMainBorder()// returns main border of the level
{
	return MainBorder;
}
