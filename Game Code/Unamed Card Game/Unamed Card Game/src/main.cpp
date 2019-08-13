/*! \file main.cpp
*		This is the entry point for the project. 
*/

#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow l_Window(sf::VideoMode(800, 800), "Unamed Card Game"); 

	while (l_Window.isOpen())
	{
		sf::Event l_Event;

		// Events Here. 

		while (l_Window.pollEvent(l_Event))
		{
			if (l_Event.type == sf::Event::Closed)
			{
				return 1;
			}
		}

		l_Window.clear();

		// Draw Here. 

		l_Window.display();
	}

	return 0; 
}