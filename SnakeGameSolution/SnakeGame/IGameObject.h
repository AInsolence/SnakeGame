#pragma once
#include "stdafx.h"

class IGameObject
{
public:
	IGameObject();
	virtual ~IGameObject();

	sf::Sprite GetMainSprite() const;
	FPair GetCoordinates() const;
	FPair GetSpriteSize() const;
	
	void SetCoordinates(int32, int32);// set coordinates of the top left corner of the object
	int32 SetSprite(sf::Sprite &SpriteToSet, std::string TextureLocation);
	void SetSpriteSize(int32, int32);

protected:
	sf::Sprite MainSprite;
	FPair Coordinates;// coordinates of the top left corner of the object
	sf::Texture Texture;// helper var to textures mapping
	FPair SpriteSize;
};
