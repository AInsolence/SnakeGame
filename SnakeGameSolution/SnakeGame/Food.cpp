#include "stdafx.h"
#include "Food.h"

//constructor
// x&y is the coordinates of appearing on the map
Food::Food(int32 x, int32 y, float XScale, float YScale, int32 NewValue, float NewLifeTime)
{
	Body = new Block("Blue", x, y, XScale, YScale);
	Value = NewValue;
	LifeTime = NewLifeTime;
	Status = EFoodStatus::Appear;
}

//destructor
Food::~Food()
{
}

//Getters
int32 Food::GetValue() const
{
	return Value;
}

float Food::GetLifeTime() const
{
	return LifeTime;
}

//Setters
void Food::SetValue(int32 NewValue)
{
	Value = NewValue;
	return;
}

void Food::SetLifeTime(float NewTime)
{
	LifeTime = NewTime;
	return;
}
