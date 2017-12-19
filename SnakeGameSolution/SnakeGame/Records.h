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

	GameText* PlayerName;

	PlayerTable GetTable() const;
	Block* GetNameInputForm() const;
	PlayerTable ReadFromFile();
	bool bSetNewRecord(int);
	void SetNewPlayer();
	void WriteToFile();
	
private:
	PlayerTable PlayerScoreTable;
	std::fstream* Fstream;
	bool bIsItNewOwnRecord;
	// contain form to show player name input form before the each game
	Block* NameInputForm;
	
	void InputForm();// create input form
};

