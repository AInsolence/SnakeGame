#pragma once
#include "BorderBlock.h"


// constructor
BorderBlock::BorderBlock(std::string BlockType, int32 x, int32 y):IGameObject(BlockTypes[BlockType])
{
	SetCoordinates(x, y);
}

// destructor
BorderBlock::~BorderBlock()
{
}

// Methods
