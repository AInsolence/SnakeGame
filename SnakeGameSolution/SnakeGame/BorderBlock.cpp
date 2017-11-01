#pragma once
#include "stdafx.h"
#include "BorderBlock.h"


// constructor
BorderBlock::BorderBlock(std::string BlockType, int32 x, int32 y)
{
	SetCoordinates(x, y);
	SetSprite(MainSprite, BlockTypes[BlockType]);
}

// destructor
BorderBlock::~BorderBlock()
{
}

// Methods
