/*
	This class create food instances which is the target to Snake in the game.
	It change snake's size, increase or decrease dependes on Value of the food.
*/

#pragma once
#include "Block.h"

enum class EFoodStatus
{
	Appear,
	Disappear
};

class Food
{
public:

	Food(int x, int y, float XScale, float YScale, int NewValue, float NewLifeTime);
	~Food();

	int GetValue() const;
	float GetLifeTime() const;
	EFoodStatus GetStatus() const;
	Block* Body;// pointer for food sprite

	void SetValue(int);// value for the snake +increase/-decrease points or segments
	void SetLifeTime(float);
	void SetStatus(EFoodStatus);

	void UpdateCoordinates(int, int);
	void Animation();

private:
	int Value;// nutrition value can be negative and positive. Impact for snake's size change.
	EFoodStatus Status;// defind is the food exist or not on the map
	float LifeTime;// lifetime in seconds when food will exists on the maps

	
};

