#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>

template <class T>
class ResourceManager
{

	// Data Members 

private:

	std::map<std::string, T> m_ResourceMap; 

	// Member Functions 

public:

	void m_AddietmToMap(std::string id, T elementToAdd)
	{
		m_ResourceMap.insert<std::make_pair(id, elementToAdd)>; 
	}

	T& m_GetItemFromMap(std::string id)
	{
		return m_ResourceMap[id]; 
	}

};

template <>
class ResourceManager <sf::Font>
{
	// Data Members 

private:

	std::map<std::string, sf::Font> m_ResourceMap;

	// Member Functions 

public:

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