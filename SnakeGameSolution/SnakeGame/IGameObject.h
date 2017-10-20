/*
This is a base class for the game objects.
Contains data and methods are needed to interact with objects.
*/

#pragma once
#include <vector>

using int32 = int;
using FPair = std::pair<int32, int32>;

class IGameObject
{
public:
	IGameObject(int, int);
	virtual ~IGameObject();

	FPair GetCoordinates();
	void SetCoordinates(int32, int32);

private:
	char Shape;
	FPair Coordinates;// coordinates of the object <x, y> on the game field
};
