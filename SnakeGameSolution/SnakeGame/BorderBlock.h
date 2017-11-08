#pragma once
#include "stdafx.h"
#include <map>


class BorderBlock
{
public:
	// (SIZE, x_size, y_size)
	BorderBlock(std::string BlockType, int32 x, int32 y, float XScale, float YScale);
	~BorderBlock();

	sf::Sprite MainSprite;

	FPair GetSpriteSize() const;
	int32 SetTexture(sf::Sprite &SpriteToSet, std::string TextureLocation, float, float);// create texture for sprite
	void SetSpriteSize(int32, int32);

private:
	sf::Texture Texture;// helper var to textures mapping
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

