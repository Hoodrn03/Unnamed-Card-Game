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

	int m_iHitPoints; 

	std::string m_Tribe; 

	ability m_AbliltyOne; 

	ability m_AbilityTwo;

	ability m_AbilityThree;

	// Member Functions 

public:


};