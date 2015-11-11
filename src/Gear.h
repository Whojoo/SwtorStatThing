/*
 * Gear.h
 *
 *  Created on: 11 jun. 2015
 *      Author: Robin
 */

#ifndef GEAR_H_
#define GEAR_H_

enum eNumberOfGearSlots
{
	eNumberOfGearSlots_Implants = 3,
	eNumberOfGearSlots_Enhancements = 7,
	eNumberOfGearSlots_Mods = 9,
	eNumberOfGearSlots_Armorings = 9,
	eNumberOfGearSlots_Relics = 2,
	eNumberOfGearSlots_Crystals = 2
};

//The different gear levels.
enum eGearLevel
{
	eGear_Ressurected = 192,
	eGear_Revanite = 198
};

enum eWeaponType
{
	eWeapon_Sniper,
	eWeapon_Assault_Cannon,
	eWeapon_Blaster_Rifle,
	eWeapon_Blaster_Pistol,
	eWeapon_Dual_Bladed_Lightsaber,
	eWeapon_Lightsaber
};

extern const char* GetWeaponString(eWeaponType weaponType);

struct Weapon
{
	double average;

	Weapon(int min, int max) : average((double)(min + (double)(max - min) * 0.5)) { }
	Weapon() : Weapon(0, 0) { }
};


//TODO: Character sheet? -Robin
//TODO: Change according to 4.0 mastery changes. -Robin
struct Gear
{
	Weapon weapon;
	int main;
	int secundairy;
	int tertiary;
	int rest;
	int crystals;

	Gear(int main, int secundairy, int tertiary);
};

#endif /* GEAR_H_ */
