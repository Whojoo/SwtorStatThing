/*
 * Ability.h
 *
 *  Created on: 11 jun. 2015
 *      Author: Robin
 */

#ifndef ABILITY_H_
#define ABILITY_H_

struct sAbilityTick
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
	 * \param aName name of the ability for debug purposes.
	 * \param aCoef coefficient of this tick.
	 * \param aAmountModifierPercent the amountModifierPercent, this constructor adds 1 to it.
	 * \param aStdHealthMin stdHealthMin for this tick.
	 * \param aStdHealthMax stdHealthMax for this tick.
	 * \param aAddMult all additive multipliers added together. This constructor converts it from x% to 1.x
	 * \param aMultiMult all the multiplicative multipliers multiplied together.
	 * \param aCritBonus crit bonus for this tick.
	 * \param aSurgeBonus surge bonus for this tick.
	 * \param aArmorPen armor penetration for this tick.
	 */
	sAbilityTick(const char* aName, double aCoef, double aAmountModifierPercent, double aStdHealthMin, double aStdHealthMax, int aAddMult,
			double aMuliMult, double aCritBonus, int aSurgeBonus, int aArmorPen) :
				name(aName), coefficient(aCoef),
					amountModifier(1 + aAmountModifierPercent), stdHealthAverage(aStdHealthMin + (aStdHealthMax - aStdHealthMin) * 0.5),
					additiveMultiplier(1 + ((double)aAddMult * 0.01)), multiplicativeMultiplier(aMuliMult), critBonus(aCritBonus), surgeBonus(aSurgeBonus),
					armorPenetration(aArmorPen) { }

	/**
	 * Default constructor so we can use this in an array.
	 * Values filled in so I get rid of these annoying 'not initialized' warning.
	 */
	sAbilityTick() : name("ERROR"), coefficient(0), amountModifier(0), stdHealthAverage(0), additiveMultiplier(0),
			multiplicativeMultiplier(0), critBonus(0), surgeBonus(0), armorPenetration(0) { }
};

struct sAbility
{
	double contribution;
	double cooldown;
	const char* name;

	sAbilityTick* First();
	sAbilityTick* Next();
	sAbilityTick* Previous();
	void AddTick(sAbilityTick tick);

	sAbility(double aContribution, double aCooldown, const char* aName) : contribution(aContribution), cooldown(aCooldown), name(aName),
			numOfTicks(-1), currentTick(-1), ticks(0x0) { }

private:
	int numOfTicks;
	int currentTick;
	sAbilityTick* ticks;
};

#endif /* ABILITY_H_ */
