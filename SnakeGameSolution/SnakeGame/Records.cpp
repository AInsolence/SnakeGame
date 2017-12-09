#include "stdafx.h"
#include "Records.h"
#include <fstream>


Records::Records()
{
}


Records::~Records()
{
}

PlayerTable Records::ReadFromFile() const
{
	Fstream.open("records.txt");
	return PlayerTable();
}

void Records::WriteToFile(std::map<std::string, int32>)
{
}
