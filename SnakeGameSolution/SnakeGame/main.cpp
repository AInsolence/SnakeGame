// SnakeGame.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "StartDisplay.h"
#include "Level.h"
#include "Snake.h"
#include "KeyListener.h"

int main()
{
	Level Level01(25, 15);
	Snake Snake1(2, 2);
	KeyListener KListener;
	Snake1.SetCurrentDirection(ESnakeCurrentDirection::Left);

	for(int32 i = 0; i < 100; i++)
	{
		Level01.Display();
		Snake * Pointer = nullptr;
		Pointer = &Snake1;
		KListener.Start(Pointer);
		Snake1.Move();
		
		// paint Objects
		for (auto Raw : IGameObject::Canvas) // TODO delete before release
		{
			for (auto Character : Raw) std::cout << Character;
			std::cout << std::endl;
		}
		using namespace std::chrono_literals;
		std::this_thread::sleep_for(1s);
		// TODO Check right speed here
		system("cls");
	}

	system("pause");

	StartDisplay StartDisplay;// intialize main menu object
	StartDisplay.MenuListener();

	system("pause");
    return 0;
}

