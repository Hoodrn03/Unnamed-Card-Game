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

	// Member Function

public:

};