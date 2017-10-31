#pragma once
#include "stdafx.h"
#include "IGameObject.h"
#include <map>


class BorderBlock : public IGameObject
{
public:
	BorderBlock(std::string BlockType, int32 x, int32 y);
	~BorderBlock();

private:

	std::map<std::string, std::string> BlockTypes{
		{"Blue", "../../image/Block_Blue.png"},
		{ "Dark", "../../image/Block_Box_1_Dark.png" },
		{ "Light", "../../image/Block_Box_1_Light.png" },
		{ "Green", "../../image/Block_Green.png" },
		{ "Red", "../../image/Block_Red.png" },
		{ "Yellow", "../../image/Block_Yellow.png" }
	};
};

