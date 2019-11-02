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

		// Create UserInterface

		l_iError = m_clUserInterface.m_CreateGUI(m_clGameWindow.m_GetWindow());

		// Check For Error

		if (l_iError > 0)
		{
			throw l_iError;
		}

		// Load objects. 

		m_clFontManager.m_LoadFontFromFile("Arial", "assets/Fonts/Arial.ttf");

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

		case 3:

			// Unable to create a user interface with the game window. 

			std::cout << "Error Code : " << l_iErrorType << "Unable to create User Intrface." << std::endl;

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

	l_NewGameBoard.m_CreateGameBoard(700, 650, m_clGameWindow.m_GetWindow());

	// End of game board setup. 

	// Setup Collection.

	Collection l_clCollection;

	l_clCollection.m_LoadCardCollectionFromFile("assets/Objects/collection.xml");

	l_clCollection.m_SetFontsForCards(m_clFontManager.m_GetItemFromMap("Arial")); 

	l_clCollection.m_CreateCardBodies();

	int l_iCardIndex = 0;

	// End of collection setup.

	// Test Objects

	l_clCollection.m_GetCard(l_iCardIndex).m_SetCardPosition(100, 500);
	l_clCollection.m_GetCard(l_iCardIndex + 1).m_SetCardPosition(300, 100);

	SingleTarget l_Target; 

	// End of test objects

	while (m_clGameWindow.m_GetWindow().isOpen())
	{
		// Update Logic.

		m_clMouse.m_SetMousePos(m_clGameWindow.m_GetWindow());
		m_clMouse.m_UpdateMouseCurser();

		if ((m_clMouse.m_GetLMBDown()) && 
			(l_clCollection.m_GetCard(l_iCardIndex + 1).m_WithinCard(m_clMouse.m_GetMousePos().x, m_clMouse.m_GetMousePos().y)))
		{
			l_Target.m_SetTarget(m_clMouse.m_GetMousePos().x, m_clMouse.m_GetMousePos().y); 
		}

		// Events Here. 

		m_clEventHandler.m_DetectEvents(m_clGameWindow.m_GetWindow());

		if (m_clEventHandler.m_HandleEvents() < 0)
		{
			return -1;
		}

		m_clGameWindow.m_ClearWindow();

		// Draw Here. 

		l_NewGameBoard.m_DrawGameBoard(m_clGameWindow.m_GetWindow()); 

		l_clCollection.m_GetCard(l_iCardIndex).m_DrawCard(m_clGameWindow.m_GetWindow());
		l_clCollection.m_GetCard(l_iCardIndex + 1).m_DrawCard(m_clGameWindow.m_GetWindow());

		// m_clMouse.m_DrawMouseCurser(m_clGameWindow.m_GetWindow()); 

		m_clGameWindow.m_DisplayWindow();
	}

	// Exit main game loop. 

	return 0;
}


