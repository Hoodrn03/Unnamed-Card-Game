#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

/*! \struct An ability for the card, it will have a name and a desctription of what it does, 
		as well as a speed (how quickly it will trigger) and a power for how much damage it 
		will do. 
*/
struct ability
{
	std::string name, description;

	int speed = 0, power = 0; 
};

/*! \class This will hold a single card object within the card collection. */
class Card
{
	// Constructor 

public:

	Card();

	// Deconstructor 

	~Card();

	// Data Members 

private:

	// Card Data

	/*! \var This is the name of the card. */
	std::string m_sCardName; 

	/*! \var This is the tribe the card belongs to, allows for card interactions. */
	std::string m_sTribe; 

	/*! \var This is the size of the card, determines how many card slots it takes up. */
	std::string m_sSize;

	/*! \var This will be the file location for the card's portrait. */
	std::string m_sPortrait;

	/*! \var This will be the life of the card, it will determine how many hits it can take 
				before being defeted. */
	int m_iHitPoints = 0;

	/*! \var This is the first ability slot for the card, holding a basic attack. */
	ability m_AbililtyOne; 

	/*! \var This will be the second ability slot for the card normaly holding a effect based
	attack/defence. */
	ability m_AbilityTwo;
#
	/*! \var This ability slot is for larger creatures which take up multiple spaces on the board, 
			it allows for more flexibility with choosing bigger cards. */
	ability m_AbilityThree;

	// Card Drawing Objects

	std::shared_ptr<sf::Font> m_ptrMainFont;

	sf::RectangleShape m_CardBody;

	sf::Text m_NameText;

	sf::Text m_HitPointText; 

	sf::RectangleShape m_PortraitBox; 

	sf::Text m_SizeAndTribeText; 

	sf::Text m_AbilityOneNameAndDesc; 

	sf::Text m_AbilityOneSpeedAndPow; 

	sf::Text m_AbilityTwoNameAndDesc;

	sf::Text m_AbilityTwoSpeedAndPow;

	sf::Text m_AbilityThreeNameAndDesc;

	sf::Text m_AbilityThreeSpeedAndPow;

	// Member Functions 

public:

	void m_SetName(std::string name);

	void m_SetTribe(std::string tribe);

	void m_SetSize(std::string size);

	void m_SetHitPoints(int hitpoints);

	void m_SetAbilityOne(std::string name, std::string desc, int speed, int power);

	void m_SetAbilityTwo(std::string name, std::string desc, int speed, int power);

	void m_SetAbilityThree(std::string name, std::string desc, int speed, int power);

	void m_SetMainCardFont(sf::Font *font);

	void m_SetCardSize(float width, float height); 

	int m_GetCardSize(); 

	void m_PrintCardDetails(); 

	void m_DrawCard(sf::RenderWindow &window); 

};