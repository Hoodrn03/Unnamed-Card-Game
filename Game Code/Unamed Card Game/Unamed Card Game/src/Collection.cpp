#include "Collection.h"

Collection::Collection()
{
}

Collection::~Collection()
{
}

Card Collection::m_GetCard(int index)
{
	return v_clCardCollection[index];
}

void Collection::m_LoadCardCollectionFromFile(std::string filePath)
{
	
	// Load XML file

	pugi::xml_document l_doc;

	pugi::xml_parse_result l_result = l_doc.load_file(filePath.c_str(), pugi::parse_default|pugi::parse_declaration);

	// Check to see if file is open

	if (!l_result)
	{
		std::cout << "Parse error: " << l_result.description() << ", character pos= " << l_result.offset;
	}

	std::cout << "File: " << filePath << ", Opened." << std::endl;

	// Create Querys
	// The queries will alow for data to be found within the initial node.

	pugi::xpath_query l_cardQuery("/Collection/Card");

	pugi::xpath_query l_nameQuery("Name/text()");
	pugi::xpath_query l_healthQuery("HP/text()");
	pugi::xpath_query l_sizeQuery("Size/text()");
	pugi::xpath_query l_tribeQuery("Tribe/text()");
	pugi::xpath_query l_portraitQuery("Portrait/text()");
	pugi::xpath_query l_abiNameOneQuery("AbilityNameOne/text()");
	pugi::xpath_query l_abiDesOneQuery("AbilityDescriptionOne/text()");
	pugi::xpath_query l_abiSpeedOneQuery("AbilitySpeedOne/text()");
	pugi::xpath_query l_abiPowOneQuery("AbilityPowerOne/text()");
	pugi::xpath_query l_abiNameTwoQuery("AbilityNameTwo/text()");
	pugi::xpath_query l_abiDesTwoQuery("AbilityDescriptionTwo/text()");
	pugi::xpath_query l_abiSpeedTwoQuery("AbilitySpeedTwo/text()");
	pugi::xpath_query l_abiPowTwoQuery("AbilityPowerTwo/text()");

	// Parse Data

	pugi::xpath_node_set l_colletcion = l_doc.select_nodes(l_cardQuery);

	for (pugi::xpath_node l_card : l_colletcion)
	{
		pugi::xml_node l_currCard = l_card.node();

		// Collect Data for current card. 
		// Using the querys from above store the data into a node holding that xml information. 

		pugi::xml_node l_currName = l_currCard.select_node(l_nameQuery).node();
		pugi::xml_node l_currHealth = l_currCard.select_node(l_healthQuery).node();
		pugi::xml_node l_currSize = l_currCard.select_node(l_sizeQuery).node();
		pugi::xml_node l_currTribe = l_currCard.select_node(l_tribeQuery).node();
		pugi::xml_node l_currPort = l_currCard.select_node(l_portraitQuery).node();
		pugi::xml_node l_currANO = l_currCard.select_node(l_abiNameOneQuery).node();
		pugi::xml_node l_currADO = l_currCard.select_node(l_abiDesOneQuery).node();
		pugi::xml_node l_currASO = l_currCard.select_node(l_abiSpeedOneQuery).node();
		pugi::xml_node l_currAPO = l_currCard.select_node(l_abiPowOneQuery).node();
		pugi::xml_node l_currANT = l_currCard.select_node(l_abiNameTwoQuery).node();
		pugi::xml_node l_currADT = l_currCard.select_node(l_abiDesTwoQuery).node();
		pugi::xml_node l_currAST = l_currCard.select_node(l_abiSpeedTwoQuery).node();
		pugi::xml_node l_currAPT = l_currCard.select_node(l_abiPowTwoQuery).node();
		
		// Create card

		Card l_TempCard;

		l_TempCard.m_SetName(l_currName.value());
		l_TempCard.m_SetHitPoints(std::atoi(l_currHealth.value()));
		l_TempCard.m_SetSize(l_currSize.value());
		l_TempCard.m_SetTribe(l_currTribe.value());
		l_TempCard.m_SetAbilityOne(l_currANO.value(), l_currADO.value(), std::atoi(l_currASO.value()), std::atoi(l_currAPO.value()));
		l_TempCard.m_SetAbilityTwo(l_currANT.value(), l_currADT.value(), std::atoi(l_currAST.value()), std::atoi(l_currAPT.value()));

		// Add card into collection. 

		l_TempCard.m_PrintCardDetails();

		v_clCardCollection.push_back(l_TempCard);
	}

	std::cout << "Current card count: " << v_clCardCollection.size() << std::endl;

}

