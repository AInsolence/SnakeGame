#pragma once

#include <vector>
#include <random>

#include "Records.h"
#include "stdafx.h"
#include "Game.h"
#include "GameText.h"
#include "Level.h"
#include "Snake.h"
#include "KeyListener.h"
#include "Food.h"
#include "bIsObjectsCollide.h"

// constructor
Game::Game(sf::RenderWindow &window, std::string 
	PlayerName) : GameWindow (window)// link to the main window
{
	CurrentPlayerName = PlayerName;
}

// destructor
Game::~Game()
{
}

// Methods

// create all game's objects and handlers, start a game loop
int Game::Run(Records &InputNameForm)
{
	// ***Initialization of the game objects are used in the game loop***
	// Create game field background
	auto GameBackground = std::make_shared<Block>("SolarBackground", 0, 0, 0.7f, 0.7f);
	auto Level01 = std::make_shared<Level>(0.1f, 0.1f);//Create the level
	std::string PlayerName = InputNameForm.PlayerName->GetText().getString();
	auto NewPlayerHUD = std::make_shared<GameText>(PlayerName ,0, 45);//Create the HUD
	auto MySnake = std::make_shared<Snake>("Red", 42, 42, 0.2f, 0.2f);//Create the Snake
	//Create the player's input handler
	auto Klistner = std::make_shared<KeyListener>(GameWindow);
	// Create the food
	auto NewFood = std::make_shared<Food>(600, 500, 0.15f, 0.15f, 10, 20);
	bIsObjectsCollide bIsCollide;//Create collision detection functor
	bool IsGameOver = false;
	// Create 'Pause' title
	auto Pause = std::make_shared<GameText>("PAUSE", MAIN_WINDOW_WIDTH / 3, MAIN_WINDOW_WIDTH / 6, 170);
	bool IsGamePaused = false;
	StartGameMusic();
	
	// ***Start main game loop***
	while (GameWindow.isOpen())
	{
		MySnake->Move();// Start Snake movement
		// set game speed through players scores
		GameWindow.setFramerateLimit(MySnake->GetSpeed());
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
			GameWindow.draw(NewFood->GetBody()->MainSprite);
			NewFood->Animation();
		}
		//HUD render
		GameWindow.draw(NewPlayerHUD->GetText());// display Player name
		GameWindow.draw(NewPlayerHUD->GetScores());// display Scores
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
			GameOver(NewPlayerHUD.get(), InputNameForm);
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
		//Check collision with the food & change size, speed & points
		if (bIsCollide(NewFood->GetBody(), MySnake->Body[0]))
		{
			NewPlayerHUD->UpdateScores(NewFood->GetValue());// increase scores
			// increase snake's speed depending on the scores
			std::string CurrentScores = NewPlayerHUD->GetScores().getString();
			if (std::stoi(CurrentScores) % 100 == 0)
			{
				MySnake->UpdateSpeed(1);
			}
			MySnake->ChangeSize(1);// increase snake's size
			NewFood->SetStatus(EFoodStatus::Disappear);// hide food object
			// create random coordinates
			float NewX_pos = rand() % (MAIN_WINDOW_WIDTH - 84);
			float NewY_pos = rand() % (MAIN_WINDOW_HIGHT - 84);
			if (NewX_pos < 42) NewX_pos = 42;
			if (NewY_pos < 42) NewY_pos = 42;

			NewFood->UpdateCoordinates(NewX_pos, NewY_pos);// set new coordinates
			NewFood->SetStatus(EFoodStatus::Appear);// show
		}
		// ***END OF COLLISION DENECTION PART***
		Klistner->Start(MySnake.get(), IsGamePaused);//handle player input
		GameWindow.clear();// Clear the display
	}
	return 0;
}

// show player all information about he's achievements after the game is over
void Game::GameOver(GameText * hud, Records & InputNameForm)
{
	// Create 'Game Over' title
	GameText* GameOver = new GameText("GAME OVER!", MAIN_WINDOW_WIDTH/5, MAIN_WINDOW_WIDTH/6, 170);

	GameMusic.stop();
	// check is the current scores a new record for this player
	std::string NewScores = hud->GetScores().getString();
	if (InputNameForm.bSetNewRecord(std::stoi(NewScores)))
	{
		GameText* NewOwnRecord = new GameText("**It is your own record!!!**", \
			MAIN_WINDOW_WIDTH / 5, MAIN_WINDOW_WIDTH / 4, 100);
		GameWindow.draw(NewOwnRecord->GetText());
	}
	ShowCurrentPosition(InputNameForm);// show the position in score table
	GameWindow.draw(GameOver->GetText());
	GameWindow.display();// display 'Game over' window
	sf::sleep(sf::seconds(3));// pause before goto main menu
}

void Game::ShowCurrentPosition(Records & InputNameForm) const
{
	InputNameForm.WriteToFile();// write results in the score table
	InputNameForm.ReadFromFile();// read updated score table to show player
	int Start = 0;// player's place in the records table
	for (auto player : InputNameForm.GetTable())
	{
		Start++;// increase position to check
		if (player.first == CurrentPlayerName) break;
	}
	std::string Message = "Your position in the record table is " + std::to_string(Start);
	GameText* NewPosition = new GameText(Message, MAIN_WINDOW_WIDTH / 5, MAIN_WINDOW_WIDTH / 3, 70);
	GameWindow.draw(NewPosition->GetText());
}

void Game::StartGameMusic()
{
	// create music to stream music from file
	if (!GameMusic.openFromFile("../music/game.wav")) {
		std::cout << "Main game music asset is not found! ";
	}
	GameMusic.setLoop(true);
	GameMusic.setVolume(50);
	GameMusic.play();//start to play main game theme
}
