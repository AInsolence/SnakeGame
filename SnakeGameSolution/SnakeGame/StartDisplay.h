/*
	This is a view class display start menu
	Contains on menu screen, options screen and records screen.
*/

#pragma once
#include "stdafx.h"
#include <string>
#include "HUD.h"
#include "Block.h"
#include "Records.h"

//menu cursor start position
constexpr int32 CURSOR_START_POS_X = 80;
constexpr int32 CURSOR_START_POS_Y = 40;
// cursor step in menu in pixels
constexpr int32 CURSOR_STEP_BY_X = 0;
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

	int32 Run(Records InputNameForm) const;
	int32 ShowInputName(Records InputNameForm) const;

private:
	sf::RenderWindow &MenuWindow;
	Block* MenuCursor;
	Block* MenuBackground;
	HUD * MainMenuNewGame;
	HUD * MainMenuOptions;
	HUD * MainMenuRecords;
	HUD * MainMenuExit;
	HUD * OptionsHeader;
	HUD * ExitToMain;
	HUD * RecordsHeader;
	int32 ShowOptionsScreen() const;
	int32 ShowRecordsScreen() const;
};