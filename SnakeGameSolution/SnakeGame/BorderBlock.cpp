#pragma once
#include "stdafx.h"
#include "BorderBlock.h"


// constructor
BorderBlock::BorderBlock(std::string BlockType, int32 x, int32 y, float XScale, float YScale)
{
	constexpr int32 SPRITE_SIZE = 42;// TODO change to get sprite size from the object with native sf function
	MainSprite.setPosition(x, y);// set start sprite position
	SetTexture(MainSprite, BlockTypes[BlockType], XScale, YScale);// set texture from the list of textures(BlockTypes)
	SetSpriteSize(SPRITE_SIZE, SPRITE_SIZE);
}

// destructor
BorderBlock::~BorderBlock()
{
}

//Getters

FPair BorderBlock::GetSpriteSize() const
{
	return SpriteSize;
}

//Setters

void BorderBlock::SetSpriteSize(int32 x, int32 y)
{
	SpriteSize.first = x;
	SpriteSize.second = y;
}

// Methods

int32 BorderBlock::SetTexture(sf::Sprite &SpriteToSet, std::string TextureLocation, float XScale, float YScale)
{
	if (!Texture.loadFromFile(TextureLocation))// load texture image form file
	{
		return EXIT_FAILURE;// exit if do not find texture file
	}

	Texture.setSmooth(true);
	SpriteToSet.setTexture(Texture);// set Texture to Sprite
	SpriteToSet.setScale(sf::Vector2f(XScale, YScale));// zoom our Texture

	return 0;
}
