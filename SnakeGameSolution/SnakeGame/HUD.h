/*
	This class create HUD, could contain the Player name, Scores, 
	Game time & Other helpful info.
*/


#pragma once
#include "Block.h"

class HUD
{
public:
	HUD(std::string NewPlayerName, int32 StartScores);
	~HUD();

	sf::Text GetPlayerName() const;
	sf::Text GetScores() const;

	void SetScores(int32);
	void UpdateScores(int32);

	int32 Create(sf::Text & HUDLineName, sf::Font &Arial,\
		std::string TextureLocation, std::string TextValue,\
		int32 X_pos, int32 Y_pos);

private:
	sf::Text Player;
	sf::Text Scores;
	sf::Font Arial;
	std::string FontLocation = "../../image/ARIAL.TTF";
};

