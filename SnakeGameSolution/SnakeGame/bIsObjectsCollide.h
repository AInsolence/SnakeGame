#pragma once
#include "Block.h"

class bIsObjectsCollide
{
public:
	bIsObjectsCollide();
	~bIsObjectsCollide();

	bool operator () (const Block*, const Block*) const;
	bool IsObjectInside(const Block*, const Block*) const;
};

