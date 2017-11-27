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

	Food(int32 x, int32 y, float XScale, float YScale, int32 NewValue, float NewLifeTime);
	~Food();

	int32 GetValue() const;
	float GetLifeTime() const;
	EFoodStatus GetStatus() const;
	Block* Body;// pointer for food sprite

	void SetValue(int32);
	void SetLifeTime(float);
	void SetStatus(EFoodStatus);

	void UpdateCoordinates(int32, int32);
	void Animation();

private:
	int32 Value;// nutrition value can be negative and positive. Impact for snake's size change.
	EFoodStatus Status;// defind is the food exist or not on the map
	float LifeTime;// lifetime in seconds when food will exists on the maps

	
};

