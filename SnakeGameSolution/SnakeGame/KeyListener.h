/*
	KeyListener class handles user input and changes the Snake object direction.
*/

#pragma once
#include "Snake.h"

class KeyListener // Change to sf::Keyboard interaction
{
public:
	KeyListener(sf::RenderWindow &window);
	~KeyListener();

	void Start(Snake *Object, bool &IsGamePaused);
private:
	sf::RenderWindow &GameWindow;
};

