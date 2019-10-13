#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>

/*! \class Resource Manager : This will allow for a manager to be created, it will allow for the object T to be defined as 
			anything and this will create a map of a string ID and a T value which will be managed. */
template <class T>
class ResourceManager
{

	// Data Members 

private:

	/*! \var This is the map which will be managed by this class and it is a varing map, 
			with the pair of String (an ID) and T the main type to be managed. */
	std::map<std::string, T> m_ResourceMap; 

	// Member Functions 

public:

	/*! \fn AddItemToMap : This will allow for an item to be added into the map.
	Param One - String : The id for the item allowing for it to be referenced later.
	Param Two - T : The class type for the map to be added.
	*/
	void m_AddietmToMap(std::string id, T elementToAdd)
	{
		if (!m_ResourceMap.find(id))
		{
			m_ResourceMap.insert<std::make_pair(id, elementToAdd)>;
		}
	}

	/*! \fn GetItemFromMap : This will be used to get an item from the map. 
	Param One - String : The id for the ietm you want from the map. 
	*/
	T& m_GetItemFromMap(std::string id)
	{
		return m_ResourceMap[id]; 
	}

};

/*! \class ResourceManager (Sp - sf::Font) : This will create a resource manager for sf::Fonts, it will have a map 
			for Strings (The Id) and Fonts which are loaded from file (.ttf files). */
template <>
class ResourceManager <sf::Font>
{
	// Data Members 

private:

	/*! \var This is the resource manager for a pair of strings and fonts it will hold all of the fonts used within the game. */
	std::map<std::string, sf::Font> m_ResourceMap;

	// Member Functions 

public:

	/*! \fn LoadFontFromFile : This will load a font from file into the game. 
	Param One - String : The Id for the new font when adding into the map. 
	Param Two - String : The file path for the font to load.
	*/
	void m_LoadFontFromFile(std::string id, std::string filePath)
	{
		sf::Font l_TempFont; 

		if (l_TempFont.loadFromFile(filePath))
		{
			std::cout << "File: " << filePath << " Found and assigned the id: " << id << std::endl;

			m_ResourceMap.insert(std::make_pair(id, l_TempFont)); 
		}
		else
		{
			std::cout << "Unable to load from file: " << filePath << ", " << id << "Not loaded into game." << std::endl;
		}
	}

	/*! \fn GetItemFromMap : This will be used to get an item from the map.
	Param One - String : The id for the ietm you want from the map.
	*/
	sf::Font& m_GetItemFromMap(std::string id)
	{
		std::map<std::string, sf::Font>::iterator l_It;

		l_It = m_ResourceMap.find(id);

		if (l_It != m_ResourceMap.end())
		{
			return m_ResourceMap.at(id);
		}

		std::cout << "Unble to find element" << std::endl;

		sf::Font l_EmptyFont; 

		return l_EmptyFont;
	}
};