/*
 * Ability.h
 *
 *  Created on: 11 jun. 2015
 *      Author: Robin
 */

#ifndef ABILITY_H_
#define ABILITY_H_


/**
 * Struct which contains the information required for each damage tick.
 */
struct AbilityTick
{
	const char* name;
	double coefficient;
	double amountModifier;
	double stdHealthAverage;
	double additiveMultiplier;
	double multiplicativeMultiplier;
	double critBonus;
	int surgeBonus;
	int armorPenetration;

	/**
	 * Creates an ability damage tick. Some abilities have different damage values or types and these ticks support that.
	 * @param name 					- name of the ability for debug purposes.
	 * @param coef 				 	- coefficient of this tick.
	 * @param amountModifierPercent - the amountModifierPercent, this constructor adds 1 to it.
	 * @param stdHealthMin			- stdHealthMin for this tick.
	 * @param stdHealthMax 		 	- stdHealthMax for this tick.
	 * @param addMult 				- all additive multipliers added together. This constructor converts it from x% to 1.x
	 * @param multiMult 			- all the multiplicative multipliers multiplied together.
	 * @param critBonus			 	- crit bonus for this tick.
	 * @param surgeBonus			- surge bonus for this tick.
	 * @param armorPen 			 	- armor penetration for this tick.
	 */
	AbilityTick(const char* name, double coef, double amountModifierPercent, double stdHealthMin, double stdHealthMax, int addMult,
			double multiMult, double critBonus, int surgeBonus, int armorPen) :
				name(name), coefficient(coef),
					amountModifier(1 + amountModifierPercent), stdHealthAverage(stdHealthMin + (stdHealthMax - stdHealthMin) * 0.5),
					additiveMultiplier(1 + ((double)addMult * 0.01)), multiplicativeMultiplier(multiMult), critBonus(critBonus), surgeBonus(surgeBonus),
					armorPenetration(armorPen) { }

	/**
	 * Default constructor so we can use this in an array.
	 * Values filled in so I get rid of these annoying 'not initialized' warning.
	 */
	AbilityTick() : name("ERROR"), coefficient(0), amountModifier(0), stdHealthAverage(0), additiveMultiplier(0),
			multiplicativeMultiplier(0), critBonus(0), surgeBonus(0), armorPenetration(0) { }
};

/**
 * Struct which contains basic ability information and each damage tick of the ability.
 */
struct Ability
{
	double contribution;
	double cooldown;
	const char* name;

	AbilityTick* First();
	AbilityTick* Next();
	AbilityTick* Previous();
	void AddTick(AbilityTick tick);

	/**
	 * @param contribution - The total contribution this ability has represented as a double from 0 to 100.
	 * @param cooldown	   - The cooldown of the ability in seconds.
	 * @param name		   - The name of the ability.
	 */
	Ability(double contribution, double cooldown, const char* name) : contribution(contribution), cooldown(cooldown), name(name),
			numOfTicks(-1), currentTick(-1), ticks(0x0) { }

private:
	//Logic for ability tick iteration.
	int numOfTicks;
	int currentTick;
	AbilityTick* ticks;
};

#endif /* ABILITY_H_ */
