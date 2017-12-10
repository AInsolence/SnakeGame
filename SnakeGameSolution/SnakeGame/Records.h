#pragma once

using PlayerTable = std::map<std::string, int32>;

class Records
{
public:
	Records();
	~Records();

	PlayerTable ReadFromFile();
	void WriteToFile(std::vector<std::pair<std::string, int32>>);

private:
	PlayerTable PlayerScoreTable;
	std::fstream* Fstream;
};

