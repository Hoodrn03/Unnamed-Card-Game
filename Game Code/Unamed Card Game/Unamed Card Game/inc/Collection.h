#pragma once

#include <iostream>
#include <vector>

#include "PUGIXML/pugixml.hpp"


#include "Card.h"

class Collection
{
	// Constructor 

public:

	Collection();

	// Deconstructor 

	~Collection();

	// Data Members 

private:

	std::vector<Card> v_clCardCollection;

	const sf::Vector2f m_SmallCard = sf::Vector2f(200, 250);

	const sf::Vector2f m_MediumCard = sf::Vector2f(400, 250);;

	const sf::Vector2f m_LargeCard = sf::Vector2f(600, 250);;

	// Member Functions 

public:

	// Setters 

	void m_SetFontsForCards(sf::Font& font); 

	// Getters 

	Card m_GetCard(int index);

	// Creators 

	void m_CreateCardBodies();

	void m_CreateCardBodies(float width, float height); 

	// Loading from files

	void m_LoadCardCollectionFromFile(std::string filePath); 

};