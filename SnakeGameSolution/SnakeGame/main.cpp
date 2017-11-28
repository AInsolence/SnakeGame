// SnakeGame.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "StartDisplay.h"
#include "Game.h"


int main()
{
	// Create main app window
	sf::RenderWindow window(sf::VideoMode(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HIGHT), "SFML works!");

	while (window.isOpen())
	{
		// Create Game object and render all eventsin the main window
		StartDisplay* MainMenu = new StartDisplay(window);
		Game* NewGame = new Game(window, "Anton");
		MainMenu->Run();
		delete MainMenu;
		// Run the new game
		NewGame->Run();
		delete NewGame;
	}

    return 0;
}

