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