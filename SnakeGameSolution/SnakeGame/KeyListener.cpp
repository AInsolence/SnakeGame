#pragma once
#include "stdafx.h"
#include "KeyListener.h"


KeyListener::KeyListener(sf::RenderWindow &window) : GameWindow(window)
{
	
}


KeyListener::~KeyListener()
{
}

void KeyListener::Start(Snake *Object)
{
	sf::Event event;

	while (GameWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			GameWindow.close();
		// Handle user keyboard input in the game
		if (event.type == sf::Event::KeyPressed) {
			switch (event.key.code)
			{
			case sf::Keyboard::Left:
				Object->SetCurrentDirection(ESnakeCurrentDirection::Left);
				break;
			case sf::Keyboard::Right:
				Object->SetCurrentDirection(ESnakeCurrentDirection::Right);
				break;
			case sf::Keyboard::Up:
				Object->SetCurrentDirection(ESnakeCurrentDirection::Up);
				break;
			case sf::Keyboard::Down:
				Object->SetCurrentDirection(ESnakeCurrentDirection::Down);
			default:
				break;
			}
		}
	}
}
