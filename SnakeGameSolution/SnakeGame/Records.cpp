#include "stdafx.h"
#include "Records.h"
#include <fstream>


Records::Records()
{
	bIsItNewOwnRecord = false;
	ReadFromFile();
	InputForm();
}


Records::~Records()
{
}

// predicate to compare players scores in the PlayerScoresTable
bool UnPred(std::pair<std::string, int> one, std::pair<std::string, int> two)
{
	if (one.second > two.second) return true;
	return false;
}

PlayerTable Records::ReadFromFile()
{
	// clear table before reading the file
	PlayerScoreTable.clear();
	// open records file
	Fstream = new std::fstream("../img/records.txt", std::ios::in);
	if (!Fstream->is_open())
	{
		std::cout << "Cannot open players records table storage file!";
	}
	std::string PlayerInfo = "";// for all symbols string
	std::string PlayerName = "";// for player name
	char Delimeter = '*'; // delimeter to find player's name
	std::string PlayerScores = "";
	// get all info(place, name, scores)
	while(!Fstream->eof())
	{
		getline(*Fstream, PlayerInfo);// get all info about player
		if (PlayerInfo != "")
		{
			// get player name
			size_t StartPos = PlayerInfo.find_first_of(Delimeter) + 1;
			size_t EndPos = PlayerInfo.find_last_of(Delimeter);
			PlayerName = PlayerInfo.substr(StartPos, EndPos - StartPos);
			// get player scores
			PlayerInfo = PlayerInfo.substr(EndPos);// skip player name
			size_t NotScores = PlayerInfo.find_last_not_of("0123456789");
			PlayerScores = PlayerInfo.substr(NotScores + 1);
			// write results to the PlayerScoreTable
			PlayerScoreTable.push_back(std::make_pair(PlayerName, std::stoi(PlayerScores)));
		}
	}
	Fstream->close();
	return PlayerScoreTable;
}

// add new player in the table if it is not exist
void Records::SetNewPlayer()
{// get new player name
	std::string NewPlayerName = PlayerName->GetText().getString();
	// check if the current player in the Table
	bool IsPlayerintable = false;
	for (auto player : PlayerScoreTable)
	{
		if (player.first == NewPlayerName)
		{
			IsPlayerintable = true;
			break;
		}
	}
	// if player not in the table -> add to the table
	if (!IsPlayerintable)
	{// if not in the table
		PlayerScoreTable.push_back(std::make_pair(NewPlayerName, 0));
	}
}

PlayerTable Records::GetTable() const
{
	return PlayerScoreTable;
}

Block * Records::GetNameInputForm() const
{
	return NameInputForm;
}

// write new player records
bool Records::bSetNewRecord(int NewScores)
{// get player name
	std::string NewPlayerName = PlayerName->GetText().getString();
	for (auto &player : PlayerScoreTable)// NOTE!!! Here use access by-reference
	{// if current player in score table
		if (player.first == NewPlayerName)
		{// and last player scores < current scores
			if (player.second < NewScores)
			{// save new record
				player.second = NewScores;
				return true;
			}
		}
	}
	return false;
}

void Records::WriteToFile()
{
	// sort players by scores before writing in the file
	PlayerTable Table = PlayerScoreTable;
	std::stable_sort(Table.begin(), Table.end(), UnPred);
	// open records file
	Fstream = new std::fstream("../img/records.txt", std::ios::out | std::ios::trunc);
	if (!Fstream->is_open())
	{
		std::cout << "Cannot open players records table storage file!";
	}
	int FirstPlace = 1;// for the first place write 1
	for (auto player : Table)
	{
		*Fstream << FirstPlace << ". *";// write player's position in the table & delimeter
		*Fstream << player.first << "*";// write player name
		for (size_t i = 20; i > (player.first.length() + std::to_string(player.second).length()); i--)
		{// write spaces between name & scores
			*Fstream << '_';
		}
		*Fstream << player.second << std::endl;// write scores
		FirstPlace++;// next place in the table
	}	
	Fstream->close();
}

void Records::InputForm()
{
	NameInputForm = new Block ("Star", 200, 170, 0.5f, 0.1f);
	// changes dynamically in the StartDisplay.cpp file throught player input
	PlayerName = new GameText("", 300, 175, 60);
}
