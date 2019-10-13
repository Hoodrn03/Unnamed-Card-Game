#include "Card.h"

Card::Card()
{
	
}

Card::~Card()
{
}

/*! \fn SetName : Sets the name for this card.
Param One - String : The loaded cards name.
*/
void Card::m_SetName(std::string name)
{
	m_sCardName = name;
}

/*! \fn SetTribe : Sets the tribe/classification for this card.
Param One - String : The loaded cards Tribe.
*/
void Card::m_SetTribe(std::string tribe)
{
	m_sTribe = tribe;
}

/*! \fn SetSize : Sets the number of card slots it takes up.
Param One - String : The loaded cards Size.
*/
void Card::m_SetSize(std::string size)
{
	m_sSize = size;
}

/*! \fn SetHitPoints : Sets the number of Hp the card has.
Param One - Int : The loaded cards Hit Points.
*/
void Card::m_SetHitPoints(int hitpoints)
{
	m_iHitPoints = hitpoints;
}

/*! \fn SetAbilityOne : Creates the first card ability.
Param One - String : The ability's Name.
Param Two - String : The Description for the ability.
Param Three - Int : The Speed for the ability/how quickly it will be performed.
Param Four - Int : The Power for the ability/how much damage it will do.
*/
void Card::m_SetAbilityOne(std::string name, std::string desc, int speed, int power)
{
	m_AbililtyOne.name = name;
	m_AbililtyOne.description = desc;
	m_AbililtyOne.speed = speed;
	m_AbililtyOne.power = power;
}

/*! \fn SetAbilityTwo : Creates the second card ability.
Param One - String : The ability's Name.
Param Two - String : The Description for the ability.
Param Three - Int : The Speed for the ability/how quickly it will be performed.
Param Four - Int : The Power for the ability/how much damage it will do.
*/
void Card::m_SetAbilityTwo(std::string name, std::string desc, int speed, int power)
{
	m_AbilityTwo.name = name;
	m_AbilityTwo.description = desc;
	m_AbilityTwo.speed = speed;
	m_AbilityTwo.power = power;
}

/*! \fn SetAbilityThree : Creates the third card ability.
Param One - String : The ability's Name.
Param Two - String : The Description for the ability.
Param Three - Int : The Speed for the ability/how quickly it will be performed.
Param Four - Int : The Power for the ability/how much damage it will do.
*/
void Card::m_SetAbilityThree(std::string name, std::string desc, int speed, int power)
{
	m_AbilityThree.name = name;
	m_AbilityThree.description = desc;
	m_AbilityThree.speed = speed;
	m_AbilityThree.power = power; 
}

/*! \fn SetMainCardFont : Stores the address of the font which will be used.
Param One - Int : The loaded cards Hit Points.
*/
void Card::m_SetMainCardFont(sf::Font& font)
{
	
}

/*! \fn SetCardSize : Creates the main card body (the RectangleShape for the card).
Param One - Float : The Width for the card.
Param Two - Float : The Height for the card.
*/
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

/*! \fn GetCardSize : This will return the size classification for the card between tiny and Huge.
*/
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

/*! \fn PrintCardDetails : This will print to the console all of the details the card has loaded from file.
*/
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

/*! \fn DrawCard : Using the main RenderWindow the card will be drawn onto the screen.
Param One - RenderWindow : The main game widow.
*/
void Card::m_DrawCard(sf::RenderWindow &window)
{
	window.draw(m_CardBody);
	window.draw(m_PortraitBox); 

}
