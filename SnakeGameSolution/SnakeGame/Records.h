#pragma once
#include "Block.h"
#include "HUD.h"

using PlayerTable = std::vector<std::pair<std::string, int32>>;

class Records
{
public:
	Records();
	~Records();

	PlayerTable GetTable() const;
	PlayerTable ReadFromFile();

	Block* NameInputForm;
	HUD* PlayerName;
	bool bIsItNewOwnRecord;

	void SetNewPlayer();
	bool bSetNewRecord(int32);
	
	void WriteToFile();
	int32 InputForm();

private:
	PlayerTable PlayerScoreTable;
	std::fstream* Fstream;
};

