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
	Snake();
	~Snake();

	std::vector<FPair> SnakeBody;// container to store snake head & snake segments coordinates
	
private:
	// initialized in the constructor
	const char SnakeHeadTexture;
	const char SnakeBodyTexture;
	const char SnakeTailTexture;
};

