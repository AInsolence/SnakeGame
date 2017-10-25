#pragma once
#include "IGameObject.h"
#include <vector>

enum class ESnakeState
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

class Snake : public BaseGameObject
{
public:
	Snake(int32 XStartPosition, int32 YStartPosition);
	~Snake();

	std::vector<FPair> SnakeBody;// container to store snake head & snake segments coordinates
	int32 GetSnakeSpeed() const;
	void SetSnakeSpeed(int32);
	
private:
	// initialized in the constructor
	const char SnakeHeadTexture;
	const char SnakeBodyTexture;
	const char SnakeTailTexture;
	int32 SnakeSpeed;
};

