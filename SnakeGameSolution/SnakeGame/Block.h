/*
	Block is one of the base class provides us with building blocks.
	It's used to create the game objects.
*/

#pragma once
#include "stdafx.h"
#include <map>

//Base block size without scaling, depends on using tileset images
constexpr float BASE_SPRITE_SIZE = 420;

class Block
{
public:
	// (SIZE, x_size, y_size)
	Block(std::string BlockType, float x, float y, float XScale, float YScale);
	~Block();

	sf::Sprite MainSprite;// store object's image

	int SetTexture(sf::Sprite &SpriteToSet, std::string TextureLocation, float, float);

private:
	sf::Texture Texture;// helper variable used to textures mapping
	std::map<std::string, std::string> BlockTypes{
		{"Menu", "../img/MENU.png" },
		{ "MenuCursor", "../img/MENU_CURSOR.png" },
		{ "Options", "../img/OPTIONS.png" },
		{ "Records", "../img/RECORDS.png" },
		{ "GameOver", "../img/OVER.png" },
		{ "Pause", "../img/PAUSE.png" },
		{ "SolarBackground", "../img/SOLAR.jpeg"},
		{ "Head", "../img/SNAKE.png"},
		{ "HeadLeft", "../img/SNAKE_L.png" },
		{ "HeadRight", "../img/SNAKE_Rg.png" },
		{ "HeadDown", "../img/SNAKE_D.png" },
		{ "HeadUp", "../img/SNAKE_U.png" },
		{ "Body", "../img/SBODY.png" },
		{"Block", "../img/BLUE.png"},
		{ "Food", "../img/FOOD_1.png" },
		{ "Star", "../img/STAR.jpg" }
	};
};

