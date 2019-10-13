#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "BoxWithText.h"

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

	/*! \var This object will form the border for the card and will hold all of the other 
				components within it. */
	sf::RectangleShape m_CardBody;

	/*! \var This box will hold a picture for the card. */
	sf::RectangleShape m_PortraitBox; 

	BoxWithText m_clNameText; 

	BoxWithText m_clHPText; 

	BoxWithText m_clSizeAndClassText; 

	// Member Functions 

public:

	// Setters
	
	/*! \fn SetName : Sets the name for this card. 
	Param One - String : The loaded cards name. 
	*/
	void m_SetName(std::string name);
	
	/*! \fn SetTribe : Sets the tribe/classification for this card. 
	Param One - String : The loaded cards Tribe. 
	*/
	void m_SetTribe(std::string tribe);

	/*! \fn SetSize : Sets the number of card slots it takes up. 
	Param One - String : The loaded cards Size.
	*/
	void m_SetSize(std::string size);

	/*! \fn SetHitPoints : Sets the number of Hp the card has.
	Param One - Int : The loaded cards Hit Points.
	*/
	void m_SetHitPoints(int hitpoints);

	/*! \fn SetAbilityOne : Creates the first card ability.
	Param One - String : The ability's Name.  
	Param Two - String : The Description for the ability. 
	Param Three - Int : The Speed for the ability/how quickly it will be performed.
	Param Four - Int : The Power for the ability/how much damage it will do.  
	*/
	void m_SetAbilityOne(std::string name, std::string desc, int speed, int power);

	/*! \fn SetAbilityTwo : Creates the second card ability.
	Param One - String : The ability's Name.
	Param Two - String : The Description for the ability.
	Param Three - Int : The Speed for the ability/how quickly it will be performed.
	Param Four - Int : The Power for the ability/how much damage it will do.
	*/
	void m_SetAbilityTwo(std::string name, std::string desc, int speed, int power);

	/*! \fn SetAbilityThree : Creates the third card ability.
	Param One - String : The ability's Name.
	Param Two - String : The Description for the ability.
	Param Three - Int : The Speed for the ability/how quickly it will be performed.
	Param Four - Int : The Power for the ability/how much damage it will do.
	*/
	void m_SetAbilityThree(std::string name, std::string desc, int speed, int power);

	/*! \fn SetMainCardFont : Stores the address of the font which will be used.
	Param One - Int : The loaded cards Hit Points.
	*/
	void m_SetMainCardFont(sf::Font &font);

	/*! \fn SetCardSize : Creates the main card body (the RectangleShape for the card).
	Param One - Float : The Width for the card.
	Param Two - Float : The Height for the card. 
	*/
	void m_SetCardSize(float width, float height); 

	// Getters 

	/*! \fn GetCardSize : This will return the size classification for the card between tiny and Huge.
	*/
	int m_GetCardSize(); 

	// Other

	/*! \fn PrintCardDetails : This will print to the console all of the details the card has loaded from file. 
	*/
	void m_PrintCardDetails(); 

	/*! \fn DrawCard : Using the main RenderWindow the card will be drawn onto the screen.
	Param One - RenderWindow : The main game widow. 
	*/
	void m_DrawCard(sf::RenderWindow &window); 

};