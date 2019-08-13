/*! \file main.cpp
*		This is the entry point for the project. 
*/

#include <SFML/Graphics.hpp>

#include "GameWindow.h"

int main()
{
	GameWindow l_clGameWindow;

	l_clGameWindow.m_CreateWindow(500, 500);

	while (l_clGameWindow.m_GetWindow().isOpen())
	{
		sf::Event l_Event;

		// Events Here. 

		while (l_clGameWindow.m_GetWindow().pollEvent(l_Event))
		{
			if (l_Event.type == sf::Event::Closed)
			{
				return 1;
			}
		}

		l_clGameWindow.m_GetWindow().clear();

		// Draw Here. 

		l_clGameWindow.m_GetWindow().display();
	}

	return 0; 
}