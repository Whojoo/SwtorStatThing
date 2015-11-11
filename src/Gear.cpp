/*
 * Gear.cpp
 *
 *  Created on: 11 jun. 2015
 *      Author: Robin
 */

#include "Gear.h"

const char* GetWeaponString(eWeaponType weaponType)
{
	switch (weaponType)
	{
		case eWeapon_Assault_Cannon: return "assault_cannon";
		case eWeapon_Sniper: return "sniper";
		case eWeapon_Blaster_Pistol: return "blaster_pistol";
		case eWeapon_Blaster_Rifle: return "blaster_rifle";
		case eWeapon_Dual_Bladed_Lightsaber: return "dual_bladed_lightsaber";
		case eWeapon_Lightsaber: return "lightsaber";
	}

	return "none";
}
