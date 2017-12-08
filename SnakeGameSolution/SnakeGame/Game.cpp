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
	MainText = PlayerName;
}

// destructor
Game::~Game()
{
}

// Methods

// create all game's objects and handlers, start a game loop
int32 Game::Run()
{
	// ***Initialization of the game objects are used in the game loop***
	// Create game field background
	Block* GameBackground = new Block("SolarBackground", 0, 0, 0.7f, 0.7f);
	Level* Level01 = new Level(0.1f, 0.1f);//Create the level
	HUD* hud = new HUD("Player", 0, 45);//Create the HUD
	Snake* MySnake = new Snake("Red", 200, 200, 0.1f, 0.1f);//Create the Snake
	KeyListener* Klistner = new KeyListener(GameWindow);//Create the player's input handler
	// Create the food
	Food* NewFood = new Food(600, 500, 0.15f, 0.15f, 10, 20);// TODO make real rand for x, y
	bIsObjectsCollide bIsCollide;//Create collision detection functor
	// Create 'Game Over' title
	HUD* GameOver = new HUD("GAME OVER!", MAIN_WINDOW_WIDTH / 5, MAIN_WINDOW_WIDTH / 6, 170);
	bool IsGameOver = false;
	// Create 'Pause' title
	HUD* Pause = new HUD("PAUSE", MAIN_WINDOW_WIDTH / 3, MAIN_WINDOW_WIDTH / 6, 170);
	bool IsGamePaused = false;

	//Game music and sounds
	sf::Music GameMusic;// create music to stream music from file
	if (!GameMusic.openFromFile("../../music/game.wav")) {
		std::cout << "Main game music asset is not found! ";
		//return EXIT_FAILURE;
	}
	GameMusic.setLoop(true);
	GameMusic.setVolume(50);
	GameMusic.play();//start to play main game theme
	
	// ***Start main game loop***
	while (GameWindow.isOpen())
	{		
		Klistner->Start(MySnake, IsGamePaused);// start handle player input

		MySnake->Move();// Start Snake movement

		GameWindow.setFramerateLimit(5);

		// ***RENDERING PART OF THE GAME LOOP***
		// Background render
		GameWindow.draw(GameBackground->MainSprite);
		// Level render
		for (auto block : Level01->GetMainBorder())
		{
			GameWindow.draw(block->MainSprite);
		}
		// Snake render
		for (auto segment : MySnake->Body)
		{
			GameWindow.draw(segment->MainSprite);
		}
		// Food render
		if (NewFood->GetStatus() == EFoodStatus::Appear)
		{
			GameWindow.draw(NewFood->Body->MainSprite);
			NewFood->Animation();
		}
		//HUD render
		GameWindow.draw(hud->GetText());// display Player name
		GameWindow.draw(hud->GetScores());// display Scores
		//Pause logic & render
		if (IsGamePaused && !IsGameOver)
		{
			MySnake->bIsMove = false;
			GameWindow.draw(Pause->GetText());
			GameMusic.setVolume(0);
		}
		else
		{
			MySnake->bIsMove = true;
			if (GameMusic.getVolume() == 0)	GameMusic.setVolume(50);
		}
		//Game Over logic & render
		if (IsGameOver)
		{
			GameWindow.draw(GameOver->GetText());
			GameWindow.display();//Display 'Game over' window
			sf::sleep(sf::seconds(3));
			return 0;
		}
		// ***END OF RENDERING PART***

		GameWindow.display();//Display window and all game elements

		// ***COLLISION DETECTION PART OF THE GAME LOOP***
		// Check collision snake with it's own segments
		for (auto segment : MySnake->Body)
		{
			if (bIsCollide(segment, MySnake->Body[0]))
			{
				if (segment != MySnake->Body[0])// if it is not a head itself
				{
					MySnake->bIsMove = false;
					IsGameOver = true;
				}
			}
		}
		//Check collision with walls
		for (auto block : Level01->GetMainBorder())
		{
			if (bIsCollide(block, MySnake->Body[0]))
			{
				MySnake->bIsMove = false;
				IsGameOver = true;
			}
		}
		//Check collision with the food & change size & points after that
		if (bIsCollide(NewFood->Body, MySnake->Body[0]))
		{
			hud->UpdateScores(NewFood->GetValue());// increase scores
			MySnake->ChangeSize(1);// increase snake's size
			NewFood->SetStatus(EFoodStatus::Disappear);// hide food object
			// create random coordinates
			int32 NewX_pos = rand() % (MAIN_WINDOW_WIDTH - 84);
			int32 NewY_pos = rand() % (MAIN_WINDOW_HIGHT - 84);
			if (NewX_pos < 42) NewX_pos = 42;
			if (NewY_pos < 42) NewY_pos = 42;

			NewFood->UpdateCoordinates(NewX_pos, NewY_pos);// set new coordinates
			NewFood->SetStatus(EFoodStatus::Appear);// show
		}
		// ***END OF COLLISION DENECTION PART***

		GameWindow.clear();// Clear the display
	}
	return 0;
}
