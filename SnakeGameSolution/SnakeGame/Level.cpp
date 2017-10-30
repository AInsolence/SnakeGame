#pragma once
#include "stdafx.h"
#include "Level.h"


// constructor
Level::Level(int32 LevelHight, int32 LevelWidth): LevelWidth(LevelWidth),\
 LevelHight(LevelHight), LevelSurfaceTexture(' '), LevelBorderTexture('#')
{
	Display(); // create the canvas with x-width and y-hight sizes
}

// destructor
Level::~Level()
{
}

// Methods

void Level::Display()
{
	// create the level
	// TODO need to change creation of level
	FVector LevelRaw (LevelHight, LevelSurfaceTexture);// create column of the level
	std::fill_n(std::back_inserter(Canvas), LevelWidth, LevelRaw);// fill the canvas with columns
		
	// loop to create levels border
	for (int32 i = 0; i < LevelWidth; i++)
	{
		for (int32 j = 0; j < LevelHight; j++)
		{
			if (i == 0 || i == LevelWidth - 1 || j == 0 || j == LevelHight - 1)//if on the border
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