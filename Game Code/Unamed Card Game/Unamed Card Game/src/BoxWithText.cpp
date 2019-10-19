#include "BoxWithText.h"

BoxWithText::BoxWithText()
{
}

BoxWithText::~BoxWithText()
{
}

/*! \fn SetFont : This will set the font being used by the text.
Param One - sf::Font& : The address for the font being used.
*/
void BoxWithText::m_SetFont(sf::Font& font)
{
	m_ptrMainFont = &font;

	m_Text.setFont(*m_ptrMainFont);
}

/*! \fn SetText : This will set the string being used by the text.
Param One - String : The information being displayed.
*/
void BoxWithText::m_SetText(std::string s)
{
	m_Text.setString(s); 

	m_Text.setFillColor(sf::Color::Black);
}

/*! \fn SetBoxSize : This will create the box.
Param One - Float : The Width for the box.
Param Two - Float : The Height for the box.
*/
void BoxWithText::m_SetBoxSize(float width, float height)
{
	m_BoxForText.setSize(sf::Vector2f(width, height)); 

	m_BoxForText.setFillColor(sf::Color::Green); 
}

/*! \fn SetSizeAndText : This will set the string being used by the text
		and create the box at the same time.
Param One - Float : The Width for the box.
Param Two - Float : The Height for the box.
Param Three - String : The information being displayed.
*/
void BoxWithText::m_SetSizeAndText(float width, float height, std::string s)
{
	m_SetBoxSize(width, height);

	m_SetText(s);

	m_ResizeText(); 
}

void BoxWithText::m_SetSizeAndText(float width, float height, std::string s, unsigned int maxSize)
{
	m_SetBoxSize(width, height);

	m_SetText(s);

	m_ResizeText(maxSize);
}

/*! \fn SetPosition : This will move the box with the text to a new location in the window.
Param One - Float : The X coord.
Param Two - Float : The Y coord.
*/
void BoxWithText::m_SetPosition(float x, float y)
{
	m_BoxForText.setPosition(sf::Vector2f(x, y));
	m_Text.setPosition(sf::Vector2f(x, y));
}

/*! \fn ResizeText : This will ensure the text fits within the box if the box is resized.
*/
void BoxWithText::m_ResizeText()
{
	// Local Vars

	int l_iCharSize = 20, l_iMinSize = 9, l_iMaxSize = 20, l_iNumberOfLines = 1;

	// Text Sizing 

	do
	{
		l_iCharSize--; 

		// std::cout << std::to_string(l_iCharSize);

		if (l_iCharSize < l_iMinSize)
		{
			l_iNumberOfLines++;

			// If the text becomes too small then it will be wrapped, cutting the string into parts and 
			// placing the parts on seperate line allowing the text on each line to be bigger. 

			m_WrapText(l_iNumberOfLines);

			l_iCharSize = l_iMaxSize;
		}

		m_Text.setCharacterSize(l_iCharSize);

	} while (m_Text.getGlobalBounds().width > m_BoxForText.getGlobalBounds().width);

	// std::cout << std::endl;
}

/*! \fn ResizeText : This will ensure the text fits within the box if the box is resized.
*/
void BoxWithText::m_ResizeText(unsigned int maxSize)
{
	// Local Vars

	int l_iCharSize = maxSize, l_iMinSize = maxSize / 2, l_iMaxSize = maxSize, l_iNumberOfLines = 1;

	// Text Sizing 

	do
	{
		l_iCharSize--;

		// std::cout << std::to_string(l_iCharSize);

		if (l_iCharSize < l_iMinSize)
		{
			l_iNumberOfLines++;

			m_WrapText(l_iNumberOfLines);

			l_iCharSize = l_iMaxSize;
		}

		m_Text.setCharacterSize(l_iCharSize);

	} while ((m_Text.getGlobalBounds().width > m_BoxForText.getGlobalBounds().width) ||
		(m_Text.getGlobalBounds().height > m_BoxForText.getGlobalBounds().height));

	std::cout << std::endl;
}

void BoxWithText::m_WrapText(unsigned int numberofLines)
{
	// Local Variables

	std::string l_sOrigionalText; 

	std::vector<std::string> v_TextPartitions; 

	int l_iStringSize, l_iSegments; 

	// Wrapping Text 
	
	l_sOrigionalText = m_Text.getString();

	l_iStringSize = l_sOrigionalText.length();

	l_iSegments = l_iStringSize / numberofLines; 

	v_TextPartitions.resize(numberofLines);

	int l_iCurrPos = 0;

	for (unsigned int i = 0; i < v_TextPartitions.size(); i++)
	{
		std::string l_sThisLine;  
		
		for (unsigned int j = l_iCurrPos; j < l_iCurrPos + l_iSegments; j++)
		{
			if (l_sOrigionalText.size() >= j)
			{
				if (l_sOrigionalText[j] == 10) // ASCI code for '\n'
				{
					j += 1;
				}

				l_sThisLine += l_sOrigionalText[j];
			}
		}

		// std::cout << l_sThisLine << std::endl;

		v_TextPartitions.at(i) = (l_sThisLine);

		l_iCurrPos += l_iSegments;
	}

	std::string l_sFinalString;

	for (unsigned int i = 0; i < v_TextPartitions.size(); i++)
	{
		l_sFinalString += v_TextPartitions[i] + "\n"; 
	}

	m_Text.setString(l_sFinalString); 

}

/*! \fn DrawText : This will draw the text into the window (Box Optional)
Param One - RenderWindow : The main game window
*/
void BoxWithText::m_DrawText(sf::RenderWindow& window)
{

	window.draw(m_Text); 
}

/*! \fn DrawText : This will draw the text into the window (Box Optional)
Param One - RenderWindow : The main game window. 
Param Two - Bool : select if the box will be drawn (Yes == True).
*/
void BoxWithText::m_DrawText(sf::RenderWindow& window, bool drawBox)
{
	if (drawBox)
	{
		window.draw(m_BoxForText); 
	}

	window.draw(m_Text);
}
