#pragma once
#include "stdafx.h"
#include "IGameObject.h"

//constructors
IGameObject::IGameObject()// by default coordinates are initialized with 0
{
	Coordinates.first = 0;
	Coordinates.second = 0;
}

IGameObject::IGameObject(int x, int y)// initialized with object start coordinates
{
	Coordinates.first = x;
	Coordinates.second = y;
}

//destructor
IGameObject::~IGameObject()
{
}

//Getters
FPair IGameObject::GetCoordinates() const
{
	return Coordinates;
}

//Setters
void IGameObject::SetCoordinates(int32 x, int32 y)
{
	Coordinates.first = x;
	Coordinates.second = y;
}
