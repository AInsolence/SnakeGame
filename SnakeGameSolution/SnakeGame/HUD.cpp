#include "stdafx.h"
#include "HUD.h"


HUD::HUD(std::string NewPlayerName, int32 StartPoints)
{
	PlayerName = NewPlayerName;
	PointsCounter = StartPoints;
	Create();
}


HUD::~HUD()
{
}

void HUD::Create()
{
	Display = new Block("Blue", 50, 550, 5.5f, 0.3f);
	sf::Text Player;

}
