#pragma once
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

EFoodStatus Food::GetStatus() const
{
	return Status;
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

void Food::SetStatus(EFoodStatus NewStatus)
{
	Status = NewStatus;
	return;
}

void Food::UpdateCoordinates(int32 x, int32 y)
{
	Body->MainSprite.setPosition(x, y);
	return;
}

// animate the food through changing sprites scale up and down
void Food::Animation()
{
	int32 MAX_FRAMES = 10;
	int32 PERCENT_TO_CHANGE_SCALE = 40;
	static float counter = 0;// how much frames will be, started from 0
	static bool Grow = true;

	if (Grow)
	{// starting to increase scale of the food body
		Body->MainSprite.setScale(Body->MainSprite.getScale().x + Body->MainSprite.getScale().x/ PERCENT_TO_CHANGE_SCALE, \
			Body->MainSprite.getScale().y + Body->MainSprite.getScale().y/ PERCENT_TO_CHANGE_SCALE);
		counter++;
	}
	
	if (!Grow)
	{// starting to decrease scale of the food body		
		Body->MainSprite.setScale(\
			Body->MainSprite.getScale().x - Body->MainSprite.getScale().x / PERCENT_TO_CHANGE_SCALE, \
			Body->MainSprite.getScale().y - Body->MainSprite.getScale().y / PERCENT_TO_CHANGE_SCALE);
		counter--;
	}

	if (counter == MAX_FRAMES) Grow = false;// if the body is approach max size -> start to decrease
	if (!counter) Grow = true;// if the body is approach min size -> start to increase
}
