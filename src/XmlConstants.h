/*
 * XmlConstants.h
 *
 *  Created on: 11 jun. 2015
 *      Author: Robin
 */

#ifndef XMLCONSTANTS_H_
#define XMLCONSTANTS_H_

/**
 * Xml file layout and element names.
 * Each tab means it is part of first 'untabbed' above it.
 */

//Root
#define BaseArmorPen "baseArmorPenetration"
#define Abilities "abilities"
	//Ability part of abilites.
	#define Ability "ability"
		//Name part of ability
		#define Name "name"
		#define Contribution "contribution"
		#define Cooldown "cooldown"
		#define Damage "damage"
			//Tick part of damage
			#define Tick "tick"
				//Stats part of tick
				#define Coefficient "coefficient"
				#define AmountModPerc "amountModifierPercent"
				#define StdHMin "stdHealthMin"
				#define StdHMax "stdHealthMax"
				#define Crit "critBonus"
				#define Surge "surgeBonus"
				#define ArmorPen "armorPenetration"
				#define MultAdditive "multiplierAdditive"
					//Value part of multiplierAdditive
					#define AdditiveValue "value"
				#define MultMuliplicative "multiplierMultiplicative"
					//Value part of multiplierMultiplicative
					#define MultiplicativeValue "value"


#endif /* XMLCONSTANTS_H_ */
