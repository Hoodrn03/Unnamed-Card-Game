#include "GameWindow.h"

GameWindow::GameWindow()
{
}

GameWindow::~GameWindow()
{
}

int GameWindow::m_CreateWindow(int width, int height)
{
	m_RenderWindow.create(sf::VideoMode(width, height), "Unnamed Card Game");

	if (m_RenderWindow.isOpen())
	{
		return 0; 
	}

	return 1;
}

sf::RenderWindow& GameWindow::m_GetWindow()
{
	return m_RenderWindow;
}
