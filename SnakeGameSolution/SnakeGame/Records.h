#pragma once
#include "Block.h"
#include "HUD.h"

using PlayerTable = std::map<std::string, int32>;

class Records
{
public:
	Records();
	~Records();

	PlayerTable ReadFromFile();
	void SetNewPlayer();
	void WriteToFile(std::vector<std::pair<std::string, int32>>);
	int32 InputForm();
	Block* NameInputForm;
	HUD* PlayerName;

private:
	PlayerTable PlayerScoreTable;
	std::fstream* Fstream;
};

