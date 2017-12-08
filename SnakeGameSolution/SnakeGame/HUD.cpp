#include "stdafx.h"
#include "HUD.h"

// variant to create info about Player and his scores in the game
HUD::HUD(std::string NewPlayerName, int32 StartScores, int32 FontSize)
{	
	// create current player name info line on x =5, y = 5 position
	Create(MainText, Arial, FontLocation, NewPlayerName, 40, 40, FontSize);
	// create start Scores info line on x = main_window_w - 70, y = 5 position
	Create(Scores, Arial, FontLocation,std::to_string(StartScores),\
			MAIN_WINDOW_WIDTH - 85, 40, FontSize);
}

// variant to create text only
HUD::HUD(std::string Message, int32 X_pos, int32 Y_pos, int32 FontSize)
{
	// create message to display
	Create(MainText, Arial, FontLocation, Message, X_pos, Y_pos, FontSize);
}


HUD::~HUD()
{
}

// Getters
sf::Text HUD::GetText() const
{
	return MainText;
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
					 std::string TextValue, float X_pos, float Y_pos, int32 FontSize)
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
