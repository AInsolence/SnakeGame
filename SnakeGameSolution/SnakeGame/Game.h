/*
	This is a main Game class creates a new game with all objects,
	starts a new game loop, checking collisions and using game speed
	to increase/decrease difficalty for the player.
*/
#pragma once

class Game
{
public:
	Game(sf::RenderWindow &window, std::string PlayerName);
	~Game();

	int32 Run();// start the new game 

private:
	// reference to the main window where the new game will be rendered
	sf::RenderWindow &GameWindow;
	std::string MainText;
};

