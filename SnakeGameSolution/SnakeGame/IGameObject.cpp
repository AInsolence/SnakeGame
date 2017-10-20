#pragma once
#include "stdafx.h"
#include "IGameObject.h"

IGameObject::IGameObject(int x, int y)// initialized with object start coordinates
{
	Coordinates.first = x;
	Coordinates.second = y;
}

IGameObject::~IGameObject()
{
}

FPair IGameObject::GetCoordinates()
{
	return Coordinates;
}

void IGameObject::SetCoordinates(int32 x, int32 y)
{
	Coordinates.first = x;
	Coordinates.second = y;
}
