// SnakeGame.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "StartDisplay.h"
#include "BorderBlock.h"
#include "Level.h"
#include "Snake.h"
#include "KeyListener.h"




int main()
{
	sf::RenderWindow window(sf::VideoMode(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HIGHT), "SFML works!");
	
	BorderBlock NewBlock("Yellow", 100, 100);
	Snake MySnake("Red", 200, 200);
	MySnake.SetCurrentDirection(ESnakeCurrentDirection::Left);
	Level Level01;
	KeyListener Klistner;
	
	
	sf::Texture texture;
		if (!texture.loadFromFile("../../image/Block_Box_2_Light.png"))// load texture image form file
		{
			return EXIT_FAILURE;// exit if do not find texture file
		}
		sf::Sprite sprite;
		sprite.setTexture(texture);

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
		std::cout << MySnake.Body[0]->GetMainSprite().getPosition().x << " ";
		std::cout << MySnake.Body[0]->GetMainSprite().getPosition().y << std::endl;

		window.clear();

		//window.draw(NewBlock.GetMainSprite());
		//window.draw(MySnake.Body[0]->GetMainSprite());

		for (auto block : Level01.GetMainBorder())
		{
			window.draw(block->GetMainSprite());
		}
		
		for (auto segment : MySnake.Body)
		{
			window.draw(segment->GetMainSprite());
		}

		window.display();
		
	}
    return 0;
}

