#pragma once
#include "stdafx.h"

class IGameObject
{
public:
	IGameObject();
	virtual ~IGameObject();

	sf::Sprite GetMainSprite() const;
	FPair GetSpriteSize() const;
	
	int32 SetTexture(sf::Sprite &SpriteToSet, std::string TextureLocation);// create texture for sprite
	void SetSpriteSize(int32, int32);
	void MoveSprite(int32, int32);

protected:
	sf::Sprite MainSprite;
	sf::Texture Texture;// helper var to textures mapping
	FPair SpriteSize;
};
