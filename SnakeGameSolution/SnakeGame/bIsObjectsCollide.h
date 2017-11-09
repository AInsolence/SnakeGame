#pragma once
#include "Block.h"

class bIsObjectsCollide
{
public:
	bIsObjectsCollide();
	~bIsObjectsCollide();

	bool operator () (Block*, Block*) const;
};

