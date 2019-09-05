#pragma once

#include <iostream>

#include "GameWindow.h"
#include "EventHandler.h"

#include "GameBoard.h"

class GameLoop
{
	// Constructor 

public:

	GameLoop();

	// Deconstructor 

	~GameLoop();

private:

	// Data Members 

	GameWindow m_clGameWindow; 

	EventHandler m_clEventHandler; 

public:

	// Member Functions

	int m_RunGame(); 

	int m_GameplayLoop(); 
};