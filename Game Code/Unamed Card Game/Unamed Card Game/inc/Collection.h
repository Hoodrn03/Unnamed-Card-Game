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

	// Member Functions 

public:

	void m_LoadCardCollectionFromFile(std::string filePath); 
};