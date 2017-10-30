#pragma once
#include "stdafx.h"
#include "Snake.h"

//constructor
Snake::Snake(int32 XStartPosition, int32 YStartPosition)
	:HeadTexture('0'), BodyTexture('@'), TailTexture('.')// set snake's textures
{
	Reset(XStartPosition, YStartPosition);
}

// destructor
Snake::~Snake()
{
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
	return;
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

	// snake START POSITION 
	Body.push_back(std::make_pair(XStartPosition, YStartPosition));
}

void Snake::IncreaseSize(int32 AdditionToCurrentSize)
{
	for (int32 NewSegments = 0; NewSegments < AdditionToCurrentSize; NewSegments++)
	{
		FPair LastSegment = Body.back();
		Body.push_back(LastSegment);// TODO change to real coordinates here depending on movement direction
	}
}

void Snake::Move()
{
		Display();

		if (Body.size() > 1)// if body has NOT only head segment
		{
			// shift coordinates of all segments to right
			std::rotate(Body.rbegin(), Body.rbegin(), Body.rend());
		}

		// change head coordinates depends on current direction
		switch (CurrentDirection)// TODO add changing of snake's  head tile  
		{
		case ESnakeCurrentDirection::Left:
			Body[0].first -= 1;
			break;
		case ESnakeCurrentDirection::Right:
			Body[0].first += 1;
			break;
		case ESnakeCurrentDirection::Up:
			Body[0].second -= 1;
			break;
		case ESnakeCurrentDirection::Down:
			Body[0].second += 1;
			break;
		default:
			break;
		}
}

void Snake::Display() const
{
	Canvas[Body.front().second][Body.front().first] = HeadTexture;// paint snake's head
	if (Body.size() > 1)
	{
		Canvas[Body.back().second][Body.back().first] = TailTexture;// paint snake's tail
		// paint snake's body, except first and last elements (head and tail)
		for (int32 index = 1; index != Body.size() - 1; index++)
		{
			Canvas[Body[index].second][Body[index].first] = BodyTexture;
		}
	}
}

