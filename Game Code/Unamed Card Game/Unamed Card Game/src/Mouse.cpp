/*! \file This will hold all of the class definitions for the class Mouse.h. */

#include "Mouse.h"

//--------------------------------------------------------
/*! \fn Constructor
*
*/
Mouse::Mouse()
{
	// Prep mouse selection box.

	m_SelectionBox.setFillColor(sf::Color::Transparent); 

	m_SelectionBox.setOutlineThickness(1.f); 

	m_SelectionBox.setOutlineColor(sf::Color::Black);

	// Prep mouse curser. 

	m_MouseCurser.setSize(sf::Vector2f(10, 10));

	m_MouseCurser.setOrigin(m_MouseCurser.getGlobalBounds().width * 0.5f, m_MouseCurser.getGlobalBounds().height * 0.5f);

	m_MouseCurser.setFillColor(sf::Color::Green);

	m_MouseCurser.setOutlineThickness(1.f);
}

//--------------------------------------------------------
/*! \fn Deconstructor
*
*/
Mouse::~Mouse()
{
}

//--------------------------------------------------------
//						Positioning
//--------------------------------------------------------

//--------------------------------------------------------
/*! \fn SetmousePos This will update the current mouse position.
*Param One : RenderWindow - The main game window.
*/
void Mouse::m_SetMousePos(sf::RenderWindow & window)
{
	// Get mouse position on desktop.
	sf::Vector2i l_PixelPos = sf::Mouse::getPosition(window);

	// Convert it to world coordinates.
	m_MousePos = window.mapPixelToCoords(l_PixelPos);
}

//--------------------------------------------------------
/*! \fn GetMousePos Used to return the value of the mouse position.
*
*/
sf::Vector2f Mouse::m_GetMousePos()
{
	return m_MousePos;
}

/*! \fn UpdateMouseCurser : Used to move the mouse curser to the current position of the mouse
*
*/
void Mouse::m_UpdateMouseCurser()
{
	m_MouseCurser.setPosition(m_MousePos); 
}

//--------------------------------------------------------
//						Clicking
//--------------------------------------------------------

/*! \var GetLMBDown : Used to check if the left mouse button is pressed.
*Param One : Vector2f - The upper map bounds to check if the mouse is within a box.
*Param Two : Vector2f - The lower map bounds to check if the mouse is within a box.
*/
bool Mouse::m_GetLMBDown()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		// std::cout << "Left Down" << std::endl;

		return true;
	}

	return false; 
}

/*! \var GetLMBDown : Used to check if the left mouse button is pressed.
*Param One : Vector2f - The upper map bounds to check if the mouse is within a box.
*Param Two : Vector2f - The lower map bounds to check if the mouse is within a box.
*/
bool Mouse::m_GetLMBDown(sf::Vector2f mapUpperBounds, sf::Vector2f mapLowerBounds)
{
	if (((m_MousePos.x > mapUpperBounds.x) && (m_MousePos.y > mapUpperBounds.y)) && 
		((m_MousePos.x < mapLowerBounds.x) && (m_MousePos.y < mapLowerBounds.y)))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			return true; 
		}
	}

	return false;
}

//--------------------------------------------------------
//						Selecting
//--------------------------------------------------------

//--------------------------------------------------------
/*! \fn CreateSelectionBox : Used to create a selection box when the mouse button is pressed.
*
*/
void Mouse::m_CreateSelectionBox()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (m_bMouseFirstDown == false)
		{
			m_SelectionBox.setPosition(m_MousePos);

			m_bMouseFirstDown = true; 
		}
		else
		{
			float l_fHeight, l_fWidth;

			l_fWidth = m_MousePos.x - m_SelectionBox.getPosition().x;

			l_fHeight = m_MousePos.y - m_SelectionBox.getPosition().y;

			m_SelectionBox.setSize(sf::Vector2f(l_fWidth, l_fHeight)); 
		}
	}
	else
	{
		if (m_bMouseFirstDown != false)
		{
			m_bMouseFirstDown = false;

			m_SelectionBox.setSize(sf::Vector2f(0, 0)); 
		}
	}

}

//--------------------------------------------------------
/*! \fn GetTopLeftSelectonBox : Used to get check the bounds for the selection box.
*
*/
sf::Vector2f Mouse::m_GetTopLeftSelectionBox()
{
	return m_SelectionBox.getPosition();
}

//--------------------------------------------------------
/*! \fn GetBottomRightSelectonBox : Used to get check the bounds for the selection box.
*
*/
sf::Vector2f Mouse::m_GetBottomRightSelectionBox()
{
	return m_SelectionBox.getPosition() + m_SelectionBox.getSize();
}

//--------------------------------------------------------
//						Rendering
//--------------------------------------------------------

//--------------------------------------------------------
/*! \fn DrawSelectionBox : Used to draw the box into the game world.
*Param One : RenderWindow - The main game window.
*/
void Mouse::m_DrawSelectionBox(sf::RenderWindow& window)
{
	window.draw(m_SelectionBox);
}

/*! \fn DrawMouseCurser : This will be use to draw the mouse curser onto the game window.
*Param One : RenderWindow - The main game window to draw onto.
*/
void Mouse::m_DrawMouseCurser(sf::RenderWindow& window)
{
	window.draw(m_MouseCurser);
}

//--------------------------------------------------------
//					Tool Tip Management
//--------------------------------------------------------

/*! \fn AssignToolTipFont : Used to set the font for the tool tips.
*Param One : Font - The ttf file associated with the font.
*/
void Mouse::m_AssignToolTipFont(sf::Font newFont)
{
	m_LocalFont = newFont;

	m_ToolTip.setFont(m_LocalFont);

	m_ToolTip.setFillColor(sf::Color::White);

	m_ToolTip.setOutlineColor(sf::Color::Black);

	m_ToolTip.setOutlineThickness(0.5f);
}

/*! \fn UpdateToolTip : Used to update the text displayed by the tool tip.
*Param One : String - The string which will be displayed.
*Param Two : Vector2f - The position of the game view.
*Param Three : Vector2f - The size of the game view.
*/
void Mouse::m_UpdateTooltip(std::string dataToDisplay, sf::Vector2f viewPos, sf::Vector2f viewSize)
{
	if (dataToDisplay != m_PreveousText)
	{
		m_ToolTip.setString(dataToDisplay);

		m_PreveousText = dataToDisplay;
	}

	m_ToolTip.setPosition(viewPos.x + (viewSize.x * 0.01f), viewPos.y + (viewSize.y * 0.90f));

	m_ToolTip.setCharacterSize((unsigned int)(viewSize.y / 6));
}

/*! \fn DrawToolTip : This will be use to draw the tool tip onto the game window.
*Param One : RenderWindow - The main game window to draw onto.
*/
void Mouse::m_DrawToolTip(sf::RenderWindow & window)
{
	if (m_ToolTip.getFont() != nullptr)
	{
		window.draw(m_ToolTip); 
	}
}

