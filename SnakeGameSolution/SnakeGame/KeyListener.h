/*
	KeyListener class handles user input and changes the Snake object direction.
*/

#pragma once
#include "Snake.h"

constexpr char KEY_UP = 'w';
constexpr char KEY_DOWN = 's';
constexpr char KEY_LEFT = 'a';
constexpr char KEY_RIGHT = 'd';

class KeyListener // Change to sf::Keyboard interaction
{
public:
	KeyListener();
	~KeyListener();

	void Start(Snake *Object);
	char KeyCommand;
};

