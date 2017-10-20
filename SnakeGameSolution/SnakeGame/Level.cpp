#include "stdafx.h"
#include "Level.h"


Level::Level(int32 x, int32 y)
{
	CreateCanvas(x, y);
}


Level::~Level()
{
}

void Level::CreateCanvas(int32 LEVEL_WIDTH, int32 LEVEL_HIGHT)
{
	MainObjectTexture = ' ';// main 'texture' to paint level
	LevelBorderTexture = '#';
	
	std::vector<char> Column (LEVEL_HIGHT, MainObjectTexture);// column of the canvas
	FField Canvas (LEVEL_WIDTH, Column);// create level canvas
		
	// loop to fill canvas with whitespaces and create main border
	for (int32 i = 0; i < LEVEL_WIDTH; i++)
	{
		for (int32 j = 0; j < LEVEL_HIGHT; j++)
		{
			if ((i == 0 || i == LEVEL_WIDTH - 1) || (j == 0 || j == LEVEL_HIGHT - 1))//if on the border
			{
				Canvas[i][j] = LevelBorderTexture;
			}
		}
	}
}