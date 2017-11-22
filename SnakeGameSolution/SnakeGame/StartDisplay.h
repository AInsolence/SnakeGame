/*
	This is a view class display start menu
	Contains on menu screen, options screen and records screen.
*/

#pragma once
#include "stdafx.h"
#include <string>
#include "Block.h"

constexpr int32 CURSOR_START_POS_X = 20;
constexpr int32 CURSOR_START_POS_Y = 30;

enum class EMenuPage
{
	MainMenu,
	Options,
	Records,
	Rules,
	Controls
};


class StartDisplay
{
public:
	StartDisplay(sf::RenderWindow &window);
	~StartDisplay();

	int32 Run() const;
	

private:
	sf::RenderWindow &MenuWindow;
	Block* Menu;
	Block* MenuCursor;
	void ShowMenuScreen() const;
	void ShowOptionsScreen() const;
	void ShowRecordsScreen() const;
	void ShowRules() const;
	void ShowControls() const;
};