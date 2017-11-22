#pragma once
#include "stdafx.h"
#include "StartDisplay.h"


// constructor
StartDisplay::StartDisplay(sf::RenderWindow &window) : MenuWindow(window)
{
	Menu = new Block("Menu", 0, -60, 0.68f, 0.68f);
	MenuCursor = new Block("MenuCursor", CURSOR_START_POS_X, CURSOR_START_POS_Y, 0.15f, 0.15f);
}

//destructor
StartDisplay::~StartDisplay()
{
}

// Methods

//show display and handle user input in menu area
int StartDisplay::Run() const
{
	ShowMenuScreen(); //show main menu for player
	// use enum to track current page to handle user input with appropriate switcher
	EMenuPage CurrentMenuPage = EMenuPage::MainMenu;
	while (MenuWindow.isOpen())
	{
		sf::Event event;

		while (MenuWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed){
				MenuWindow.close();
			}
			// Handle user keyboard input in main menu
			if (event.type == sf::Event::KeyPressed) {
				// cursor step in menu in pixels
				constexpr int32 CURSOR_STEP_BY_X = 15;
				constexpr int32 CURSOR_STEP_BY_Y = 160;

				switch (event.key.code)
				{
				case sf::Keyboard::Down:// go down by menu points
					if (MenuCursor->MainSprite.getPosition().y < MAIN_WINDOW_HIGHT - 300)
					{// if curson not on the bottom of the screen
						MenuCursor->MainSprite.move(-CURSOR_STEP_BY_X, CURSOR_STEP_BY_Y);
					}
					break;
				case sf::Keyboard::Up:// go up by menu points
					if (MenuCursor->MainSprite.getPosition().y > 50)
					{// if curson not on the top of the screen
						MenuCursor->MainSprite.move(CURSOR_STEP_BY_X, -CURSOR_STEP_BY_Y);
					}
					break;
				case sf::Keyboard::Return:// choose a menu point
					const int32 CurrentCursorPosition =\
						MenuCursor->MainSprite.getPosition().y;// get cursor Y position
					switch (CurrentCursorPosition)
					{
					case CURSOR_START_POS_Y:// TODO Change to cursor start pos const
						return 0;
						break;
					case CURSOR_START_POS_Y + CURSOR_STEP_BY_Y:
						std::cout << "Options! ";
						break;
					case CURSOR_START_POS_Y + 2*CURSOR_STEP_BY_Y:
						std::cout << "Records! ";
						break;
					case CURSOR_START_POS_Y + 3*CURSOR_STEP_BY_Y:
						MenuWindow.close();
					default:
						break;
					}
					break;
				}
			}
		}

		MenuWindow.draw(Menu->MainSprite);
		MenuWindow.draw(MenuCursor->MainSprite);

		MenuWindow.display();
		MenuWindow.clear();
	}
	return 0;
}

void StartDisplay::ShowMenuScreen() const
{
	
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
