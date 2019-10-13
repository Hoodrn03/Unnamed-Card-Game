#include "BoxWithText.h"

BoxWithText::BoxWithText()
{
}

BoxWithText::~BoxWithText()
{
}

/*! \fn SetFont : This will set the font being used by the text.
Param One - sf::Font& : The address for the font being used.
*/
void BoxWithText::m_SetFont(sf::Font& font)
{
	m_ptrMainFont = &font;

	m_Text.setFont(*m_ptrMainFont);
}

/*! \fn SetText : This will set the string being used by the text.
Param One - String : The information being displayed.
*/
void BoxWithText::m_SetText(std::string s)
{
	m_Text.setString(s); 

	m_Text.setFillColor(sf::Color::Black);
}

/*! \fn SetBoxSize : This will create the box.
Param One - Float : The Width for the box.
Param Two - Float : The Height for the box.
*/
void BoxWithText::m_SetBoxSize(float width, float height)
{
	m_BoxForText.setSize(sf::Vector2f(width, height)); 

	m_BoxForText.setFillColor(sf::Color::Green); 
}

/*! \fn SetSizeAndText : This will set the string being used by the text
		and create the box at the same time.
Param One - Float : The Width for the box.
Param Two - Float : The Height for the box.
Param Three - String : The information being displayed.
*/
void BoxWithText::m_SetSizeAndText(float width, float height, std::string s)
{
	m_SetBoxSize(width, height);

	m_SetText(s);

	m_ResizeText(); 
}

/*! \fn SetPosition : This will move the box with the text to a new location in the window.
Param One - Float : The X coord.
Param Two - Float : The Y coord.
*/
void BoxWithText::m_SetPosition(float x, float y)
{
	m_BoxForText.setPosition(sf::Vector2f(x, y));
	m_Text.setPosition(sf::Vector2f(x, y));
}

/*! \fn ResizeText : This will ensure the text fits within the box if the box is resized.
*/
void BoxWithText::m_ResizeText()
{
	int l_iCharSize = 20;

	do
	{
		l_iCharSize--; 

		m_Text.setCharacterSize(l_iCharSize);

	} while ((m_Text.getGlobalBounds().width > m_BoxForText.getGlobalBounds().width) 
		|| (m_Text.getGlobalBounds().height > m_BoxForText.getGlobalBounds().height));
}

/*! \fn DrawText : This will draw the text into the window (Box Optional)
Param One - RenderWindow : The main game window
*/
void BoxWithText::m_DrawText(sf::RenderWindow& window)
{

	window.draw(m_Text); 
}

/*! \fn DrawText : This will draw the text into the window (Box Optional)
Param One - RenderWindow : The main game window. 
Param Two - Bool : select if the box will be drawn (Yes == True).
*/
void BoxWithText::m_DrawText(sf::RenderWindow& window, bool drawBox)
{
	if (drawBox)
	{
		window.draw(m_BoxForText); 
	}

	window.draw(m_Text);
}
