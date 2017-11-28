#pragma once
#include "stdafx.h"
#include "StartDisplay.h"


// constructor
StartDisplay::StartDisplay(sf::RenderWindow &window) : MenuWindow(window)
{
	Menu = new Block("Menu", 0, -30, 0.68f, 0.68f);
	MenuCursor = new Block("MenuCursor", CURSOR_START_POS_X, CURSOR_START_POS_Y, 0.25f, 0.25f);
	Options = new Block("Options", 0, -10, 0.68f, 0.68f);
	Records = new Block("Records", 0, -10, 0.68f, 0.68f);
}

//destructor
StartDisplay::~StartDisplay()
{
}

// Methods

//show display and handle user input in menu area
int StartDisplay::Run() const
{
	static bool bIsMusicPlay = false;
	//move cursor to the start position
	MenuCursor->MainSprite.setPosition(CURSOR_START_POS_X, CURSOR_START_POS_Y);
	// Menu music
	sf::Music GameMusic;// create music to stream from file
	if (!GameMusic.openFromFile("../../music/menu.wav")) {
		std::cout << "Main game music asset is not found! ";
		//return EXIT_FAILURE;
	}
	GameMusic.setLoop(true);
	GameMusic.setVolume(50);
	if (!bIsMusicPlay) {
		GameMusic.play();//start to play main game theme
		bIsMusicPlay = true;
	}

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
				switch (event.key.code)
				{
				case sf::Keyboard::Down:// go down by the menu points
					if (MenuCursor->MainSprite.getPosition().y < MAIN_WINDOW_HIGHT - 300)
					{// if curson not on the bottom of the screen
						MenuCursor->MainSprite.move(-CURSOR_STEP_BY_X, CURSOR_STEP_BY_Y);
					}
					break;
				case sf::Keyboard::Up:// go up by the menu points
					if (MenuCursor->MainSprite.getPosition().y > 50)
					{// if curson not on the top of the screen
						MenuCursor->MainSprite.move(CURSOR_STEP_BY_X, -CURSOR_STEP_BY_Y);
					}
					break;
				case sf::Keyboard::Return:// choose a menu point
					int32 CurrentCursorPosition = \
						MenuCursor->MainSprite.getPosition().y;
					std::cout << "CursorPosition: " << CurrentCursorPosition;
					switch (CurrentCursorPosition)
					{
					case CURSOR_START_POS_Y:
						return 0;
						break;
					case CURSOR_START_POS_Y + CURSOR_STEP_BY_Y:
						ShowOptionsScreen();
						break;
					case CURSOR_START_POS_Y + 2*CURSOR_STEP_BY_Y:
						ShowRecordsScreen();
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

int32 StartDisplay::ShowOptionsScreen() const
{
	// move cursor to the end of options. TODO change after adding real options points
	MenuCursor->MainSprite.setPosition(CURSOR_START_POS_X, CURSOR_START_POS_Y);
	while (MenuWindow.isOpen())
	{
		sf::Event event;

		while (MenuWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				MenuWindow.close();
			}
			// Handle user keyboard input in the options menu
			if (event.type == sf::Event::KeyPressed) {
				switch (event.key.code)
				{
				case sf::Keyboard::Down:// go down by the options points
					if (MenuCursor->MainSprite.getPosition().y < MAIN_WINDOW_HIGHT - 300)
					{// if curson not on the bottom of the screen
						MenuCursor->MainSprite.move(-CURSOR_STEP_BY_X, CURSOR_STEP_BY_Y);
					}
					break;
				case sf::Keyboard::Up:// go up by the options points
					if (MenuCursor->MainSprite.getPosition().y > 50)
					{// if curson not on the top of the screen
						MenuCursor->MainSprite.move(CURSOR_STEP_BY_X, -CURSOR_STEP_BY_Y);
					}
					break;
				case sf::Keyboard::Return:// choose an options point
					const int32 CurrentCursorPosition = \
						MenuCursor->MainSprite.getPosition().y;// get cursor Y position
					switch (CurrentCursorPosition)
					{
					case CURSOR_START_POS_Y + 3*CURSOR_STEP_BY_Y:
						return 0;// return to the main menu
						break;
					}
					break;
				}
			}
		}

		MenuWindow.draw(Options->MainSprite);
		MenuWindow.draw(MenuCursor->MainSprite);
		MenuWindow.display();
		MenuWindow.clear();
	}
}

int32 StartDisplay::ShowRecordsScreen() const
{
	// move cursor to the end of the records
	// TODO change after adding real records
	MenuCursor->MainSprite.setPosition(CURSOR_START_POS_X, CURSOR_START_POS_Y);
	while (MenuWindow.isOpen())
	{
		sf::Event event;

		while (MenuWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				MenuWindow.close();
			}
			// Handle user keyboard input on records screen
			if (event.type == sf::Event::KeyPressed) {
				// cursor step in menu in pixels
				constexpr int32 CURSOR_STEP_BY_X = 15;
				constexpr int32 CURSOR_STEP_BY_Y = 160;

				switch (event.key.code)
				{
				case sf::Keyboard::Down:// go down by the options points
					if (MenuCursor->MainSprite.getPosition().y < MAIN_WINDOW_HIGHT - 300)
					{// if curson not on the bottom of the screen
						MenuCursor->MainSprite.move(-CURSOR_STEP_BY_X, CURSOR_STEP_BY_Y);
					}
					break;
				case sf::Keyboard::Up:// go up by the options points
					if (MenuCursor->MainSprite.getPosition().y > 50)
					{// if curson not on the top of the screen
						MenuCursor->MainSprite.move(CURSOR_STEP_BY_X, -CURSOR_STEP_BY_Y);
					}
					break;
				case sf::Keyboard::Return:// choose a menu point
					const int32 CurrentCursorPosition = \
						MenuCursor->MainSprite.getPosition().y;// get cursor Y position
					switch (CurrentCursorPosition)
					{
					case CURSOR_START_POS_Y + 3 * CURSOR_STEP_BY_Y:
						return 0;// return to the main menu
						break;
					}
					break;
				}
			}
		}

		MenuWindow.draw(Records->MainSprite);
		MenuWindow.draw(MenuCursor->MainSprite);
		MenuWindow.display();
		MenuWindow.clear();
	}
}