/*
This is a base class for the game objects.
Contains data and methods are needed to interact with objects.
*/

#pragma once
#include <vector>

using int32 = int;
using FPair = std::pair<int32, int32>;
using FVector = std::vector<char>;
using FField = std::vector< std::vector<char> >;

class IGameObject
{
public:
	IGameObject();
	virtual ~IGameObject();

	//virtual void Display() = 0;// TODO make decision about this

	static FField Canvas;// matrix (vector of vectors) to display all objects in console
};
