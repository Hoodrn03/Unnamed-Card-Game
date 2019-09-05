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

	for (unsigned int i = 0; i < v_CardSlots.size(); i++)
	{
		window.draw(v_CardSlots[i]); 
	}
}

/*! \fn CreateGameBoard : This will create the basis for the game board (using rectangle shapes).
*Param One : Float - The width for the game board.
*Param Two : Float - The height for the game board.
*/
void GameBoard::m_CreateGameBoard(float width, float height)
{
	m_GameBoard.setSize(sf::Vector2f(width, height));

	m_GameBoard.setPosition(sf::Vector2f(200, 200)); 
}

/*! \fn CreateGameBoard (Override) : This will create the basis for the game board (using rectangle shapes).
*Param One : RenderWindow - The main game window allowing for the board to be properly sized.
*/
void GameBoard::m_CreateGameBoard(sf::RenderWindow& window)
{
	// This should create the game board using the size of the current game window. To ensure the box is within the center of the screen then you will
	// need to work out what will get the width to 1 then  half what you would need to add to get it there. E.g. 0.5 + 0.5 = 1 so the offset will be 2.5; 


	/*! \var The height and width for the game board. */
	float l_fWidth = 0.7f, l_fHeight = 0.5f;

	/*! \var The offset for the game board to place it within the center. */
	float l_fWidthOffSet = 0.15f, l_fHeightOffset = 0.25f; 

	// Create main game board.

	m_GameBoard.setSize(sf::Vector2f(window.getSize().x * l_fWidth, window.getSize().y * l_fHeight));

	m_GameBoard.setPosition(sf::Vector2f(window.getSize().x * l_fWidthOffSet, window.getSize().y * l_fHeightOffset));

	// Create card slots for game board. 


}

