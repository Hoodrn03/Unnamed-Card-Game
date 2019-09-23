#pragma once

#include <iostream>

/*! \struct An ability for the card, it will have a name and a desctription of what it does, 
		as well as a speed (how quickly it will trigger) and a power for how much damage it 
		will do. 
*/
struct ability
{
	std::string name, description;

	int speed, power; 
};

class Card
{
	// Constructor 

public:

	Card();

	// Deconstructor 

	~Card();

	// Data Members 

private:

	std::string m_sCardName; 

	std::string m_sTribe; 

	std::string m_sSize;

	std::string m_sPortrait;

	int m_iHitPoints;

	ability m_AbliltyOne; 

	ability m_AbilityTwo;

	ability m_AbilityThree;

	// Member Functions 

public:

	void m_SetName(std::string name);

	void m_SetTribe(std::string tribe);

	void m_SetSize(std::string size);

	void m_SetHitPoints(int hitpoints);

	void m_SetAbilityOne(std::string name, std::string desc, int speed, int power);

	void m_SetAbilityTwo(std::string name, std::string desc, int speed, int power);

	void m_SetAbilityThree(std::string name, std::string desc, int speed, int power);

};