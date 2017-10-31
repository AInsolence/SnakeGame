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
	
	BorderBlock NewBlock("Blue", 40, 40);

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
		window.display();
	}
    return 0;
}

