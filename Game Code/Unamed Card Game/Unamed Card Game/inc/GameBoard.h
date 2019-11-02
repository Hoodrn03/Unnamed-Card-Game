#pragma once

#include "SFML/Graphics.hpp"

#include <iostream>

/*! \class This will hold the main functionality for the game board, it will allow for cards to be placed overtop of it. */
class GameBoard
{
	// Constructor 

public:

	GameBoard();

	// Deconstructor 

	~GameBoard();

	// Data Members 

private:

	/*! \var The main game board for the game (Basic background). */
	sf::RectangleShape m_GameBoard;

	// Member Functions 

public:

	/*! \fn DrawGameBoard : This will draw the current game board onto the current game window. 
	*Param One : RenderWindow - The main game window to be drawn onto. 
	*/
	void m_DrawGameBoard(sf::RenderWindow & window);

	/*! \fn CreateGameBoard : This will create the basis for the game board (using rectangle shapes).
	*Param One : Float - The width for the game board.
	*Param Two : Float - The height for the game board.
	*/
	void m_CreateGameBoard(float width, float height);

	void m_CreateGameBoard(float width, float height, sf::RenderWindow& window);

	void m_CreateGameBoard(float width, float height, float x, float y);

	/*! \fn CreateGameBoard (Override) : This will create the basis for the game board (using rectangle shapes).
	*Param One : RenderWindow - The main game window allowing for the board to be properly sized.
	*/
	void m_CreateGameBoard(sf::RenderWindow& window);
};