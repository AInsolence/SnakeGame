#pragma once
#include "stdafx.h"
#include "StartDisplay.h"

// constructor
StartDisplay::StartDisplay(sf::RenderWindow &window) : MenuWindow(window)
{
	MenuBackground = new Block("Star", -150, -50, 1.0f, 1.0f);
	MenuCursor = new Block("Food", CURSOR_START_POS_X, CURSOR_START_POS_Y, 0.3f, 0.3f);
	// create main menu screen
	MainMenuNewGame = new HUD("NEW GAME", 270, 0, 200);
	MainMenuOptions = new HUD("OPTIONS", 270, CURSOR_STEP_BY_Y, 200);
	MainMenuRecords = new HUD("RECORDS", 270, 2*CURSOR_STEP_BY_Y, 200);
	MainMenuExit = new HUD("EXIT", 270, 3*CURSOR_STEP_BY_Y, 200);
	// create options screen
	OptionsHeader = new HUD("OPTIONS", 230, 0, 150);
	ExitToMain = new HUD("RETURN TO THE MAIN MENU", 230, 3 * CURSOR_STEP_BY_Y + 30, 100);
	// create records screen
	RecordsHeader = new HUD("RECORDS", 230, 0, 150);
}

//destructor
StartDisplay::~StartDisplay()
{
}

// Methods

//show display and handle user input in menu area
int StartDisplay::Run(Records InputNameForm) const
{
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
	GameMusic.play();//start to play main game theme

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
						// show input name form before the starting the game
						ShowInputName(InputNameForm);
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

		MenuWindow.draw(MenuBackground->MainSprite);
		MenuWindow.draw(MenuCursor->MainSprite);
		MenuWindow.draw(MainMenuNewGame->GetText());
		MenuWindow.draw(MainMenuOptions->GetText());
		MenuWindow.draw(MainMenuRecords->GetText());
		MenuWindow.draw(MainMenuExit->GetText());

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

		MenuWindow.draw(MenuBackground->MainSprite);
		MenuWindow.draw(MenuCursor->MainSprite);
		MenuWindow.draw(OptionsHeader->GetText());
		MenuWindow.draw(ExitToMain->GetText());
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

		MenuWindow.draw(MenuBackground->MainSprite);
		MenuWindow.draw(MenuCursor->MainSprite);
		MenuWindow.draw(RecordsHeader->GetText());
		MenuWindow.draw(ExitToMain->GetText());
		MenuWindow.display();
		MenuWindow.clear();
	}
}

int32 StartDisplay::ShowInputName(Records InputNameForm) const
{
	HUD* EnterName = new HUD("Hero, please enter your name:", 200, 50, 80);
	// create user name input form
	sf::String PlayerName = "";

	while (MenuWindow.isOpen())
	{
		sf::Event event;

		while (MenuWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				MenuWindow.close();
			}
			// Handle user keyboard input on records screen
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Return)
				{
					InputNameForm.SetNewPlayer();
					return 0;
				}
			}
			// input user name handler
			if (event.type == sf::Event::TextEntered)
			{
				// use only ASCII symbols
				if (event.text.unicode < 128)
				{
					PlayerName += static_cast<char>(event.text.unicode);
					InputNameForm.PlayerName->SetMainText(PlayerName);
					std::cout << static_cast<char>(event.text.unicode);
				}
				// TODO create delete with backspace
			}
		}

		MenuWindow.draw(MenuBackground->MainSprite);
		MenuWindow.draw(EnterName->GetText());
		MenuWindow.draw(InputNameForm.NameInputForm->MainSprite);
		MenuWindow.draw(InputNameForm.PlayerName->GetText());

		MenuWindow.display();
		MenuWindow.clear();
	}
}