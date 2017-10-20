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

	int MenuListener() const;
	
private:
	void ShowMenuScreen() const;
	void ShowOptionsScreen() const;
	void ShowRecordsScreen() const;
	void ShowRules() const;
	void ShowControls() const;
};