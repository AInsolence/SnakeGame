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

	Food(float x, float y, float XScale, float YScale, int NewValue, int NewLifeTime);
	~Food();

	int GetValue() const;
	float GetLifeTime() const;
	Block* GetBody() const;
	EFoodStatus GetStatus() const;

	void SetValue(int);// value for the snake +increase/-decrease points or segments
	void SetLifeTime(int);
	void SetStatus(EFoodStatus);
	void UpdateCoordinates(float, float);
	void Animation();

private:
	float Value;// nutrition value can be negative and positive. Impact for snake's size change.
	EFoodStatus Status;// defind is the food exist or not on the map
	float LifeTime;// lifetime in seconds when food will exists on the maps
	Block* Body;// pointer for food sprite
};

