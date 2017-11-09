/*
	This class create HUD, contain the Player name, Points, Game time & Other helpful info.
*/


#pragma once
#include "Block.h"

class HUD
{
public:
	HUD(std::string NewPlayerName, int32 StartPoints);
	~HUD();

	void Create();
	Block* Display;
private:
	std::string PlayerName;
	int32 PointsCounter;
};

