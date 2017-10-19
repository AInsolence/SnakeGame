/*
	This is a view class display start menu
	Contains on menu screen, options screen and records screen.
*/

#pragma once
#include <string>

using int32 = int;
using FString = std::string;

enum class MenuPage
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

	//show menu by default
	//check what screen is displayed
	//if user press 1 - start the game 2 - show options 3 - 
	void ShowMenuScreen();
	void ShowOptionsScreen();
	void ShowRecordsScreen();
	void ShowRules();
	void ShowControls();

private:
	//initialization in constructor
	FString StartMenu;
	FString OptionsScreen;
	FString RecordsScreen;
	FString Rules;
	FString Controls;
};