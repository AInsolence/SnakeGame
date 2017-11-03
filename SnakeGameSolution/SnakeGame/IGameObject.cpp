#pragma once
#include "stdafx.h"
#include "IGameObject.h"

IGameObject::IGameObject()
{
	MainSprite.setPosition(0, 0);// initialized by default
	SetSpriteSize(0, 0);// initialized by default
}

IGameObject::~IGameObject()
{
}

// Getters

sf::Sprite IGameObject::GetMainSprite() const
{
	return MainSprite;
}

FPair IGameObject::GetSpriteSize() const
{
	return SpriteSize;
}

// Setters

int32 IGameObject::SetTexture(sf::Sprite &SpriteToSet, std::string TextureLocation)
{
	if (!Texture.loadFromFile(TextureLocation))// load texture image form file
	{
		return EXIT_FAILURE;// exit if do not find texture file
	}

	Texture.setSmooth(true);
	SpriteToSet.setTexture(Texture);// set Texture to Sprite
	SpriteToSet.setScale(sf::Vector2f(0.2f, 0.2f));// zoom our Texture

	return 0;
}

void IGameObject::SetSpriteSize(int32 x, int32 y)
{
	SpriteSize.first = x;
	SpriteSize.second = y;
}

void IGameObject::MoveSprite(int32 x, int32 y)
{
	MainSprite.move(x, y);// TODO here is the problem with design!!
}

// Methods
