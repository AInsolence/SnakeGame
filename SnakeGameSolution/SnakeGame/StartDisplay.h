/*
	This is a view class display start menu
	Contains on menu screen, options screen and records screen.
*/

#pragma once
#include <string>

using int32 = int;
using FString = std::string;

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
	StartDisplay();
	~StartDisplay();

	int MenuListener();
	
private:
	void ShowMenuScreen();
	void ShowOptionsScreen();
	void ShowRecordsScreen();
	void ShowRules();
	void ShowControls();
};