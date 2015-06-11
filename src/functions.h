/*
 * functions.h
 *
 *  Created on: 11 jun. 2015
 *      Author: Robin
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <pugixml.hpp>
#include <vector>

struct sAbility;
typedef std::vector<sAbility> abilityList;

/**
 * Starts the program for a certain xml file path.
 * \param aPath path to the xml file.
 */
extern void Start(const char* aPath);

/**
 * Loads the abilities into a std::vector
 * \param aParentNode the <abilities> node.
 */
extern abilityList LoadAbilities(pugi::xml_node aParentNode);

extern inline double GetDoubleFromNode(const char* aNodeName, pugi::xml_node& aParentNode);
extern inline int GetIntFromNode(const char* aNodeName, pugi::xml_node& aParentNode);

#endif /* FUNCTIONS_H_ */
