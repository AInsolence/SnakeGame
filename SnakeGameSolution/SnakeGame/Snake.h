/*
	Snake class provide all structures to create main game object Snake.
	It has two states represents here with enumerations: alive/dead & moving direction.
	Snake consists of segments(Blocks) & can increase their number after eating the food.
*/

#pragma once
#include "stdafx.h"
#include <vector>
#include "Block.h"

using FTuple = std::tuple<sf::Sprite, int, int>;

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
	Snake(std::string SnakeColor, float x, float y, float XScale, float YScale);
	~Snake();

	std::vector<Block*> Body;// container to store snake head & snake segments
	bool bIsMove;// state of the snake move or hold

	int GetSpeed() const;
	int GetSize() const;
	ESnakeState GetCurrentState() const;
	ESnakeCurrentDirection GetCurrentDirection() const;
	
	// reset the snake to the default parameters
	void Reset(float &XStartPosition, float &YStartPosition, float XScale, float YScale);
	void UpdateSpeed(int);
	void SetSize(int);
	void SetCurrentDirection(ESnakeCurrentDirection);
	void ChangeSize(int);
	void Move();

	
private:
	// initialized in the reset function called in the constructor
	int Speed;
	int Size;
	ESnakeState CurrentState;// alive or dead
	ESnakeCurrentDirection CurrentDirection;
};

