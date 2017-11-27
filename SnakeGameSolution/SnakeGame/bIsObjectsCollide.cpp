#include "stdafx.h"
#include "bIsObjectsCollide.h"


bIsObjectsCollide::bIsObjectsCollide()
{
}


bIsObjectsCollide::~bIsObjectsCollide()
{
}

bool bIsObjectsCollide::operator()(const Block* Object_1, const Block* Object_2) const
{
	if (Object_1->MainSprite.getGlobalBounds().intersects(Object_2->MainSprite.getGlobalBounds())) 
	{
		return true;
	}
		
	return false;
}
