#include "stdafx.h"
#include "Snake.h"

//constructor
Snake::Snake(int32 XStartPosition, int32 YStartPosition)
	:SnakeHeadTexture('0'), SnakeBodyTexture('@'), SnakeTailTexture('.')// set snake's textures
{
	// snake is alive in the beginning of the game
	ESnakeState SnakeState = ESnakeState::Alive;
	// snake starting direction is left
	ESnakeCurrentDirection SnakeCurrentDirection = ESnakeCurrentDirection::Left;
	// set snake speed in the beginning of the game
	constexpr int32 START_SNAKE_SPEED = 1;
	SetSnakeSpeed(START_SNAKE_SPEED);
	// snake starting position
	SnakeBody.push_back(std::make_pair(XStartPosition, YStartPosition));
}

// destructor
Snake::~Snake()
{
}

// Getters

int32 Snake::GetSnakeSpeed() const
{
	return SnakeSpeed;
}

// Setters

void Snake::SetSnakeSpeed(int32 CurrentSnakeSpeed)
{
	SnakeSpeed = CurrentSnakeSpeed;
	return;
}

// Methods


