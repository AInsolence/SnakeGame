// SnakeGame.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "StartDisplay.h"
#include "BorderBlock.h"
#include "Snake.h"
#include "KeyListener.h"



int main()
{
	sf::RenderWindow window(sf::VideoMode(1366, 720), "SFML works!");
	
	BorderBlock NewBlock("Yellow", 100, 100);
	Snake MySnake("Red", 200, 200);
	
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
		window.draw((std::get<0>(MySnake.Body[0])));
		/*for (auto segment : MySnake.Body)
		{
			window.draw(std::get<0>(segment));
		}*/
		
		window.display();
	}
    return 0;
}

