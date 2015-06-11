/*
 * functions.h
 *
 *  Created on: 11 jun. 2015
 *      Author: Robin
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <vector>
#include "Ability.h"
#include "Gear.h"

//Forward declaration(s)
namespace pugi
{
	class xml_node;
} /* namespace pugi */

//Typedef for ability vector.
struct sAbility;
typedef std::vector<sAbility> abilityVec;

/**
 * Starts the program for a certain xml file path.
 * \param aPath path to the xml file.
 */
extern void Start(const char* aPath, const char* aDiciplineName, eWeaponType weapon);

/**
 * Loads the abilities into a std::vector
 * \param aParentNode the <abilities> node.
 */
extern abilityVec LoadAbilities(pugi::xml_node aParentNode);

extern inline double GetDoubleFromNode(const char* aNodeName, pugi::xml_node& aParentNode);
extern inline int GetIntFromNode(const char* aNodeName, pugi::xml_node& aParentNode);

#endif /* FUNCTIONS_H_ */
