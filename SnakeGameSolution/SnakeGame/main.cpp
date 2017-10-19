// SnakeGame.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "StartDisplay.h"


int main()
{
	StartDisplay StartDisplay;// intialize main menu object
	StartDisplay.MenuListener();

	system("pause");
    return 0;
}

