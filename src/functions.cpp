/*
 * functions.cpp
 *
 *  Created on: 11 jun. 2015
 *      Author: Robin
 */


#include <pugixml.hpp>
#include <json/json.h>
#include <iostream>
#include <fstream>

#include "functions.h"
#include "XmlConstants.h"
#include "JsonConstants.h"

void Start(const char* path, const char* diciplineName, eWeaponType weapon)
{
	pugi::xml_document doc;
	doc.load_file(path);

	//Load all the abilities.
	abilityVec list = LoadAbilities(doc.child(XML_CONSTANTS.ABILTIES));

	//Load the json for stat distribution values.
	LoadGearJson();
}

abilityVec LoadAbilities(pugi::xml_node parentNode)
{
	abilityVec list;

	const XmlAbilityConstants& abilityConstants = XML_CONSTANTS.ABILTIY;

	for (pugi::xml_node abilityNode = parentNode.first_child(); abilityNode; abilityNode = abilityNode.next_sibling())
	{
		//Get the name;
		const char* name = abilityNode.child_value(abilityConstants.NAME);

		//Setup the ability
		Ability ability = Ability(abilityNode.child(abilityConstants.CONTRIBUTION).text().as_double(),
				abilityNode.child(abilityConstants.COOLDOWN).text().as_double(), name);

		const XmlAbilityDamageTickConstants& tickConstants = abilityConstants.DAMAGE_CONSTANTS.TICK;

		//TODO: Write the stat reader down here in a component system so extending it won't be a problem anymore. -Robin

		//Now add each tick to ability.
		for (pugi::xml_node tickNode = abilityNode.child(abilityConstants.DAMAGE).first_child(); tickNode; tickNode = tickNode.next_sibling())
		{
			//TODO: So you want to iterate over all the components over here. -Robin

			double coefficient = GetDoubleFromNode(tickConstants.COEFFICIENT, tickNode);
			double amountModifierPercent = GetDoubleFromNode(tickConstants.AMOUNT_MODIFIER_PERCENT, tickNode);
			double stdHealthMin = GetDoubleFromNode(tickConstants.STD_HEALTH_MIN, tickNode);
			double stdHealthMax = GetDoubleFromNode(tickConstants.STD_HEALTH_MAX, tickNode);
			//TODO: design crit loader around the new crit sytem. -Robin
			double critBonus = GetDoubleFromNode(tickConstants.CRIT_BONUS, tickNode);
			int surgeBonus = GetIntFromNode(tickConstants.CRIT_MULTIPLIER_BONUS, tickNode);
			int armorPenetration = GetIntFromNode(tickConstants.ARMOR_PENETRATION, tickNode);

			//Get the total of all the additive multipliers
			int additiveMultiplier = 0;
			for (pugi::xml_node addMultNode = tickNode.child(tickConstants.ADDITIVE_MULTIPLIER).first_child();
					addMultNode; addMultNode = addMultNode.next_sibling())
			{
				//Additive so add.
				additiveMultiplier += GetIntFromNode(tickConstants.MULTIPLIER_VALUE, addMultNode);
			}

			double multiplicativeMultiplier = 1;
			for (pugi::xml_node addMultNode = tickNode.child(tickConstants.MULTIPLICATIVE_MULTIPLIER).first_child();
					addMultNode; addMultNode = addMultNode.next_sibling())
			{
				//Multiplicative so multiply.
				multiplicativeMultiplier *= GetDoubleFromNode(tickConstants.MULTIPLIER_VALUE, addMultNode);
			}

			AbilityTick tick = AbilityTick(name, coefficient, amountModifierPercent, stdHealthMin, stdHealthMax, additiveMultiplier,
					multiplicativeMultiplier, critBonus, surgeBonus, armorPenetration);

			//Add the tick the the ability.
			ability.AddTick(tick);
		}

		//Finally push the ability to the vector.
		list.push_back(ability);
	}

	return list;
}

void LoadGearJson()
{
	Json::Value root;
	Json::Reader reader;
	std::ifstream fileInput;
	fileInput.open(StatDistributionPath, std::ifstream::binary);

	if (reader.parse(fileInput, root, false))
		std::cout << reader.getFormattedErrorMessages() << std::endl;

	std::cout << root.get("gear_levels", 10)[1].get("level", 0).asInt();
}

inline double GetDoubleFromNode(const char* nodeName, pugi::xml_node& parentNode)
{
	return parentNode.child(nodeName).text().as_double();
}

inline int GetIntFromNode(const char* aNodeName, pugi::xml_node& parentNode)
{
	return parentNode.child(aNodeName).text().as_int();
}
