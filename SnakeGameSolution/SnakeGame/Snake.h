#pragma once
#include "stdafx.h"
#include <vector>
#include "BorderBlock.h"

using FTuple = std::tuple<sf::Sprite, int32, int32>;

enum class ESnakeState// current status of the Snake object
{
	Alive,
	Dead
};

enum class ESnakeCurrentDirection// movement direction of the snake object
{
	Right,
	Left,
	Up,
	Down
};

class Snake
{
public:
	Snake(std::string SnakeColor, int32 x, int32 y, float XScale, float YScale);
	~Snake();

	std::vector<BorderBlock*> Body;// container to store snake head & snake segments

	int32 GetSpeed() const;
	int32 GetSize() const;
	ESnakeState GetCurrentState() const;
	ESnakeCurrentDirection GetCurrentDirection() const;

	void Reset(int32 &XStartPosition, int32 &YStartPosition);
	void SetSpeed(int32);
	void SetSize(int32);
	void SetCurrentDirection(ESnakeCurrentDirection);
	void IncreaseSize(int32);
	void Move();

	
private:
	// initialized in the reset function called in the constructor
	int32 Speed;
	int32 Size;
	ESnakeState CurrentState;
	ESnakeCurrentDirection CurrentDirection;
};

