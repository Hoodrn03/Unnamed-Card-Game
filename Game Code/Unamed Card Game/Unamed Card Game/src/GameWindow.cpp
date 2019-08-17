#include "GameWindow.h"

GameWindow::GameWindow()
{
}

GameWindow::~GameWindow()
{
}

/*! \fn CreateWindow : This will be used to initalize the game window.
*Param One : Int - The width of the game window.
*Param Two : Int - The height of the game window. 
*/
int GameWindow::m_CreateWindow(int width, int height)
{
	m_RenderWindow.create(sf::VideoMode(width, height), "Unnamed Card Game");

	if (m_RenderWindow.isOpen())
	{
		return 0; 
	}

	return 1;
}

/*! \fn GetWindow : This will allow for access of the game window. */
sf::RenderWindow& GameWindow::m_GetWindow()
{
	return m_RenderWindow;
}

/*! \fn ClearWindow : Used to clear the game window. */
void GameWindow::m_ClearWindow()
{
	m_RenderWindow.clear();
}

/*! \fn DisplayWindow : Used to display all of the elements onto the game window. */
void GameWindow::m_DisplayWindow()
{
	m_RenderWindow.display();
}
