#include "stdafx.h"
#include "bIsObjectsCollide.h"


bIsObjectsCollide::bIsObjectsCollide()
{
}


bIsObjectsCollide::~bIsObjectsCollide()
{
}

bool bIsObjectsCollide::operator()(const Block & Object_1, const Block & Object_2) const
{
	// Object_1 coordinates and size parameters 
	const float X_POS_OBJ_1 = Object_1.MainSprite.getPosition().x;
	const float Y_POS_OBJ_1 = Object_1.MainSprite.getPosition().y;
	const float X_SIZE_OBJ_1 = BASE_SPRITE_SIZE * Object_1.MainSprite.getScale().x;
	const float Y_SIZE_OBJ_1 = BASE_SPRITE_SIZE * Object_1.MainSprite.getScale().y;
	// Object_2 coordinates and size parameters 
	const float X_POS_OBJ_2 = Object_2.MainSprite.getPosition().x;
	const float Y_POS_OBJ_2 = Object_2.MainSprite.getPosition().y;
	const float X_SIZE_OBJ_2 = BASE_SPRITE_SIZE * Object_2.MainSprite.getScale().x;
	const float Y_SIZE_OBJ_2 = BASE_SPRITE_SIZE * Object_2.MainSprite.getScale().y;

	// get coordinates of the FIRST object points
	for (float x = X_POS_OBJ_1; x != X_SIZE_OBJ_1; x++)// get x pos of first object point
	{ 
		for (float y = Y_POS_OBJ_1; y != Y_SIZE_OBJ_1; y++)// get y pos of first object point
		{
			// get coordinates of the SECOND object points
			for (float x2 = X_POS_OBJ_1; 2 != X_SIZE_OBJ_1; x2++)// get x pos of second object point
			{
				for (float y2 = Y_POS_OBJ_1; y2 != Y_SIZE_OBJ_1; y2++)// get y pos of second object point
				{// if the coordinates of any points of two objects are equal
					if (x == x2 && y == y2)
					{
						return true;// collision
					}
				}
			}
		}
	}
	return false;
}
