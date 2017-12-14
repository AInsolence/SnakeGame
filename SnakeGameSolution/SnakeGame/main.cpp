// SnakeGame.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "StartDisplay.h"
#include "Game.h"
#include "Records.h"

int main()
{
	// Create main app window
	sf::RenderWindow window(sf::VideoMode(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HIGHT), "SFML works!");

	while (window.isOpen())
	{
		// Create new PlayerName Object
		Records InputNameForm;
		// Create Game object and render all eventsin the main window
		StartDisplay* MainMenu = new StartDisplay(window);
		MainMenu->Run(InputNameForm);
		// Run the new game
		std::string PlayerName = InputNameForm.PlayerName->GetText().getString();
		Game* NewGame = new Game(window, PlayerName);
		NewGame->Run(InputNameForm);
		delete MainMenu;
		delete NewGame;
	}

    return 0;
}

