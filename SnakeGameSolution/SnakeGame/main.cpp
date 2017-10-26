// SnakeGame.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "StartDisplay.h"
#include "Level.h"
#include "Snake.h"

int main()
{
	Level Level01(25, 15);
	Snake Snake(2, 2);

	for(int32 i = 0; i < 10; i++)
	{
		Level01.Create(25, 15);
		Snake.Move();

		// check Canvas creation
		for (auto Raw : IGameObject::Canvas) // TODO delete before release
		{
			for (auto Character : Raw) std::cout << Character;
			std::cout << std::endl;
		}
		const int32 MILISECONDS_IN_SECOND = 1000;

		clock_t StartOfDelay = clock();
		// TODO Check right speed here
		_getch();
		system("cls");
	}

	system("pause");

	StartDisplay StartDisplay;// intialize main menu object
	StartDisplay.MenuListener();

	system("pause");
    return 0;
}

