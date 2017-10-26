#pragma once
#include "IGameObject.h"
#include <vector>
#include <time.h>

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
	Snake(int32 XStartPosition, int32 YStartPosition);
	~Snake();

	std::vector<FPair> Body;// container to store snake head & snake segments coordinates

	int32 GetSpeed() const;
	int32 GetSize() const;
	ESnakeState GetCurrentState() const;
	ESnakeCurrentDirection GetCurrentDirection() const;

	void Reset(int32 &XStartPosition, int32 &YStartPosition);
	void SetSpeed(int32);
	void SetSize(int32);
	void IncreaseSize(int32);
	void Move();

	
private:
	// initialized in the reset function called in the constructor
	const char HeadTexture;
	const char BodyTexture;
	const char TailTexture;
	int32 Speed;
	int32 Size;
	ESnakeState CurrentState;
	ESnakeCurrentDirection CurrentDirection;

	void TimeDelay() const;// helper function to delay snake's coordinates updating, depends on snake's speed
	void Display() const;
};

