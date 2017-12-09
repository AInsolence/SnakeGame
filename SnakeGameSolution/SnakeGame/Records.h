#pragma once

using PlayerTable = std::vector < std::map<std::string, int32> >;

class Records
{
public:
	Records();
	~Records();

	PlayerTable ReadFromFile() const;
	void WriteToFile(std::map<std::string, int32>);

private:
	PlayerTable Buffer;
	std::fstream Fstream;
};

