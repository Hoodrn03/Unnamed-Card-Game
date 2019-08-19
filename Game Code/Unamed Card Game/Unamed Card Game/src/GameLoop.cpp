#include "GameLoop.h"

GameLoop::GameLoop()
{

}

GameLoop::~GameLoop()
{
}

int GameLoop::m_RunGame()
{
	int l_iError = 0;

	try
	{
		l_iError = m_clGameWindow.m_CreateWindow(800, 800);

		if (l_iError > 0)
		{
			throw l_iError;
		}

		l_iError = m_GameplayLoop();

		if (l_iError > 0)
		{
			throw l_iError;
		}

	}
	catch (int l_iErrorType)
	{
		switch (l_iErrorType)
		{
		case 1:

			std::cout << "Error Code : " << l_iErrorType << "Unable to open game window" << std::endl;

			break;

		default:

			std::cout << "Undefined Error Code : " << l_iErrorType << std::endl;

			break;
		}

		return 1;
	}

	return 0;
}

int GameLoop::m_GameplayLoop()
{

	while (m_clGameWindow.m_GetWindow().isOpen())
	{
		// Events Here. 

		m_clEventHandler.m_DetectEvents(m_clGameWindow.m_GetWindow());

		m_clGameWindow.m_ClearWindow();

		// Draw Here. 

		m_clGameWindow.m_DisplayWindow();
	}

	return 0;
}


