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
	m_AbliltyOne.name = name;
	m_AbliltyOne.description = desc;
	m_AbliltyOne.speed = speed;
	m_AbliltyOne.power = power; 
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

void Card::m_PrintCardDetails()
{
	// Print Data 

	std::cout << "------------------------------"  << std::endl;

	std::cout << "Current Name: " << m_sCardName << std::endl;
	std::cout << "Current Hp: " << m_iHitPoints << std::endl;
	std::cout << "Current Size: " << m_sSize << std::endl;
	std::cout << "Current Tribe: " << m_sTribe << std::endl;
	std::cout << "Current Portrait: " << "NULL" << std::endl;
	std::cout << "Current Ability One Name: " << m_AbliltyOne.name << std::endl;
	std::cout << "Current Ability One Description: " << m_AbliltyOne.description << std::endl;
	std::cout << "Current Ability One Speed: " << m_AbliltyOne.speed << std::endl;
	std::cout << "Current Ability One Power: " << m_AbliltyOne.power << std::endl;
	std::cout << "Current Ability Two Name: " << m_AbilityTwo.name << std::endl;
	std::cout << "Current Ability Two Description: " << m_AbilityTwo.description << std::endl;
	std::cout << "Current Ability Two Speed: " << m_AbilityTwo.speed << std::endl;
	std::cout << "Current Ability Two Power: " << m_AbilityTwo.power << std::endl;
}
