#include "stdafx.h"
#include "GameText.h"

// variant to create info about Player and his scores in the game
GameText::GameText(std::string NewPlayerName, int StartScores, int FontSize)
{	
	// create current player name info line on x =5, y = 5 position
	Create(MainText, Arial, FontLocation, NewPlayerName, 40, 40, FontSize);
	// create start Scores info line on x = main_window_w - 70, y = 5 position
	Create(Scores, Arial, FontLocation,std::to_string(StartScores),\
			MAIN_WINDOW_WIDTH - 85, 40, FontSize);
}

// variant to create text only
GameText::GameText(std::string Message, int X_pos, int Y_pos, int FontSize)
{
	// create message to display
	Create(MainText, Arial, FontLocation, Message, X_pos, Y_pos, FontSize);
}


GameText::~GameText()
{
}

// Getters
sf::Text GameText::GetText() const
{
	return MainText;
}

sf::Text GameText::GetScores() const
{
	return Scores;
}

// Setters
void GameText::SetScores(int NewScores)
{
	// cast integer to string and set a new scores value
	Scores.setString(std::to_string(NewScores));
	return;
}

void GameText::SetMainText(sf::String NewText)
{
	MainText.setString(NewText);
}

// Methods

// increase or decrease player's scores depending on increment parameter
void GameText::UpdateScores(int Increment)
{
	long double NewScores;
	std::string  OldScore = Scores.getString();// get the current scores
	// cast to an integer and add increment
	NewScores = (std::stoi(OldScore)) + Increment;
	
	SetScores(NewScores);// set a new value of the scores
}

// create the HUD info line
int GameText::Create(sf::Text & HUDLineName, sf::Font &Arial,\
					std::string FontLocation,\
					 std::string TextValue, float X_pos, float Y_pos, int FontSize)
{
	if (!Arial.loadFromFile(FontLocation))// load font from file
	{
		return EXIT_FAILURE;
	}

	HUDLineName.setString(TextValue);
	HUDLineName.setFont(Arial);
	HUDLineName.setStyle(sf::Text::Bold);
	HUDLineName.setFillColor(Black);
	HUDLineName.setCharacterSize(FontSize);
	HUDLineName.setPosition(X_pos, Y_pos);

	return 0;
}
