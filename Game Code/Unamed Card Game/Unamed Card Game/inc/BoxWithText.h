#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class BoxWithText
{
	// Constructor 
	
public:

	BoxWithText();

	// Deconstructor 

	~BoxWithText();

	// Data Members 

private:

	std::shared_ptr<sf::Font> m_ptrMainFont; 

	sf::Text m_Text; 

	sf::RectangleShape m_BoxForText; 

	// Member Function

public:

	// Setup text/font

	void m_SetFont(sf::Font& font); 

	void m_SetText(std::string s); 

	void m_SetBoxSize(float width, float height);

	void m_SetSizeAndText(float width, float height, std::string s); 

	void m_SetPosition(float x, float y); 

	void m_ResizeText(); 

	// Draw elements

	void m_DrawText(sf::RenderWindow& window); 

};