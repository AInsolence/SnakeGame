#pragma once
#include "stdafx.h"
#include "KeyListener.h"


KeyListener::KeyListener(sf::RenderWindow &window) : GameWindow(window)
{
	
}


KeyListener::~KeyListener()
{
}

void KeyListener::Start(Snake *Object, bool &IsGamePaused)
{
	sf::Event event;

	if (GameWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			GameWindow.close();
		// Handle user keyboard input in the game
		if (event.type == sf::Event::KeyPressed) {
			switch (event.key.code)
			{
			case sf::Keyboard::Space:
				if (IsGamePaused)
				{
					IsGamePaused = false;
				}
				else
				{
					IsGamePaused = true;
				}
				break;
			case sf::Keyboard::Left:
				if (Object->GetCurrentDirection() != ESnakeCurrentDirection::Right)
				{
					Object->SetCurrentDirection(ESnakeCurrentDirection::Left);
				}
				break;
			case sf::Keyboard::Right:
				if (Object->GetCurrentDirection() != ESnakeCurrentDirection::Left)
				{
					Object->SetCurrentDirection(ESnakeCurrentDirection::Right);
				}
				break;
			case sf::Keyboard::Up:
				if (Object->GetCurrentDirection() != ESnakeCurrentDirection::Down)
				{
					Object->SetCurrentDirection(ESnakeCurrentDirection::Up);
				}
				break;
			case sf::Keyboard::Down:
				if (Object->GetCurrentDirection() != ESnakeCurrentDirection::Up)
				{
					Object->SetCurrentDirection(ESnakeCurrentDirection::Down);
				}
			default:
				break;
			}
		}
	}
}
