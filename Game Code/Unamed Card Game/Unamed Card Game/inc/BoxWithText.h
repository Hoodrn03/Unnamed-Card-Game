#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

/*! \class BoxWithText : This will allow for the simple creation and placement of a box with text 
			placed perfectly within it. */
class BoxWithText
{
	// Constructor 
	
public:

	BoxWithText();

	// Deconstructor 

	~BoxWithText();

	// Data Members 

private:

	/*! \var A pointer to the address of a font used by the text in this box. */
	sf::Font* m_ptrMainFont = &sf::Font(); 

	/*! \var The text information being displayed im the box. */
	sf::Text m_Text; 

	/*! \var The box which the text will be placed within. */
	sf::RectangleShape m_BoxForText; 

	// Member Function

public:

	// Setup text/font
	
	/*! \fn SetFont : This will set the font being used by the text.
	Param One - sf::Font& : The address for the font being used. 
	*/
	void m_SetFont(sf::Font& font); 

	/*! \fn SetText : This will set the string being used by the text.
	Param One - String : The information being displayed.
	*/
	void m_SetText(std::string s); 

	/*! \fn SetBoxSize : This will create the box.
	Param One - Float : The Width for the box.
	Param Two - Float : The Height for the box. 
	*/
	void m_SetBoxSize(float width, float height);

	/*! \fn SetSizeAndText : This will set the string being used by the text 
			and create the box at the same time.
	Param One - Float : The Width for the box.
	Param Two - Float : The Height for the box.
	Param Three - String : The information being displayed.
	*/
	void m_SetSizeAndText(float width, float height, std::string s); 

	/*! \fn SetPosition : This will move the box with the text to a new location in the window.
	Param One - Float : The X coord.
	Param Two - Float : The Y coord.  
	*/
	void m_SetPosition(float x, float y); 

	/*! \fn ResizeText : This will ensure the text fits within the box if the box is resized.
	*/
	void m_ResizeText(); 

	// Draw elements

	/*! \fn DrawText : This will draw the text into the window.
	Param One - RenderWindow : The main game window
	*/
	void m_DrawText(sf::RenderWindow& window);

	/*! \fn DrawText (Overload): This will draw the text into the window (Box Optional).
	Param One - RenderWindow : The main game window.
	Param Two - Bool : select if the box will be drawn (Yes == True).
	*/
	void m_DrawText(sf::RenderWindow& window, bool drawBox);


};