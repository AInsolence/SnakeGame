#pragma once
#include "stdafx.h"
#include "KeyListener.h"


KeyListener::KeyListener()
{
	KeyCommand = 'd';// right-direction by default
}


KeyListener::~KeyListener()
{
}

void KeyListener::Start(Snake *Object)
{
	// get users input
	if (_kbhit())//if any key is pressed
	{
		KeyCommand = _getch();//get it
	}
	switch (KeyCommand) {// and change direction if it's necessary
	case KEY_LEFT:
		Object->SetCurrentDirection(ESnakeCurrentDirection::Left);
		break;
	case KEY_RIGHT:
		Object->SetCurrentDirection(ESnakeCurrentDirection::Right);
		break;
	case KEY_UP:
		Object -> SetCurrentDirection(ESnakeCurrentDirection::Up);
		break;
	case KEY_DOWN:
		Object -> SetCurrentDirection(ESnakeCurrentDirection::Down);
	default:
		break;
	}
}
