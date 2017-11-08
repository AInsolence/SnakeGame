#pragma once
#include "stdafx.h"
#include "Block.h"


// constructor
Block::Block(std::string BlockType, int32 x, int32 y, float XScale, float YScale)
{
	// set start block position on the game screen
	MainSprite.setPosition(x, y);
	// set texture from the list of textures(BlockTypes)
	SetTexture(MainSprite, BlockTypes[BlockType], XScale, YScale);
	SetSpriteSize(BASE_SPRITE_SIZE*XScale, BASE_SPRITE_SIZE*YScale);
}

// destructor
Block::~Block()
{
}

//Getters

FPair Block::GetSpriteSize() const
{
	return SpriteSize;
}

//Setters

void Block::SetSpriteSize(int32 x, int32 y)
{
	SpriteSize.first = x;
	SpriteSize.second = y;
}

// Methods

// creates texture and defines scale for sprite
int32 Block::SetTexture(sf::Sprite &SpriteToSet, std::string TextureLocation, float XScale, float YScale)
{
	if (!Texture.loadFromFile(TextureLocation))// load texture image form file
	{
		return EXIT_FAILURE;// exit if do not find texture file
	}

	Texture.setSmooth(true);
	SpriteToSet.setTexture(Texture);// binds Texture with Sprite
	SpriteToSet.setScale(sf::Vector2f(XScale, YScale));// zoom our Texture to given scale parameter

	return 0;
}
