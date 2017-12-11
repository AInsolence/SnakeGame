#pragma once
#include "Block.h"
#include "HUD.h"

using PlayerTable = std::vector<std::pair<std::string, int32>>;

class Records
{
public:
	Records();
	~Records();

	PlayerTable ReadFromFile();
	void SetNewPlayer();
	void SetPlayerScores(int32);
	void WriteToFile();
	int32 InputForm();
	Block* NameInputForm;
	HUD* PlayerName;

private:
	PlayerTable PlayerScoreTable;
	std::fstream* Fstream;
};

