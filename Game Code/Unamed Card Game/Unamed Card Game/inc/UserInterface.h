#pragma once

#include <iostream>

#include "SFML/Graphics.hpp"

#include "TGUI/TGUI.hpp"

/*! \class This will be used to control all of the user interface elements within the game
			it will hale the adding and removing of all of these widgits. 
*/
class UserInterface
{
	// Constructor

public:

	UserInterface();

	// Deconstructor 

	~UserInterface();

	// Data Members 

private:

	std::unique_ptr<tgui::Gui> m_ptrInterface; 

	// Member Functions

public:

	tgui::Gui *m_GetGUI(); 

	void m_ClearGUI(); 

	int m_CreateGUI(sf::RenderWindow& window);

	void m_DrawGUI();

};