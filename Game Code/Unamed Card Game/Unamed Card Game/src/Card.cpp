#include "Card.h"

Card::Card()
{
	
}

Card::~Card()
{
}

void Card::m_SetName(std::string name)
{
	m_sCardName = name;
}

void Card::m_SetTribe(std::string tribe)
{
	m_sTribe = tribe;
}

void Card::m_SetSize(std::string size)
{
	m_sSize = size;
}

void Card::m_SetHitPoints(int hitpoints)
{
	m_iHitPoints = hitpoints;
}

void Card::m_SetAbilityOne(std::string name, std::string desc, int speed, int power)
{
	m_AbililtyOne.name = name;
	m_AbililtyOne.description = desc;
	m_AbililtyOne.speed = speed;
	m_AbililtyOne.power = power;
}

void Card::m_SetAbilityTwo(std::string name, std::string desc, int speed, int power)
{
	m_AbilityTwo.name = name;
	m_AbilityTwo.description = desc;
	m_AbilityTwo.speed = speed;
	m_AbilityTwo.power = power;
}

void Card::m_SetAbilityThree(std::string name, std::string desc, int speed, int power)
{
	m_AbilityThree.name = name;
	m_AbilityThree.description = desc;
	m_AbilityThree.speed = speed;
	m_AbilityThree.power = power; 
}

void Card::m_SetMainCardFont(sf::Font* font)
{
	m_ptrMainFont.reset(font);
}

void Card::m_SetCardSize(float width, float height)
{
	m_CardBody.setSize(sf::Vector2f(width, height));
	m_CardBody.setPosition(sf::Vector2f(20, 30));
	m_CardBody.setFillColor(sf::Color::White);

	m_PortraitBox.setSize(sf::Vector2f(m_CardBody.getGlobalBounds().width * 0.8f, m_CardBody.getGlobalBounds().height * 0.3f));
	m_PortraitBox.setPosition(sf::Vector2f(m_CardBody.getGlobalBounds().width * 0.1f + m_CardBody.getPosition().x, 
		m_CardBody.getGlobalBounds().height * 0.1f + m_CardBody.getPosition().y));
	m_PortraitBox.setFillColor(sf::Color::Blue);
}

int Card::m_GetCardSize()
{
	if (m_sSize == "Tiny")
	{
		return 1;
	}
	else if (m_sSize == "Small")
	{
		return 1;
	}
	else if (m_sSize == "Medium")
	{
		return 1;
	}
	else if (m_sSize == "Large")
	{
		return 2;
	}
	else
	{
		return 3;
	}

	return -1;
}



void Card::m_PrintCardDetails()
{
	// Print Data 

	std::cout << "------------------------------"  << std::endl;

	std::cout << "Current Name: " << m_sCardName << std::endl;
	std::cout << "Current Hp: " << m_iHitPoints << std::endl;
	std::cout << "Current Size: " << m_sSize << std::endl;
	std::cout << "Current Tribe: " << m_sTribe << std::endl;
	std::cout << "Current Portrait: " << "NULL" << std::endl;
	std::cout << "Current Ability One Name: " << m_AbililtyOne.name << std::endl;
	std::cout << "Current Ability One Description: " << m_AbililtyOne.description << std::endl;
	std::cout << "Current Ability One Speed: " << m_AbililtyOne.speed << std::endl;
	std::cout << "Current Ability One Power: " << m_AbililtyOne.power << std::endl;
	std::cout << "Current Ability Two Name: " << m_AbilityTwo.name << std::endl;
	std::cout << "Current Ability Two Description: " << m_AbilityTwo.description << std::endl;
	std::cout << "Current Ability Two Speed: " << m_AbilityTwo.speed << std::endl;
	std::cout << "Current Ability Two Power: " << m_AbilityTwo.power << std::endl;
}

void Card::m_DrawCard(sf::RenderWindow &window)
{
	window.draw(m_CardBody);
	window.draw(m_PortraitBox); 

}
