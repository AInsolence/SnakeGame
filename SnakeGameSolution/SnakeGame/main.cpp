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
	Level Level01;
	
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

		window.clear();
		/*std::vector<sf::Sprite> vec(10);
		for (int32 i = 0; i < 500; i += 40)
		{
			int32 x = 0; int32 y = 0;
			sf::Sprite *ptr;
			ptr = new sf::Sprite(sprite);
			ptr->setPosition(0, i);
			vec.push_back(*ptr);
			
		}*/
		window.draw(NewBlock.GetMainSprite());

		for (auto segment : MySnake.Body)
		{
			window.draw(segment->GetMainSprite());
		}

		for (auto block : Level01.MainBorder)
		{
			window.draw(block->GetMainSprite());
		}
		
		window.display();
	}
    return 0;
}

