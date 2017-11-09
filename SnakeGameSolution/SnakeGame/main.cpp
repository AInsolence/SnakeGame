// SnakeGame.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "StartDisplay.h"
#include "Block.h"
#include "Level.h"
#include "Snake.h"
#include "KeyListener.h"
#include "Food.h"
#include "bIsObjectsCollide.h"




int main()
{
	sf::RenderWindow window(sf::VideoMode(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HIGHT), "SFML works!");
	
	Block NewBlock("Yellow", 100, 100, 0.2f, 0.2f);
	Snake MySnake("Red", 200, 200, 0.1f, 0.1f);
	Level Level01(0.2f, 0.2f);
	KeyListener Klistner;
	
	
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
		std::cout << MySnake.Body.size();
		std::cout << MySnake.Body[0]->MainSprite.getPosition().x << " ";
		std::cout << MySnake.Body[0]->MainSprite.getPosition().y << std::endl;

		MySnake.SetCurrentDirection(ESnakeCurrentDirection::Down);
		if (ESnakeCurrentDirection::Down ==  MySnake.GetCurrentDirection())
		{
			std::cout << "Right" << std::endl;
		}
		
		window.clear();

		//window.draw(NewBlock.GetMainSprite());
		//window.draw(MySnake.Body[0]->GetMainSprite());

		for (auto block : Level01.GetMainBorder())
		{
			window.draw(block->MainSprite);
		}
		
		for (auto segment : MySnake.Body)
		{
			window.draw(segment->MainSprite);
		}

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

