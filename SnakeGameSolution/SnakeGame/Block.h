/*
	Block is one of the base class provides us with building blocks.
	It's used to create the game objects.
*/

#pragma once
#include "stdafx.h"
#include <map>

//Base block size without scaling, depends on using tileset images
constexpr int32 BASE_SPRITE_SIZE = 210;

class Block
{
public:
	// (SIZE, x_size, y_size)
	Block(std::string BlockType, int32 x, int32 y, float XScale, float YScale);
	~Block();

	sf::Sprite MainSprite;// store object's image

	FPair GetSpriteSize() const;
	int32 SetTexture(sf::Sprite &SpriteToSet, std::string TextureLocation, float, float);
	void SetSpriteSize(int32, int32);

private:
	sf::Texture Texture;// helper variable used to textures mapping
	FPair SpriteSize;
	std::map<std::string, std::string> BlockTypes{
		{"Blue", "../../image/Block_Blue.png"},
		{ "Dark", "../../image/Block_Box_1_Dark.png" },
		{ "Light", "../../image/Block_Box_1_Light.png" },
		{ "Green", "../../image/Block_Green.png" },
		{ "Red", "../../image/Block_Red.png" },
		{ "Yellow", "../../image/Block_Yellow.png" }
	};
};

