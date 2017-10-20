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
	IGameObject();
	IGameObject(int, int);
	virtual ~IGameObject();

	FPair GetCoordinates() const;
	void SetCoordinates(int32, int32);

protected:
	char MainObjectTexture;// main textre for represent object
	FPair Coordinates;// coordinates of the object <x, y> on the game field
};
