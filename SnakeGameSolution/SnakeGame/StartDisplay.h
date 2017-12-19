/*
	This is a view class display start menu
	Contains on menu screen, options screen and records screen.
*/

#pragma once
#include "stdafx.h"
#include <string>
#include "GameText.h"
#include "Block.h"
#include "Records.h"

//menu cursor start position
constexpr int CURSOR_START_POS_X = 80;
constexpr int CURSOR_START_POS_Y = 40;
// cursor step in menu in pixels
constexpr int CURSOR_STEP_BY_X = 0;
constexpr int CURSOR_STEP_BY_Y = 160;

class StartDisplay
{
public:
	StartDisplay(sf::RenderWindow &window);
	~StartDisplay();

	int Run(Records &InputNameForm) const;
	

private:
	sf::RenderWindow &MenuWindow;
	Block* MenuCursor;
	Block* MenuBackground;
	GameText * MainMenuNewGame;
	GameText * MainMenuOptions;
	GameText * MainMenuRecords;
	GameText * MainMenuExit;
	GameText * OptionsHeader;
	GameText * ExitToMain;
	GameText * RecordsHeader;

	int ShowOptionsScreen() const;
	int ShowRecordsScreen(Records &InputNameForm) const;
	int ShowInputName(Records &InputNameForm) const;
};