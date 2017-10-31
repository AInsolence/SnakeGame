#pragma once
#include "stdafx.h"

class IGameObject
{
public:
	IGameObject(std::string TextureLocation);
	~IGameObject();

	sf::Sprite GetMainSprite() const;
	FPair GetCoordinates() const;
	
	void SetCoordinates(int32, int32);
	int32 SetSprite(sf::Sprite SpriteToSet, std::string TextureLocation);

protected:
	sf::Sprite MainSprite;
	FPair Coordinates;
};
