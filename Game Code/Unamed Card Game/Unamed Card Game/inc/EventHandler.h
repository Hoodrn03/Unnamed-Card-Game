#pragma once

#include "SFML/Graphics.hpp"

class EventHandler
{
public:

	// Constructor 

	EventHandler();

	// Deconstructor 

	~EventHandler();

private:

	// Data Members 

public:

	// Member Functions

	/*! \fn DetectEvents : Used to detect current events within the game current loop of the game. 
	*Param One : RenderWindow - The current game window. 
	*/
	void m_DetectEvents(sf::RenderWindow & gameWindow);

	/*! \fn HandleEvents : Used to handle any events detected within the game. #
	*Param One : Int - The code for the event detected. 
	*Param Two : RenderWindow - The current game window. 
	*/
	void m_HandleEvents(int eventCode, sf::RenderWindow & gameWindow);

};