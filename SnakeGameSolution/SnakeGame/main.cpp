// SnakeGame.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "StartDisplay.h"
#include "Game.h"


int main()
{
	// Create main app window
	sf::RenderWindow window(sf::VideoMode(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HIGHT), "SFML works!");
	// Create Game object and render all eventsin the main window
	StartDisplay MainMenu(window);
	Game NewGame(window, "Anton");
	MainMenu.Run();
	// Run the new game
	NewGame.Run();
	
    return 0;
}

