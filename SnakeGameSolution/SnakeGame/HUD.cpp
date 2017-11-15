#include "stdafx.h"
#include "HUD.h"


HUD::HUD(std::string NewPlayerName, int32 StartScores)
{	
	// create current player name info line on x =5, y = 5 position
	Create(Player, Arial, FontLocation, NewPlayerName, 5, 5);
	// create start Scores info line on x = main_window_w - 70, y = 5 position
	Create(Scores, Arial, FontLocation,std::to_string(StartScores),\
			MAIN_WINDOW_WIDTH - 70, 5);
}


HUD::~HUD()
{
}

// Getters
sf::Text HUD::GetPlayerName() const
{
	return Player;
}

sf::Text HUD::GetScores() const
{
	return Scores;
}

// Setters
void HUD::SetScores(int32 NewScores)
{
	// cast integer to string and set a new scores value
	Scores.setString(std::to_string(NewScores));
	return;
}

// Methods

// increase or decrease player's scores depending on increment parameter
void HUD::UpdateScores(int32 Increment)
{
	long double NewScores;
	std::string  OldScore = Scores.getString();// get the current scores
	std::cout << OldScore << std::endl;
	// cast to an integer and add increment
	NewScores = (std::stoi(OldScore)) + Increment;
	
	SetScores(NewScores);// set a new value of the scores
}

// create the HUD info line
int32 HUD::Create(sf::Text & HUDLineName, sf::Font &Arial,\
					std::string FontLocation,\
					 std::string TextValue, float X_pos, float Y_pos)
{
	if (!Arial.loadFromFile(FontLocation))// load font from file
	{
		return EXIT_FAILURE;
	}

	HUDLineName.setString(TextValue);
	HUDLineName.setFont(Arial);
	HUDLineName.setFillColor(White);
	HUDLineName.setCharacterSize(20);
	HUDLineName.setPosition(X_pos, Y_pos);

	return 0;
}
