/*
	This is a main Game class creates a new game with all objects,
	starts a new game loop, checking collisions and using game speed
	to increase/decrease difficalty for the player.
*/
#pragma once
#include "Records.h"

class Game
{
public:
	Game(sf::RenderWindow &window, std::string PlayerName);
	~Game();
	 
	int Run(Records &InputNameForm);// start the new game
	void GameOver(GameText * NewPlayerHUD, Records & InputNameForm);
	void ShowCurrentPosition(Records & InputNameForm);// player position on the score table
	void StartGameMusic();
	
private:
	// reference to the main window where the new game will be rendered
	sf::RenderWindow &GameWindow;
	std::string CurrentPlayerName;
	sf::Music GameMusic;//Game music and sounds
};

