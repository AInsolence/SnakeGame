#pragma once
#include "IGameObject.h"
#include <vector>

using int32 = int;
using FField = std::vector< std::vector<char> >;

class Level : public IGameObject
{
public:
	Level(int32, int32);
	~Level();

	FField Canvas;// matrix (vector of vectors) to display level
	void CreateCanvas(int32, int32);// create main level canvas & border

private:
	char LevelBorderTexture;
};

