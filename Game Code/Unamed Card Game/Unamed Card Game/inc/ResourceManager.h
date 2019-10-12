#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

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
		std::map<std::string, T>::iterator l_It;

		l_It = m_ResourceMap.find(id);

		if (l_It != m_ResourceMap.end())
		{
			return m_ResourceMap.at(id); 
		}

		std::cout << "Unble to find element" << std::endl;
			 
		return T(); 
	}

};