#pragma once
#include "IGameObject.h"

IGameObject::IGameObject(std::string TextureLocation)
{
	SetSprite(MainSprite, TextureLocation);// create object with appropriate sprite
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

int32 IGameObject::SetSprite(sf::Sprite SpriteToSet, std::string TextureLocation)
{
	sf::Texture Texture;

	if (!Texture.loadFromFile(TextureLocation))// load texture image form file
	{
		return EXIT_FAILURE;// exit if do not find texture file
	}

	Texture.setSmooth(true);
	SpriteToSet.setTexture(Texture);// set Texture to Sprite
	SpriteToSet.setScale(sf::Vector2f(0.2f, 0.2f));// zoom our Texture
	SpriteToSet.setPosition(0, 0);

	return 0;
}
