#pragma once
#include "stdafx.h"
#include "BorderBlock.h"


// constructor
BorderBlock::BorderBlock(std::string BlockType, int32 x, int32 y)
{
	constexpr int32 SPRITE_SIZE = 42;// TODO change to get sprite size from the object with native sf function
	MainSprite.setPosition(x, y);// set start sprite position
	SetTexture(MainSprite, BlockTypes[BlockType]);// set texture from the list of textures(BlockTypes)
	SetSpriteSize(SPRITE_SIZE, SPRITE_SIZE);
}

// destructor
BorderBlock::~BorderBlock()
{
}

// Methods
