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
	if (IsObjectInside(Object_1, Object_2) || IsObjectInside(Object_2, Object_1))
	{// if object inside another or vice versa
		return true;
	}
	return false;
}

// check is one object's angles inside other object or not
bool bIsObjectsCollide::IsObjectInside(const Block * Object_1, const Block * Object_2) const
{
	// Object_1 coordinates and size parameters 
	const float X_POS_OBJ_1 = Object_1->MainSprite.getPosition().x;
	const float Y_POS_OBJ_1 = Object_1->MainSprite.getPosition().y;
	const float X_SIZE_OBJ_1 = BASE_SPRITE_SIZE * Object_1->MainSprite.getScale().x;
	const float Y_SIZE_OBJ_1 = BASE_SPRITE_SIZE * Object_1->MainSprite.getScale().y;
	// Object_2 coordinates and size parameters 
	const float X_POS_OBJ_2 = Object_2->MainSprite.getPosition().x;
	const float Y_POS_OBJ_2 = Object_2->MainSprite.getPosition().y;
	const float X_SIZE_OBJ_2 = BASE_SPRITE_SIZE * Object_2->MainSprite.getScale().x;
	const float Y_SIZE_OBJ_2 = BASE_SPRITE_SIZE * Object_2->MainSprite.getScale().y;

	for (int32 x = X_POS_OBJ_1; x <= X_POS_OBJ_1 + X_SIZE_OBJ_1; x += X_SIZE_OBJ_1)
	{
		for (int32 y = Y_POS_OBJ_1; y <= Y_POS_OBJ_1 + Y_SIZE_OBJ_1; y += Y_SIZE_OBJ_1)
		{
			if ((x >= X_POS_OBJ_2 && x <= (X_POS_OBJ_2 + X_SIZE_OBJ_2))\
				&& (y >= Y_POS_OBJ_2 && y <= (Y_POS_OBJ_2 + Y_SIZE_OBJ_2)))
			{
				return true;
			}
		}
	}

	return false;
}
