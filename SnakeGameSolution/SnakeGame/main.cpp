// SnakeGame.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "StartDisplay.h"
#include "Level.h"


int main()
{
	Level Level01(30, 20);

	system("pause");

	StartDisplay StartDisplay;// intialize main menu object
	StartDisplay.MenuListener();

	system("pause");
    return 0;
}

