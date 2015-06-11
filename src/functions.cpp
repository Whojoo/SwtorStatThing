/*
 * functions.cpp
 *
 *  Created on: 11 jun. 2015
 *      Author: Robin
 */

#include <iostream>

#include "functions.h"
#include "Ability.h"
#include "XmlConstants.h"

void Start(const char* aPath)
{
	pugi::xml_document doc;
	doc.load_file(aPath);

	//Load all the abilities.
	abilityList list = LoadAbilities(doc.child(Abilities));

	//Test if everything went according to plan.
//	for (abilityList::iterator it = list.begin(); it != list.end(); ++it)
//		std::cout << it->First()->coefficient << std::endl;
}

abilityList LoadAbilities(pugi::xml_node aParentNode)
{
	abilityList list;

	for (pugi::xml_node abilityNode = aParentNode.first_child(); abilityNode; abilityNode = abilityNode.next_sibling())
	{
		//Get the name;
		const char* name = abilityNode.child_value(Name);

		//Setup the ability
		sAbility ability = sAbility(abilityNode.child(Contribution).text().as_double(),
				abilityNode.child(Cooldown).text().as_double(), name);

		//Now add each tick to ability.
		for (pugi::xml_node tickNode = aParentNode.child(Damage).first_child(); tickNode; tickNode = tickNode.next_sibling())
		{
			double coefficient = GetDoubleFromNode(Coefficient, tickNode);
			std::cout << coefficient << std::endl;
			double amountModifierPercent = GetDoubleFromNode(AmountModPerc, tickNode);
			double stdHealthMin = GetDoubleFromNode(StdHMin, tickNode);
			double stdHealthMax = GetDoubleFromNode(StdHMax, tickNode);
			double critBonus = GetDoubleFromNode(Crit, tickNode);
			int surgeBonus = GetIntFromNode(Surge, tickNode);
			int armorPenetration = GetIntFromNode(ArmorPen, tickNode);

			//Get the total of all the additive multipliers
			int additiveMultiplier = 0;
			for (pugi::xml_node addMultNode = tickNode.child(MultAdditive).first_child();
					addMultNode; addMultNode = addMultNode.next_sibling())
				//Additive so add.
				additiveMultiplier += GetIntFromNode(AdditiveValue, addMultNode);

			double multiplicativeMultiplier = 1;
			for (pugi::xml_node addMultNode = tickNode.child(MultMuliplicative).first_child();
					addMultNode; addMultNode = addMultNode.next_sibling())
				//Multiplicative so multiply.
				multiplicativeMultiplier *= GetIntFromNode(MultiplicativeValue, addMultNode);

			sAbilityTick tick = sAbilityTick(name, coefficient, amountModifierPercent, stdHealthMin, stdHealthMax, additiveMultiplier,
					multiplicativeMultiplier, critBonus, surgeBonus, armorPenetration);

			//Add the tick the the ability.
			ability.AddTick(tick);
		}

		//Finally push the ability to the vector.
		list.push_back(ability);
	}

	return list;
}

inline double GetDoubleFromNode(const char* aNodeName, pugi::xml_node& aParentNode)
{
	return aParentNode.child(aNodeName).text().as_double();
}

inline int GetIntFromNode(const char* aNodeName, pugi::xml_node& aParentNode)
{
	return aParentNode.child(aNodeName).text().as_int();
}
