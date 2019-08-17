#pragma once

#include <SFML/Graphics.hpp>

/*! \class GameWidow : This will be used to control the main game window. */
class GameWindow
{
public:

	// Constructors 

	GameWindow();

	// Deconstructor 

	~GameWindow();

private:

	// Data Members 

	/*! \var This will be the main window for the game. */
	sf::RenderWindow m_RenderWindow; 

public:

	// Memeber Functions 

	/*! \fn CreateWindow : This will be used to initalize the game window.
	*Param One : Int - The width of the game window.
	*Param Two : Int - The height of the game window.
	*/
	int m_CreateWindow(int height, int width);

	/*! \fn GetWindow : This will allow for access of the game window. */
	sf::RenderWindow& m_GetWindow();

	/*! \fn ClearWindow : Used to clear the game window. */
	void m_ClearWindow();

	/*! \fn DisplayWindow : USed to display all of the elements onto the game window. */
	void m_DisplayWindow(); 
};
