#include "stdafx.h"
#include "Level.h"


// constructor
Level::Level(int32 LevelWidth, int32 LevelHight):LevelSurfaceTexture(' '), LevelBorderTexture('#')
{
	Create(LevelWidth, LevelHight); // create the canvas with x-width and y-hight sizes
}

// destructor
Level::~Level()
{
}

// Methods

void Level::Create(int32 LEVEL_HIGHT, int32 LEVEL_WIDTH)
{
	// create the level
	// TODO need to change creation of level
	FVector LevelRaw (LEVEL_HIGHT, LevelSurfaceTexture);// create column of the level
	std::fill_n(std::back_inserter(Canvas), LEVEL_WIDTH, LevelRaw);// fill the canvas with columns
		
	// loop to create levels border
	for (int32 i = 0; i < LEVEL_WIDTH; i++)
	{
		for (int32 j = 0; j < LEVEL_HIGHT; j++)
		{
			if (i == 0 || i == LEVEL_WIDTH - 1 || j == 0 || j == LEVEL_HIGHT - 1)//if on the border
			{
				Canvas[i][j] = LevelBorderTexture;// paint the border
			}
			else
			{
				Canvas[i][j] = LevelSurfaceTexture;// paint the surface
			}
		}
	}
}