/*
	This class create HUD, could contain the Player name, Scores, 
	Game time & Other helpful info.
*/


#pragma once
#include "Block.h"

class HUD
{
public:
	HUD(std::string NewPlayerName, int32 StartScores, int32 FontSize);
	HUD(std::string Message, int32 X_pos, int32 Y_pos, int32 FontSize);
	~HUD();

	sf::Text GetText() const;
	sf::Text GetScores() const;

	void SetScores(int32);
	void UpdateScores(int32);

	int32 Create(sf::Text & HUDLineName, sf::Font &Arial,\
					std::string TextureLocation,\
						std::string TextValue, float X_pos, float Y_pos, int32 FontSize);

private:
	sf::Text MainText;
	sf::Text Scores;
	sf::Font Arial;
	std::string FontLocation = "../../img/ARIAL.TTF";
};

