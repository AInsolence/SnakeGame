#include "stdafx.h"
#include "Records.h"
#include <fstream>


Records::Records()
{
	std::vector<std::pair<std::string, int32>> TestMap{
		{"Anton", 2300},
		{"Marina", 2800},
		{"Roma", 2800},
		{"Elina", 3200}
	};

	ReadFromFile();
	WriteToFile(TestMap);
	
}


Records::~Records()
{
}

PlayerTable Records::ReadFromFile()
{
	// open records file
	Fstream = new std::fstream("../../records.txt", std::ios::in);
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
		getline(*Fstream, PlayerInfo);
		if (PlayerInfo != "")
		{
			// get player name
			size_t StartPos = PlayerInfo.find_first_of(Delimeter) + 1;
			size_t EndPos = PlayerInfo.find_last_of(Delimeter);
			PlayerName = PlayerInfo.substr(StartPos, EndPos - StartPos);
			// get player scores
			size_t NotScores = PlayerInfo.find_last_not_of("0123456789");
			PlayerScores = PlayerInfo.substr(NotScores + 1);
			// write results to the PlayerScoreTable
			PlayerScoreTable[PlayerName] = std::stoi(PlayerScores);
		}
	}
	Fstream->close();
	return PlayerTable();
}

// predicate to compare players scores in the PlayerScoresTable
bool UnPred(std::pair<std::string, int32> one, std::pair<std::string, int32> two)
{
	if (one.second > two.second) return true;
	return false;
}

void Records::WriteToFile(std::vector<std::pair<std::string, int32>> Table)
{
	// sort players by scores before writing in the file
	std::stable_sort(Table.begin(), Table.end(), UnPred);
	// open records file
	Fstream = new std::fstream("../../records.txt", std::ios::out | std::ios::trunc);
	if (!Fstream->is_open())
	{
		std::cout << "Cannot open players records table storage file!";
	}
	int32 FirstPlace = 1;// for the first place write 1
	for (auto player : Table)
	{
		*Fstream << FirstPlace << ". *";// write player's position in the table & delimeter
		*Fstream << player.first << "*";// write player name
		for (int32 i = 20; i > (player.first.length() + std::to_string(player.second).length()); i--)
		{// write spaces between name & scores
			*Fstream << '_';
		}
		*Fstream << player.second << std::endl;// write scores
		FirstPlace++;// next place in the table
	}	
	Fstream->close();
}
