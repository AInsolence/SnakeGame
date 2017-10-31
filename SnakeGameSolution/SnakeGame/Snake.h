#pragma once
#include "stdafx.h"
#include <vector>
#include "IGameObject.h"

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

class Snake : public IGameObject
{
public:
	Snake(std::string SnakeColor, int32 x, int32 y);
	~Snake();

	std::vector<std::tuple<sf::Sprite, int32, int32>> Body;// container to store snake head & snake segments coordinates

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
	sf::Sprite HeadSprite;
	sf::Sprite TailSprite;
	int32 Speed;
	int32 Size;
	ESnakeState CurrentState;
	ESnakeCurrentDirection CurrentDirection;
};

