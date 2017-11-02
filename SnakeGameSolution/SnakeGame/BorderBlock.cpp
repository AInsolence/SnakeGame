#pragma once
#include "stdafx.h"
#include "BorderBlock.h"


// constructor
BorderBlock::BorderBlock(std::string BlockType, int32 x, int32 y)
{
	constexpr int32 SPRITE_SIZE = 42;
	SetCoordinates(x, y);
	SetSprite(MainSprite, BlockTypes[BlockType]);
	SetSpriteSize(SPRITE_SIZE, SPRITE_SIZE);
}

// destructor
BorderBlock::~BorderBlock()
{
}

// Methods
