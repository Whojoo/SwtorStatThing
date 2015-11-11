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
struct Ability;
typedef std::vector<Ability> abilityVec;

/**
 * Starts the program for a certain xml file path.
 * \param aPath path to the xml file.
 */
extern void Start(const char* path, const char* diciplineName, eWeaponType weapon);

/**
 * Loads the abilities into a std::vector
 * \param aParentNode the <abilities> node.
 */
extern abilityVec LoadAbilities(pugi::xml_node parentNode);

extern void LoadGearJson();

extern inline double GetDoubleFromNode(const char* nodeName, pugi::xml_node& parentNode);
extern inline int GetIntFromNode(const char* aNodeName, pugi::xml_node& parentNode);

#endif /* FUNCTIONS_H_ */
