// SnakeGame.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "StartDisplay.h"
#include "Level.h"
#include "Snake.h"

int main()
{
	Level Level01(15, 25);
	Snake Snake(2, 2);

	for(int32 i = 0; i < 10; i++)
	{
		Snake.Move();

		// check Canvas creation
		for (auto Column : IGameObject::Canvas) // TODO delete before release
		{
			for (auto Character : Column) std::cout << Character;
			std::cout << std::endl;
		}
	}

	system("pause");

	StartDisplay StartDisplay;// intialize main menu object
	StartDisplay.MenuListener();

	system("pause");
    return 0;
}

