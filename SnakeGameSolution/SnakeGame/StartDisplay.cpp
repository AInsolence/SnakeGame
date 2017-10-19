#pragma once
#include "stdafx.h"
#include "StartDisplay.h"


StartDisplay::StartDisplay() // constructor intialize text for main menu screens
{
	StartMenu = "\n\n\n    1. Start new game \n    2. Options \n    3. Best Players \n\n\n\
    Press 'q' to exit the game";

	OptionsScreen = "\n\n\n    Options: \n    1. Rules \n    2. Controls \n\n\n\
   Press ESC to return to previous menu.";

	RecordsScreen = "\n\n\n    1. Anton \n    2. Anton \n    3. Anton \n\n\n\
   Press ESC to return to previous menu.";

	Rules = "\n\n\n   Rules \n\n\n\
   Press ESC to return to previous menu.";// TODO write game rules
	
	Controls = "\n\n\n    Controls \n\n\n\
   Press ESC to return to previous menu.";// TODO write game controls
}

//destructor
StartDisplay::~StartDisplay()
{
}

//show display and handle user input in menu area
int StartDisplay::MenuListener()
{
	ShowMenuScreen(); //show main menu for player
	// use enum to track current page to handle user input with appropriate switcher
	MenuPage CurrentMenuPage = MenuPage::MainMenu;
	
	char UserCommand = ' ';// variable to store user input in menu area
	do{
		if (_kbhit())// check if any key is pressed by player
		{
			UserCommand = _getch();
		}

		if (CurrentMenuPage == MenuPage::MainMenu)
			// main menu navigation
		{
			switch (UserCommand)
			{
				case '1':
					return 0;// TODO change line to "Start the new game"
					break;
				case '2':
					ShowOptionsScreen();
					CurrentMenuPage = MenuPage::Options;
					UserCommand = ' ';// reset user input to avoid deep fall in menu
					break;
				case '3':
					ShowRecordsScreen();
					CurrentMenuPage = MenuPage::Records;
			}
		}

		if (CurrentMenuPage == MenuPage::Options)
			// options menu navigation
		{
			switch (UserCommand)
			{
			case '1':
				ShowRules();
				CurrentMenuPage = MenuPage::Rules;
				break;
			case '2':
				ShowControls();
				CurrentMenuPage = MenuPage::Controls;
				break;
			case 27:// handle "ESC" keystroke
				ShowMenuScreen();
				CurrentMenuPage = MenuPage::MainMenu;
				break;
			default:
				break;
			}
		}

		if(CurrentMenuPage == MenuPage::Records)
			// records menu navigation
		{
			switch (UserCommand)
			{
			case 27:// handle "ESC" keystroke
				ShowMenuScreen();
				CurrentMenuPage = MenuPage::MainMenu;
				UserCommand = ' ';// reset user input to avoid deep fall in menu
				break;
			default:
				break;
			}
		}

		if (CurrentMenuPage == MenuPage::Rules || CurrentMenuPage == MenuPage::Controls)
			// go back to options menu
		{
			switch (UserCommand)
			{
			case 27:// handle "ESC" keystroke
				ShowOptionsScreen();
				CurrentMenuPage = MenuPage::Options;
				UserCommand = ' ';// reset user input to avoid returning straight to main menu
			default:
				break;
			}
		}
	} while (tolower(UserCommand) != 'q'); // user could press 'q' to exit game
	return 0;
}

void StartDisplay::ShowMenuScreen()
{
	system ("cls");
	std::cout << StartMenu << std::endl;
}

void StartDisplay::ShowOptionsScreen()
{
	system("cls");
	std::cout << OptionsScreen << std::endl;
}

void StartDisplay::ShowRecordsScreen()
{
	system("cls");
	std::cout << RecordsScreen << std::endl;
}

void StartDisplay::ShowRules()
{
	system("cls");
	std::cout << Rules << std::endl;
}

void StartDisplay::ShowControls()
{
	system("cls");
	std::cout << Controls << std::endl;
}
