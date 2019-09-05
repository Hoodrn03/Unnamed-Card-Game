#pragma once

#include <iostream>

#include "GameWindow.h"
#include "EventHandler.h"

#include "GameBoard.h"

/*! \class This will be used to control the flow of the game. */
class GameLoop
{
	// Constructor 

public:

	GameLoop();

	// Deconstructor 

	~GameLoop();

private:

	// Data Members 

	/*! \var The main game window for this game, it will be used to contain all of the visual elements for the game. */
	GameWindow m_clGameWindow; 

	/*! \var The event handler for the game, all events in the game will be processed through this class. */
	EventHandler m_clEventHandler; 

public:

	// Member Functions

	/*! \fn RunGame : This will be used to initiate the game, booting it onto the main menu. This will also handle all critical 
	errors, wherein the game closes. */
	int m_RunGame(); 

	/*! \fn GameplayLoop : This will hold the main gameplay loop, for this game it will be between two players. */
	int m_GameplayLoop(); 
};