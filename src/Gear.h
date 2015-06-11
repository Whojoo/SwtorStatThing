/*
 * Gear.h
 *
 *  Created on: 11 jun. 2015
 *      Author: Robin
 */

#ifndef GEAR_H_
#define GEAR_H_

//Equipment constants.
#define ImplantCount 3
#define EnhancementCount 7
#define ModCount 9
#define ArmoringCount 9
#define RelicCount 2
#define CrystalCount 2

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

struct sWeapon
{
	double average;

	sWeapon(int aMin, int aMax) : average((double)(aMin + (double)(aMax - aMin) * 0.5)) { }
	sWeapon() : sWeapon(0, 0) { }
};

struct sGear
{
	sWeapon weapon;
	int main;
	int secundairy;
	int tertiary;
	int rest;
	int crystals;

	sGear(int aMain, int aSecundairy, int tertiary);
};

#endif /* GEAR_H_ */
