/*! \file This will manage the main functions for the mouse within the game. */

#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include <iostream>

/*! \class This class will be usd to maintain and manage mouse functions. */
class Mouse
{
	// Constructor 

public:

	//--------------------------------------------------------
	/*! \fn Constructor
	*
	*/
	Mouse(); 

	// Deconstructor 

public:

	//--------------------------------------------------------
	/*! \fn Deconstructor
	*
	*/
	~Mouse(); 

	// Data Members 

private:

	/*! \var This will hold the current position of the mouse in the game window. */
	sf::Vector2f m_MousePos;

	/*! \var This will be used to select items within the game. */
	sf::RectangleShape m_SelectionBox; 

	/*! \var The current mouse cureser for the game. */
	sf::RectangleShape m_MouseCurser; 

	/*! \var This will be used to limit the mouse down function to once a press. */
	bool m_bMouseFirstDown = false; 

	/*! \var The local font used by the tool tip. */
	sf::Font m_LocalFont;

	/*! \var This will be the tool tip displayed onto the screen. */
	sf::Text m_ToolTip; 

	/*! \var The preveous text displayed by the tool tip. */
	std::string m_PreveousText = " "; 

	// Member Functions

public:

	//--------------------------------------------------------
	//						Positioning
	//--------------------------------------------------------

	//--------------------------------------------------------
	/*! \fn SetmousePos This will update the current mouse position. 
	*Param One : RenderWindow - The main game window.
	*/
	void m_SetMousePos(sf::RenderWindow &window); 

	//--------------------------------------------------------
	/*! \fn GetMousePos Used to return the value of the mouse position. 
	*
	*/
	sf::Vector2f m_GetMousePos(); 

	/*! \fn UpdateMouseCurser : Used to move the mouse curser to the current position of the mouse
	*
	*/
	void m_UpdateMouseCurser();

	//--------------------------------------------------------
	//						Clicking
	//--------------------------------------------------------

	bool m_GetLMBDown();

	/*! \var GetLMBDown : Used to check if the left mouse button is pressed. 
	*Param One : Vector2f - The upper map bounds to check if the mouse is within a box.
	*Param Two : Vector2f - The lower map bounds to check if the mouse is within a box.
	*/
	bool m_GetLMBDown(sf::Vector2f mapUpperBounds, sf::Vector2f mapLowerBounds);

	//--------------------------------------------------------
	//						Selecting
	//--------------------------------------------------------

	//--------------------------------------------------------
	/*! \fn CreateSelectionBox : Used to create a selection box when the mouse button is pressed. 
	*
	*/
	void m_CreateSelectionBox(); 

	//--------------------------------------------------------
	/*! \fn GetTopLeftSelectonBox : Used to get check the bounds for the selection box. 
	*
	*/
	sf::Vector2f m_GetTopLeftSelectionBox();

	//--------------------------------------------------------
	/*! \fn GetBottomRightSelectonBox : Used to get check the bounds for the selection box.
	*
	*/
	sf::Vector2f m_GetBottomRightSelectionBox();

	//--------------------------------------------------------
	//						Rendering
	//--------------------------------------------------------

	//--------------------------------------------------------
	/*! \fn DrawSelectionBox : Used to draw the box into the game world.
	*Param One : RenderWindow - The main game window. 
	*/
	void m_DrawSelectionBox(sf::RenderWindow &window); 

	/*! \fn DrawMouseCurser : This will be use to draw the mouse curser onto the game window.
	*Param One : RenderWindow - The main game window to draw onto.
	*/
	void m_DrawMouseCurser(sf::RenderWindow& window);

	//--------------------------------------------------------
	//					Tool Tip Management
	//--------------------------------------------------------
	
	/*! \fn AssignToolTipFont : Used to set the font for the tool tips. 
	*Param One : Font - The ttf file associated with the font. 
	*/
	void m_AssignToolTipFont(sf::Font newFont);

	/*! \fn UpdateToolTip : Used to update the text displayed by the tool tip. 
	*Param One : String - The string which will be displayed.
	*Param Two : Vector2f - The position of the game view. 
	*Param Three : Vector2f - The size of the game view. 
	*/
	void m_UpdateTooltip(std::string dataToDisplay, sf::Vector2f viewPos, sf::Vector2f viewSize);

	/*! \fn DrawToolTip : This will be use to draw the tool tip onto the game window.
	*Param One : RenderWindow - The main game window to draw onto. 
	*/
	void m_DrawToolTip(sf::RenderWindow & window); 

};