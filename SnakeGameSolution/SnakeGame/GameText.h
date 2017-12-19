/*
	This class create text to show in the game floaterface,
	could contain the PlayerName, Scores, Game time & other helpful info.
*/


#pragma once
#include "Block.h"

class GameText
{
public:
	GameText(std::string NewPlayerName, int StartScores, float FontSize);
	GameText(std::string Message, float X_pos, float Y_pos, float FontSize);
	~GameText();

	sf::Text GetText() const;
	sf::Text GetScores() const;

	void SetScores(int);
	void UpdateScores(int);
	void SetMainText(sf::String);
	
	float Create(sf::Text & HUDLineName, sf::Font &Arial,\
					std::string TextureLocation,\
						std::string TextValue, float X_pos, float Y_pos, float FontSize);

private:
	sf::Text Mafloatext;
	sf::Text Scores;
	sf::Font Arial;
	std::string FontLocation = "../img/ARIAL.TTF";
};
