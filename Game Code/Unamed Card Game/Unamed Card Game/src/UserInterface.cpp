#include "UserInterface.h"

UserInterface::UserInterface()
{
}

UserInterface::~UserInterface()
{
}

tgui::Gui UserInterface::m_GetGUI()
{
	return &m_ptrInterface->get;
}

void UserInterface::m_ClearGUI()
{
}

int UserInterface::m_CreateGUI(sf::RenderWindow& window)
{

	m_ptrInterface.reset(new tgui::Gui(window));

	std::cout << "Interface Created" << std::endl;

	return 0;
}

void UserInterface::m_DrawGUI()
{
	m_ptrInterface->draw();
}
