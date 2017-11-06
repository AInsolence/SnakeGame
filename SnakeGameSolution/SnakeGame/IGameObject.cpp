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

FPair IGameObject::GetSpriteSize() const
{
	return SpriteSize;
}

// Setters

int32 IGameObject::SetTexture(sf::Sprite &SpriteToSet, std::string TextureLocation, float XScale, float YScale)
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

void IGameObject::SetSpriteSize(int32 x, int32 y)
{
	SpriteSize.first = x;
	SpriteSize.second = y;
}
