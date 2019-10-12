#include "BoxWithText.h"

BoxWithText::BoxWithText()
{
}

BoxWithText::~BoxWithText()
{
}

void BoxWithText::m_SetFont(sf::Font& font)
{
	m_ptrMainFont.reset(&font);

	m_Text.setFont(*m_ptrMainFont);
}

void BoxWithText::m_SetText(std::string s)
{
	m_Text.setString(s); 
}

void BoxWithText::m_SetBoxSize(float width, float height)
{
	m_BoxForText.setSize(sf::Vector2f(width, height)); 

	m_BoxForText.setFillColor(sf::Color::Green); 
}

void BoxWithText::m_SetSizeAndText(float width, float height, std::string s)
{
	m_SetBoxSize(width, height);

	m_SetText(s);

	m_ResizeText(); 
}

void BoxWithText::m_SetPosition(float x, float y)
{
	m_BoxForText.setPosition(sf::Vector2f(x, y));
	m_Text.setPosition(sf::Vector2f(x, y));
}

void BoxWithText::m_ResizeText()
{
	int l_iCharSize = 31;

	do
	{
		l_iCharSize--; 

		m_Text.setCharacterSize(l_iCharSize);

	} while (m_Text.getGlobalBounds().width > m_BoxForText.getGlobalBounds().width);
}

void BoxWithText::m_DrawText(sf::RenderWindow& window)
{
	// To see the bounds for the text uncomment the draw section for the box. 
	// window.draw(m_BoxForText); 

	window.draw(m_Text); 
}
