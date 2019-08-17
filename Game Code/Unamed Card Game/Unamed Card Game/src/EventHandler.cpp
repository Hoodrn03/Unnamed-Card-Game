#include "EventHandler.h"

EventHandler::EventHandler()
{

}

EventHandler::~EventHandler()
{

}

/*! \fn DetectEvents : Used to detect current events within the game current loop of the game.
*Param One : RenderWindow - The current game window.
*/
void EventHandler::m_DetectEvents(sf::RenderWindow & gameWindow)
{
	/*! \var This will be used to poll the window for events. */
	sf::Event l_Event; 

	while (gameWindow.pollEvent(l_Event))
	{
		if (l_Event.type == sf::Event::Closed)
		{
			m_HandleEvents(0, gameWindow);
		}
	}
}

/*! \fn HandleEvents : Used to handle any events detected within the game. #
*Param One : Int - The code for the event detected.
*Param Two : RenderWindow - The current game window.
*/
void EventHandler::m_HandleEvents(int eventCode, sf::RenderWindow & gameWindow)
{
	switch (eventCode)
	{
	case 0:

		gameWindow.close();

		break;
	
	default:

		break;
	}
}
