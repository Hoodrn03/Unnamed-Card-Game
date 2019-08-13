#pragma once

#include <SFML/Graphics.hpp>

class GameWindow
{
public:

	// Constructors 

	GameWindow();

	// Deconstructor 

	~GameWindow();

private:

	// Data Members 

	sf::RenderWindow m_RenderWindow; 

public:

	// Memeber Functions 

	int m_CreateWindow(int height, int width);

	sf::RenderWindow& m_GetWindow();
};
