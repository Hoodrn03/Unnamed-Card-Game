/*! \file main.cpp
*		This is the entry point for the project. 
*/

#include <SFML/Graphics.hpp>

#include "GameWindow.h"
#include "EventHandler.h"

int main()
{
	GameWindow l_clGameWindow;

	l_clGameWindow.m_CreateWindow(500, 500);

	EventHandler l_clEventHandler; 

	while (l_clGameWindow.m_GetWindow().isOpen())
	{
		// Events Here. 

		l_clEventHandler.m_DetectEvents(l_clGameWindow.m_GetWindow());

		l_clGameWindow.m_ClearWindow();

		// Draw Here. 

		l_clGameWindow.m_DisplayWindow(); 
	}

	return 0; 
}