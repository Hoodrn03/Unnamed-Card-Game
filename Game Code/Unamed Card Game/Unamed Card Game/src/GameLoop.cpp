#include "GameLoop.h"

GameLoop::GameLoop()
{

}

GameLoop::~GameLoop()
{
}

/*! \fn RunGame : This will be used to initiate the game, booting it onto the main menu. This will also handle all critical
					errors, wherein the game closes. */
int GameLoop::m_RunGame()
{
	int l_iError = 0;

	try
	{
		// Setup game window.

		l_iError = m_clGameWindow.m_CreateWindow(800, 800);

		if (l_iError > 0)
		{
			throw l_iError;
		}

		// Start gameplay loop.

		l_iError = m_GameplayLoop();

		if (l_iError > 0)
		{
			throw l_iError;
		}

	}

	// Error checking. 

	catch (int l_iErrorType)
	{
		switch (l_iErrorType)
		{
		case 1:

			// Unable to open game window.

			std::cout << "Error Code : " << l_iErrorType << "Unable to open game window" << std::endl;

			break;

		case 2:

			// Unable to form a connection between host and server. 

			std::cout << "Error Code : " << l_iErrorType << "Unable to complete networking." << std::endl;

			break;

		default:

			std::cout << "Undefined Error Code : " << l_iErrorType << std::endl;

			break;
		}

		return 1;
	}

	return 0;
}

/*! \fn GameplayLoop : This will hold the main gameplay loop, for this game it will be between two players. */
int GameLoop::m_GameplayLoop()
{
	// Pregame Logic.

	/*! \var The game board for the game, this will hold the cards on itself. */
	GameBoard l_NewGameBoard;

	l_NewGameBoard.m_CreateGameBoard(m_clGameWindow.m_GetWindow());

	while (m_clGameWindow.m_GetWindow().isOpen())
	{
		// Update Logic.

		m_clMouse.m_SetMousePos(m_clGameWindow.m_GetWindow());
		m_clMouse.m_UpdateMouseCurser();

		// Events Here. 

		m_clEventHandler.m_DetectEvents(m_clGameWindow.m_GetWindow());

		m_clGameWindow.m_ClearWindow();

		// Draw Here. 

		l_NewGameBoard.m_DrawGameBoard(m_clGameWindow.m_GetWindow()); 

		m_clMouse.m_DrawMouseCurser(m_clGameWindow.m_GetWindow()); 

		m_clGameWindow.m_DisplayWindow();
	}

	return 0;
}


