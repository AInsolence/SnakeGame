#pragma once
#include "stdafx.h"

class IGameObject
{
public:
	IGameObject();
	virtual ~IGameObject();
	sf::Sprite MainSprite;

	FPair GetSpriteSize() const;
	
	int32 SetTexture(sf::Sprite &SpriteToSet, std::string TextureLocation, float, float);// create texture for sprite
	void SetSpriteSize(int32, int32);

protected:
	sf::Texture Texture;// helper var to textures mapping
	FPair SpriteSize;
};
