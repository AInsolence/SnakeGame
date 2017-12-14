/*
	This class create and store info about player, he's scores, records table,
	write/read information about records from/into the db file; 
*/

#pragma once
#include "Block.h"
#include "GameText.h"

using PlayerTable = std::vector<std::pair<std::string, int>>;

class Records
{
public:
	Records();
	~Records();

	PlayerTable GetTable() const;
	PlayerTable ReadFromFile();
	// contain form to show player name input form before the each game
	Block* NameInputForm;
	GameText* PlayerName;
	bool bIsItNewOwnRecord;

	void SetNewPlayer();
	bool bSetNewRecord(int);
	
	void WriteToFile();
	int InputForm();// create input form

private:
	PlayerTable PlayerScoreTable;
	std::fstream* Fstream;
};

