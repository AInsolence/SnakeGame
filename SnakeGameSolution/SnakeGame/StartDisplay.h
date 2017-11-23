/*
	This is a view class display start menu
	Contains on menu screen, options screen and records screen.
*/

#pragma once
#include "stdafx.h"
#include <string>
#include "Block.h"

//menu cursor start position
constexpr int32 CURSOR_START_POS_X = 20;
constexpr int32 CURSOR_START_POS_Y = 30;
// cursor step in menu in pixels
constexpr int32 CURSOR_STEP_BY_X = 15;
constexpr int32 CURSOR_STEP_BY_Y = 160;

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
	Block* Options;
	Block* Records;
	int32 ShowOptionsScreen() const;
	int32 ShowRecordsScreen() const;
};