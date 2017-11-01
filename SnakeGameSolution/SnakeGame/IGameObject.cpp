#pragma once
#include "stdafx.h"
#include "IGameObject.h"

IGameObject::IGameObject()
{
	SetCoordinates(0, 0);// initialized by default
}

IGameObject::~IGameObject()
{
}

// Getters

sf::Sprite IGameObject::GetMainSprite() const
{
	return MainSprite;
}

FPair IGameObject::GetCoordinates() const
{
	return Coordinates;
}

// Setters

void IGameObject::SetCoordinates(int32 x, int32 y)// set new coordinates to object
{
	Coordinates.first = x;
	Coordinates.second = y;
}

int32 IGameObject::SetSprite(sf::Sprite &SpriteToSet, std::string TextureLocation)
{
	if (!Texture.loadFromFile(TextureLocation))// load texture image form file
	{
		return EXIT_FAILURE;// exit if do not find texture file
	}

	Texture.setSmooth(true);
	SpriteToSet.setTexture(Texture);// set Texture to Sprite
	SpriteToSet.setScale(sf::Vector2f(0.4f, 0.4f));// zoom our Texture
	SpriteToSet.setPosition(Coordinates.first, Coordinates.second);

	return 0;
}
