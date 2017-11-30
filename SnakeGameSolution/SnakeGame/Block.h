/*
	Block is one of the base class provides us with building blocks.
	It's used to create the game objects.
*/

#pragma once
#include "stdafx.h"
#include <map>

//Base block size without scaling, depends on using tileset images
constexpr int32 BASE_SPRITE_SIZE = 420;

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
		{"Blue", "../../img/Block_Blue.png"},
		{ "Dark", "../../img/Block_Box_1_Dark.png" },
		{ "Light", "../../img/Block_Box_1_Light.png" },
		{ "Green", "../../img/Block_Green.png" },
		{ "Red", "../../img/Block_Red.png" },
		{ "Yellow", "../../img/Block_Yellow.png" },
		{"Menu", "../../img/MENU.png" },
		{ "MenuCursor", "../../img/MENU_CURSOR.png" },
		{ "Options", "../../img/OPTIONS.png" },
		{ "Records", "../../img/RECORDS.png" },
		{ "GameOver", "../../img/OVER.png" },
		{ "Pause", "../../img/PAUSE.png" },
		{ "SolarBackground", "../../img/SOLAR.jpeg"},
		{ "Head", "../../img/SNAKE.png"},
		{ "HeadLeft", "../../img/SNAKE_L.png" },
		{ "HeadRight", "../../img/SNAKE_Rg.png" },
		{ "HeadDown", "../../img/SNAKE_D.png" },
		{ "HeadUp", "../../img/SNAKE_U.png" },
		{ "Body", "../../img/SBODY.png" },
		{"Block", "../../img/BLUE.png"},
		{ "Food", "../../img/FOOD_1.png" },
		{ "Star", "../../img/STAR.jpg" }
	};
};

