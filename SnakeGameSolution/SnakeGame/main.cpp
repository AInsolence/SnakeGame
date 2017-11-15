// SnakeGame.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "StartDisplay.h"
#include "HUD.h"
#include "Block.h"
#include "Level.h"
#include "Snake.h"
#include "KeyListener.h"
#include "Food.h"
#include "bIsObjectsCollide.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HIGHT), "SFML works!");
	
	Block* NewBlock = new Block ("Yellow", 100, 100, 0.3f, 0.3f);
	Snake MySnake("Red", 200, 200, 0.1f, 0.1f);
	Level Level01(0.2f, 0.2f);
	KeyListener Klistner;
	bIsObjectsCollide bIsCollide;
	HUD hud("Anton", 0);
	
	
	sf::Texture texture;
		if (!texture.loadFromFile("../../image/Block_Box_2_Light.png"))// load texture image form file
		{
			return EXIT_FAILURE;// exit if do not find texture file
		}
		sf::Sprite sprite;
		sprite.setTexture(texture);

	//start the clock
	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		Klistner.Start(&MySnake);
		MySnake.Move();
		for (auto block : Level01.GetMainBorder())
		{
			if (bIsCollide(MySnake.Body[0], block))
			{
				std::cout << "true" << std::endl;
			}
			else std::cout << "false" << std::endl;
		}
		
		if (bIsCollide(MySnake.Body[0], NewBlock))
		{
			MySnake.ChangeSize(1);
		}
		window.clear();

		window.draw(NewBlock->MainSprite);
		//window.draw(MySnake.Body[0]->GetMainSprite());

		for (auto block : Level01.GetMainBorder())
		{
			window.draw(block->MainSprite);
		}
		
		for (auto segment : MySnake.Body)
		{
			window.draw(segment->MainSprite);
		}

		//HUD Display
		window.draw(hud.GetPlayerName());
		window.draw(hud.GetScores());
		//Check UpdateScore method
		hud.UpdateScores(10);// works well

		window.display();
		sf::Time TimeGap = sf::seconds(0.6f);
		sf::Time Elapsed = clock.restart();
		while (Elapsed < TimeGap)
		{
			Elapsed = clock.getElapsedTime();
		}
	}
    return 0;
}

