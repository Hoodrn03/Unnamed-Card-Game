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
