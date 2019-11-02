#include "GameBoard.h"

GameBoard::GameBoard()
{

}

GameBoard::~GameBoard()
{
}

/*! \fn DrawGameBoard : This will draw the current game board onto the current game window.
*Param One : RenderWindow - The main game window to be drawn onto.
*/
void GameBoard::m_DrawGameBoard(sf::RenderWindow & window)
{
	window.draw(m_GameBoard);
}

/*! \fn CreateGameBoard : This will create the basis for the game board (using rectangle shapes).
*Param One : Float - The width for the game board.
*Param Two : Float - The height for the game board.
*/
void GameBoard::m_CreateGameBoard(float width, float height)
{
	m_GameBoard.setSize(sf::Vector2f(width, height));

	m_GameBoard.setPosition(sf::Vector2f(50, 50)); 

	m_GameBoard.setFillColor(sf::Color(242, 151, 70, 255)); 
}

/*! \fn CreateGameBoard : This will create the basis for the game board (using rectangle shapes).
*Param One : Float - The width for the game board.
*Param Two : Float - The height for the game board.
*/
void GameBoard::m_CreateGameBoard(float width, float height, float x, float y)
{
	m_GameBoard.setSize(sf::Vector2f(width, height));

	m_GameBoard.setPosition(sf::Vector2f(x, y));

	m_GameBoard.setFillColor(sf::Color(242, 151, 70, 255));
}

/*! \fn CreateGameBoard : This will create the basis for the game board (using rectangle shapes).
*Param One : Float - The width for the game board.
*Param Two : Float - The height for the game board.
*/
void GameBoard::m_CreateGameBoard(float width, float height, sf::RenderWindow& window)
{
	// Setup main body for board.

	m_GameBoard.setSize(sf::Vector2f(width, height));

	m_GameBoard.setOrigin(sf::Vector2f(m_GameBoard.getPosition().x + (m_GameBoard.getGlobalBounds().width / 2), 
		m_GameBoard.getPosition().y + (m_GameBoard.getGlobalBounds().height / 2)));

	m_GameBoard.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));

	m_GameBoard.setFillColor(sf::Color(242, 151, 70, 255));

	// Setup card slots. 


}


