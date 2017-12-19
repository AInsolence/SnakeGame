#pragma once
#include "stdafx.h"
#include "StartDisplay.h"

// constructor
StartDisplay::StartDisplay(sf::RenderWindow &window) : MenuWindow(window)
{
	MenuBackground = new Block("Star", -150, -50, 1.0f, 1.0f);
	MenuCursor = new Block("Food", CURSOR_START_POS_X, CURSOR_START_POS_Y, 0.3f, 0.3f);
	// create main menu screen
	MainMenuNewGame = new GameText("NEW GAME", 270, 0, 200);
	MainMenuOptions = new GameText("OPTIONS", 270, CURSOR_STEP_BY_Y, 200);
	MainMenuRecords = new GameText("RECORDS", 270, 2*CURSOR_STEP_BY_Y, 200);
	MainMenuExit = new GameText("EXIT", 270, 3*CURSOR_STEP_BY_Y, 200);
	// create options screen
	OptionsHeader = new GameText("Game controls:", 230, 0, 150);
	ExitToMain = new GameText("RETURN TO THE MAIN MENU", 230, 3 * CURSOR_STEP_BY_Y + 30, 100);
	// create records screen
	RecordsHeader = new GameText("BEST PLAYERS:", 230, 0, 150);
}

//destructor
StartDisplay::~StartDisplay()
{
	delete MenuBackground;
	delete MenuCursor;
	delete MainMenuNewGame;
	delete MainMenuOptions;
	delete MainMenuRecords;
	delete MainMenuExit;
	delete OptionsHeader;
	delete ExitToMain;
	delete RecordsHeader;
}

// Methods

//show display and handle user input in menu area
int StartDisplay::Run(Records &InputNameForm) const
{
	//move cursor to the start position
	MenuCursor->MainSprite.setPosition(CURSOR_START_POS_X, CURSOR_START_POS_Y);
	// Menu music
	sf::Music GameMusic;// create music to stream from file
	if (!GameMusic.openFromFile("../music/menu.wav")) {
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
					int CurrentCursorPosition = \
						MenuCursor->MainSprite.getPosition().y;
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
						ShowRecordsScreen(InputNameForm);
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

int StartDisplay::ShowOptionsScreen() const
{
	std::string Rules = "RIGHT ARROW ----- turn right\nLEFT ARROW ----- turn left\n\
Up ARROW ----- turn up\nDOWN ARROW ----- turn down\nENTER ----- start the game\n\
SPACE ----- pause";
	GameText* GameRules = new GameText(Rules, 230, 150, 50);
	// move cursor to the end of options
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
					const int CurrentCursorPosition = \
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
		MenuWindow.draw(GameRules->GetText());
		MenuWindow.draw(ExitToMain->GetText());
		MenuWindow.display();
		MenuWindow.clear();
	}
}

int StartDisplay::ShowRecordsScreen(Records &InputNameForm) const
{
	int PlayerPosition = 0;
	int PositionOnScreenY = 150;
	std::vector<GameText*> AllRecords;
	for (auto& player : InputNameForm.GetTable())
	{
		PlayerPosition++;
		std::string Gap;
		for (size_t i = 50; i > (player.first.length() + \
			std::to_string(player.second).length()); i--)
		{// write spaces between name & scores
			Gap += '-';
		}
		std::string RecordMessage = std::to_string(PlayerPosition) + ". "\
			+ player.first + Gap + std::to_string(player.second);
		AllRecords.push_back(new GameText(RecordMessage, 230, PositionOnScreenY, 50));
		PositionOnScreenY += 50;
	}
	// move cursor to the end of the records
	MenuCursor->MainSprite.setPosition(CURSOR_START_POS_X, CURSOR_START_POS_Y);
	bool Show = true;
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
				constexpr int CURSOR_STEP_BY_X = 15;
				constexpr int CURSOR_STEP_BY_Y = 160;

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
					const int CurrentCursorPosition = \
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
		for (int i = 0; i < 7; i++)
		{
			MenuWindow.draw(AllRecords[i]->GetText());
		}
		MenuWindow.draw(ExitToMain->GetText());
		MenuWindow.display();
		MenuWindow.clear();
	}
}

int StartDisplay::ShowInputName(Records &InputNameForm) const
{
	GameText* EnterName = new GameText("Hero, please enter your name:", 200, 50, 80);
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
				if (event.key.code == sf::Keyboard::BackSpace)
				{
					if (PlayerName.getSize() > 0)
					{// delete last character in input user name form
						PlayerName.erase(PlayerName.getSize() - 1, 1);
					}
					InputNameForm.PlayerName->SetMainText(PlayerName);
				}
			}
			// input user name
			if (event.type == sf::Event::TextEntered)
			{
				// use only ASCII symbols
				if (event.text.unicode > 48 && event.text.unicode < 128)
				{
					PlayerName += static_cast<char>(event.text.unicode);
					InputNameForm.PlayerName->SetMainText(PlayerName);
				}
			}
		}

		MenuWindow.draw(MenuBackground->MainSprite);
		MenuWindow.draw(EnterName->GetText());
		MenuWindow.draw(InputNameForm.GetNameInputForm()->MainSprite);
		MenuWindow.draw(InputNameForm.PlayerName->GetText());

		MenuWindow.display();
		MenuWindow.clear();
	}
}