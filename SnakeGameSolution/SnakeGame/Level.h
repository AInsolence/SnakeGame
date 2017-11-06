#pragma once
#include "BorderBlock.h"
class Level
{
public:
	Level();
	~Level();

	void SetMainBorder(int32 MAIN_WINDOW_WIDTH, int32 MAIN_WINDOW_HIGHT, float XScale, float YScale);
	std::vector<BorderBlock*> GetMainBorder ();

private:
	std::vector<BorderBlock*> MainBorder;
};

