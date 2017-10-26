#pragma once
#include "IGameObject.h"
#include <vector>


class Level : public IGameObject
{
public:
	Level(int32, int32);
	~Level();

	void Create(int32, int32);// create main level surface & border

private:
	// initialized in the constructor
	const char LevelSurfaceTexture;// texture for represent level surface
	const char LevelBorderTexture; // 'texture' for paint levels border
};

