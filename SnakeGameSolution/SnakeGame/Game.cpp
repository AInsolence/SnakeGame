#pragma once

#include <vector>
#include <random>

#include "stdafx.h"
#include "Game.h"
#include "HUD.h"
#include "Level.h"
#include "Snake.h"
#include "KeyListener.h"
#include "Food.h"
#include "bIsObjectsCollide.h"

// constructor
Game::Game(sf::RenderWindow &window, std::string PlayerName) : GameWindow (window)// link to the main window
{
	Player = PlayerName;
}

// destructor
Game::~Game()
{
}

// Methods

// create all game's objects and handlers, start a game loop
int32 Game::Run() const
{
	// ***Initialization of the game objects are used in the game loop***
	Level Level01(0.2f, 0.2f);//Create the level
	HUD hud(Player, 0);//Create the HUD
	Snake MySnake("Red", 200, 200, 0.2f, 0.2f);//Create the Snake
	// Create food
	Food* NewFood = new Food(600, 500, 0.2f, 0.2f, 10, 20);// TODO make real rand for x, y
	KeyListener Klistner;//Create the player's input handler
	bIsObjectsCollide bIsCollide;//Create collision detection functor
	sf::Clock clock;//start the clock

	// ***Start main game loop***
	while (GameWindow.isOpen())
	{
		// TODO replace this code to the KeyListener object
		sf::Event event;
		while (GameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				GameWindow.close();
		}
		Klistner.Start(&MySnake);// start handle player input

		MySnake.Move();// Start Snake movement
		
		// ***RENDERING PART OF THE GAME LOOP***
		// Level render
		for (auto block : Level01.GetMainBorder())
		{
			GameWindow.draw(block->MainSprite);
		}
		// Snake render
		for (auto segment : MySnake.Body)
		{
			GameWindow.draw(segment->MainSprite);
		}
		// Food render
		if (NewFood->GetStatus() == EFoodStatus::Appear)
		{
			GameWindow.draw(NewFood->Body->MainSprite);
		}
		
		//HUD render
		GameWindow.draw(hud.GetPlayerName());// display Player name
		GameWindow.draw(hud.GetScores());// display Scores
		
		GameWindow.display();//Display window and all game elements

		//Speed of the game handling through the system clock
		sf::Time TimeGap = sf::seconds(0.6f);
		sf::Time Elapsed = clock.restart();
		while (Elapsed < TimeGap)
		{
			Elapsed = clock.getElapsedTime();
		}
		// ***END OF RENDERING PART***

		// ***COLLISION DETECTION PART OF THE GAME LOOP***
		//Check collision with walls
		for (auto block : Level01.GetMainBorder())
		{
			if (bIsCollide(block, MySnake.Body[0]))
			{
				std::cout << "You are dead!" << std::endl;
				// TODO finish after ceating game over window
			}
		}
		//Check collision snake with it's own segments
		for (auto segment : MySnake.Body)
		{
			if (bIsCollide(segment, MySnake.Body[0]))
			{
				if (segment != MySnake.Body[0])// if it is not a head itself
				{
					std::cout << "You are dead!" << std::endl;
					// TODO finish after ceating game over window
				}
			}
		}
		//Check collision with the food & change size & points after that
		if (bIsCollide(NewFood->Body, MySnake.Body[0]))
		{
			hud.UpdateScores(NewFood->GetValue());// increase scores
			MySnake.ChangeSize(1);// increase snake's size
			NewFood->SetStatus(EFoodStatus::Disappear);// hide food object
			// create random coordinates
			int32 NewX_pos = rand() % MAIN_WINDOW_WIDTH;
			int32 NewY_pos = rand() % MAIN_WINDOW_HIGHT;

			NewFood->UpdateCoordinates(NewX_pos, NewY_pos);// set new coordinates
			NewFood->SetStatus(EFoodStatus::Appear);// show
		}
		// ***END OF COLLISION DENECTION PART***

		GameWindow.clear();// Clear the display
	}
	return 0;
}
