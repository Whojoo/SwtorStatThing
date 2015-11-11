/*
 * XmlConstants.h
 *
 *  Created on: 11 jun. 2015
 *      Author: Robin
 */

#ifndef XMLCONSTANTS_H_
#define XMLCONSTANTS_H_

#define XML_CONSTANTS XmlConstants()

/**
 * The layout of this constants structure copies the layout in the xml file.
 * 
 * Layout:
 *
 * XML_CONSTANTS : XmlConstants
 * {
 * 		BASE_ARMOR_PENETRATION : char*
 *		ABILTIY : XmlAbilityConstants
 *		{
 *			NAME : char*
 *			CONTRIBUTION : char*
 *			COOLDOWN : char*
 *			DAMAGE : char*
 *			DAMAGE_CONSTANTS : XmlAbilityDamageConstants
 *			{
 *				TICK : XmlAbilityDamageTickConstants
 *				{
 *					COEFFICIENT : char*
 *					AMOUNT_MODIFIER_PERCENT : char*
 *					STD_HEALTH_MIN : char*
 *					STD_HEALTH_MAX : char*
 *					CRIT_BONUS : char*
 *					CRIT_MULTIPLIER_BONUS : char*
 *					ARMOR_PENETRATION : char*
 *					ADDITIVE_MULTIPLIER : char*
 *					MULTIPLICATIVE_MULTIPLIER : char*
 *					MULTIPLIER_VALUE : char*
 *				}
 *			}
 *		}
 * }	
 */		

struct XmlAbilityDamageTickConstants
{
	const char* COEFFICIENT = "coefficient";
	const char* AMOUNT_MODIFIER_PERCENT = "amountModifierPercent";
	const char* STD_HEALTH_MIN = "stdHealthMin";
	const char* STD_HEALTH_MAX = "stdHealthMax";
	const char* CRIT_BONUS = "critBonus";
	const char* CRIT_MULTIPLIER_BONUS = "surgeBonus";
	const char* ARMOR_PENETRATION = "armorPenetration";
	const char* ADDITIVE_MULTIPLIER = "multiplierAdditive";
	const char* MULTIPLICATIVE_MULTIPLIER = "multiplierMultiplicative";
	const char* MULTIPLIER_VALUE = "value";

	XmlAbilityDamageTickConstants() {}
};

struct XmlAbilityDamageConstants
{
	XmlAbilityDamageTickConstants TICK;

	XmlAbilityDamageConstants() {}
};

struct XmlAbilityConstants
{
	const char* NAME = "name";
	const char* CONTRIBUTION = "contribution";
	const char* COOLDOWN = "cooldown";
	const char* DAMAGE = "damage";

	const XmlAbilityDamageConstants DAMAGE_CONSTANTS;

	XmlAbilityConstants() {}
};

struct XmlConstants
{
	const char* BASE_ARMOR_PENETRATION = "baseArmorPenetration";
	const char* ABILTIES = "abilities";

	const XmlAbilityConstants ABILTIY;

	XmlConstants() {}
};


#endif /* XMLCONSTANTS_H_ */
