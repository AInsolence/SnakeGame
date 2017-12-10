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
		// Create Game object and render all eventsin the main window
		StartDisplay* MainMenu = new StartDisplay(window);
		Game* NewGame = new Game(window, "Player");
		Records records;
		MainMenu->Run();
		// Run the new game
		NewGame->Run();
	}

    return 0;
}

