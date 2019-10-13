#pragma once

#include "SFML/Graphics.hpp"

/*! \class The event handler for the game, any and all of the events for this game will be processed through
			this class. */
class EventHandler
{
public:

	// Constructor 

	EventHandler();

	// Deconstructor 

	~EventHandler();

private:

	// Data Members 

	int m_iCurrentEventCode = 0; 

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
	int m_HandleEvents();

};