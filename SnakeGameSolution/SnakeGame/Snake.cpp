#pragma once
#include "stdafx.h"
#include "Snake.h"

//constructor
Snake::Snake(std::string SnakeColor, int32 x, int32 y, float XScale, float YScale)
{
	Reset(x, y);
	// snake's head, tail and body segments
	Body.push_back(new BorderBlock("Light", 1000, 150, XScale, YScale));
	Body.push_back(new BorderBlock("Green", 1000, 171, XScale, YScale));
	Body.push_back(new BorderBlock("Green", 1000, 171, XScale, YScale));
	Body.push_back(new BorderBlock("Green", 1000, 171, XScale, YScale));
	Body.push_back(new BorderBlock("Green", 1000, 171, XScale, YScale));
	Body.push_back(new BorderBlock("Green", 1000, 171, XScale, YScale));
	Body.push_back(new BorderBlock("Red", 1000, 192, XScale, YScale));
}

// destructor
Snake::~Snake()
{
	for (auto segment : Body)
	{
		delete segment;
	}
}

// Getters

int32 Snake::GetSpeed() const
{
	return Speed;
}

int32 Snake::GetSize() const
{
	return Size;
}

ESnakeState Snake::GetCurrentState() const
{
	return CurrentState;
}

ESnakeCurrentDirection Snake::GetCurrentDirection() const
{
	return CurrentDirection;
}

// Setters

void Snake::SetSpeed(int32 CurrentSnakeSpeed)
{
	Speed = CurrentSnakeSpeed;
	return;
}

void Snake::SetSize(int32 NewSnakeSize)
{
	Size = NewSnakeSize;
	return;
}

void Snake::SetCurrentDirection(ESnakeCurrentDirection NewDirection)
{
	CurrentDirection = NewDirection;
}

// Methods

void Snake::Reset(int32 &XStartPosition, int32 &YStartPosition)
{
	// snake LIVE STATUS in the beginning of the game
	ESnakeState CurrentState = ESnakeState::Alive;

	// snake starting DIRECTION is left
	ESnakeCurrentDirection CurrentDirection = ESnakeCurrentDirection::Right;

	// set snake SPEED in the beginning of the game
	constexpr int32 START_SNAKE_SPEED = 1;
	SetSpeed(START_SNAKE_SPEED);

	// set snake SIZE in the beginning of the game
	constexpr int32 START_SNAKE_SIZE = 1;
	SetSize(START_SNAKE_SIZE);
}

void Snake::IncreaseSize(int32 AdditionToCurrentSize)
{
	for (int32 NewSegments = 0; NewSegments < AdditionToCurrentSize; NewSegments++)
	{
		
		// TODO change to real coordinates here depending on movement direction
	}
}

void Snake::Move()
{
	float tmpX = Body[0]->MainSprite.getPosition().x;
	float tmpY = Body[0]->MainSprite.getPosition().y;
	
	// change head coordinates depends on current direction
	switch (CurrentDirection)// TODO add changing of snake's  head tile  
	{
	case ESnakeCurrentDirection::Left:
		Body[0]->MainSprite.move(-20, 0);// TODO Change to step const var
		break;
	case ESnakeCurrentDirection::Right:
		Body[0]->MainSprite.move(20, 0);
		break;
	case ESnakeCurrentDirection::Up:
		Body[0]->MainSprite.move(0, -20);
	break;
		case ESnakeCurrentDirection::Down:
		Body[0]->MainSprite.move(0, 20);
		break;
	default:
		break;
	}

	
	for (size_t i = Body.size() - 1; i > 0; i--)
	{
		float XFactor = 0;
		float YFactor = 0;
		Body[i]->MainSprite.setPosition(Body[i - 1]->MainSprite.getPosition().x + XFactor, Body[i - 1]->MainSprite.getPosition().y + YFactor);
	}
	Body[1]->MainSprite.setPosition(tmpX, tmpY);
	//std::rotate(Body.rbegin() + 1, Body.rbegin() + 2, Body.rend());
}
