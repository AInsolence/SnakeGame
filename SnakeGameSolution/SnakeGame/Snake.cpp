#pragma once
#include "stdafx.h"
#include "Snake.h"

//constructor
Snake::Snake(std::string SnakeColor, float x, float y, float XScale, float YScale)
{
	Reset(x, y, XScale, YScale);// reset object to default parameters
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

void Snake::Reset(float &XStartPosition, float &YStartPosition, float XScale, float YScale)
{

	// create snake's head, tail and body segments // TODO move this code to Reset method
	Body.push_back(new Block("HeadUp", 42, 42, XScale, YScale));
	Body.push_back(new Block("Body", 42, 42, XScale, YScale));
	Body.push_back(new Block("Body", 42, 42, XScale, YScale));
	// snake LIVE STATUS in the beginning of the game
	ESnakeState CurrentState = ESnakeState::Alive;
	// snake move;
	bIsMove = true;
	// snake starting DIRECTION is left
	SetCurrentDirection(ESnakeCurrentDirection::Right);
	// set snake SPEED in the beginning of the game
	constexpr int32 START_SNAKE_SPEED = 1;
	SetSpeed(START_SNAKE_SPEED);
	// set snake SIZE in the beginning of the game
	constexpr int32 START_SNAKE_SIZE = 3;
	SetSize(START_SNAKE_SIZE);
}

void Snake::ChangeSize(int32 AdditionToCurrentSize)
{
	for (int32 NewSegments = 0; NewSegments < AdditionToCurrentSize; NewSegments++)
	{// add new segment with head segment scale
		Body.push_back(new Block("Body",\
			Body[0]->MainSprite.getPosition().x,\
			Body[0]->MainSprite.getPosition().y,\
			Body[0]->MainSprite.getScale().x, Body[0]->MainSprite.getScale().y));
	}
}

// move snake and it's segments through changing sprites coordinates
void Snake::Move()
{
	// steps on x and y axises depends on sprite size and scale
	float Step_x = BASE_SPRITE_SIZE * Body[0]->MainSprite.getScale().x;
	float Step_y = BASE_SPRITE_SIZE * Body[0]->MainSprite.getScale().y;

	if (bIsMove) {
		//change segments position to the next step
		for (size_t i = Body.size() - 1; i > 0; i--)
		{
			Body[i]->MainSprite.setPosition(Body[i - 1]->MainSprite.getPosition().x, \
				Body[i - 1]->MainSprite.getPosition().y);
		}
		// change head coordinates depends on current direction
		switch (CurrentDirection)// TODO add changing of snake's  head tile  
		{
		case ESnakeCurrentDirection::Left:
			Body[0]->SetTexture(Body[0]->MainSprite, "../../img/SNAKE_L.png", Body[0]->MainSprite.getScale().x,\
				Body[0]->MainSprite.getScale().y);
			Body[0]->MainSprite.move(-Step_x, 0);
			break;
		case ESnakeCurrentDirection::Right:
			Body[0]->SetTexture(Body[0]->MainSprite, "../../img/SNAKE_Rg.png", Body[0]->MainSprite.getScale().x, \
				Body[0]->MainSprite.getScale().y);
			Body[0]->MainSprite.move(Step_x, 0);
			break;
		case ESnakeCurrentDirection::Up:
			Body[0]->SetTexture(Body[0]->MainSprite, "../../img/SNAKE_U.png", Body[0]->MainSprite.getScale().x, \
				Body[0]->MainSprite.getScale().y);
			Body[0]->MainSprite.move(0, -Step_y);
			break;
		case ESnakeCurrentDirection::Down:
			Body[0]->SetTexture(Body[0]->MainSprite, "../../img/SNAKE_D.png", Body[0]->MainSprite.getScale().x, \
				Body[0]->MainSprite.getScale().y);
			Body[0]->MainSprite.move(0, Step_y);
			break;
		default:
			break;
		}
	}
}
