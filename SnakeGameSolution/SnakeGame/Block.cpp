#pragma once
#include "stdafx.h"
#include "Block.h"


// constructor
Block::Block(std::string BlockType, int x, int y, float XScale, float YScale)
{
	// set start block position on the game screen
	MainSprite.setPosition(x, y);
	// set texture from the list of textures(BlockTypes)
	SetTexture(MainSprite, BlockTypes[BlockType], XScale, YScale);
}

// destructor
Block::~Block()
{
}

// Methods

// creates texture and defines scale for sprite
int Block::SetTexture(sf::Sprite &SpriteToSet, std::string TextureLocation, float XScale, float YScale)
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
