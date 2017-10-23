#pragma once
#include "stdafx.h"
#include "StartDisplay.h"

// constructor
StartDisplay::StartDisplay() 
{
}

//destructor
StartDisplay::~StartDisplay()
{
}

// Methods

//show display and handle user input in menu area
int StartDisplay::MenuListener() const
{
	ShowMenuScreen(); //show main menu for player
	// use enum to track current page to handle user input with appropriate switcher
	EMenuPage CurrentMenuPage = EMenuPage::MainMenu;
	constexpr int32 ESC_KEY = 27;// used to handle "ESC" keystroke
	char UserCommand = ' ';// variable to store user input in menu area
	
	do{
		if (_kbhit())// check if any key is pressed by player
		{
			UserCommand = _getch();
		}

		if (CurrentMenuPage == EMenuPage::MainMenu)
			// main menu navigation
		{
			switch (UserCommand)
			{
				case '1':
					return 0;// TODO change line to "Start the new game"
					break;
				case '2':
					ShowOptionsScreen();
					CurrentMenuPage = EMenuPage::Options;
					UserCommand = ' ';// reset user input to avoid deep fall in menu
					break;
				case '3':
					ShowRecordsScreen();
					CurrentMenuPage = EMenuPage::Records;
			}
		}

		if (CurrentMenuPage == EMenuPage::Options)
			// options menu navigation
		{
			switch (UserCommand)
			{
			case '1':
				ShowRules();
				CurrentMenuPage = EMenuPage::Rules;
				break;
			case '2':
				ShowControls();
				CurrentMenuPage = EMenuPage::Controls;
				break;
			case ESC_KEY:
				ShowMenuScreen();
				CurrentMenuPage = EMenuPage::MainMenu;
				break;
			default:
				break;
			}
		}

		if(CurrentMenuPage == EMenuPage::Records)
			// records menu navigation
		{
			switch (UserCommand)
			{
			case ESC_KEY:
				ShowMenuScreen();
				CurrentMenuPage = EMenuPage::MainMenu;
				UserCommand = ' ';// reset user input to avoid deep fall in menu
				break;
			default:
				break;
			}
		}

		if (CurrentMenuPage == EMenuPage::Rules || CurrentMenuPage == EMenuPage::Controls)
			// go back to options menu
		{
			switch (UserCommand)
			{
			case ESC_KEY:
				ShowOptionsScreen();
				CurrentMenuPage = EMenuPage::Options;
				UserCommand = ' ';// reset user input to avoid returning straight to main menu
			default:
				break;
			}
		}
	} while (tolower(UserCommand) != 'q'); // user could press 'q' to exit game
	return 0;
}

void StartDisplay::ShowMenuScreen() const
{
	system ("cls");
	std::cout << "\n\n\n    1. Start new game \n    2. Options \n    3. Best Players \n\n\n\
    Press 'q' to exit the game" << std::endl;
}

void StartDisplay::ShowOptionsScreen() const
{
	system("cls");
	std::cout << "\n\n\n    Options: \n    1. Rules \n    2. Controls \n\n\n\
    Press ESC to return to the previous menu." << std::endl;
}

void StartDisplay::ShowRecordsScreen() const
{
	system("cls");
	std::cout << "\n\n\n    1. Anton \n    2. Anton \n    3. Anton \n\n\n\
    Press ESC to return to the previous menu." << std::endl;
}

void StartDisplay::ShowRules() const
{
	system("cls");
	std::cout << "\n\n\n    Rules \n\n\n\
    Press ESC to return to the previous menu." << std::endl;// TODO write game rules
}

void StartDisplay::ShowControls() const
{
	system("cls");
	std::cout << "\n\n\n    Controls \n\n\n\
    Press ESC to return to the previous menu." << std::endl;// TODO write game controls
}
