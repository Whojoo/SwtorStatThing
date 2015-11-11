/*
 * JsonConstants.h
 *
 *  Created on: 12 jun. 2015
 *      Author: Robin
 */

#ifndef JSONCONSTANTS_H_
#define JSONCONSTANTS_H_

#define StatDistributionPath "json_files/stat_distribution_values.json"

/**
 * Layout of the json using defines below:"
 * root {
 * 		GearLevel: array [
 * 			[Resurrected/Revanite] {
 * 				Level: int,
 * 				TotalMainStat: int,
 * 				SecundairyValues: object {
 * 					Mod: int,
 * 					Enhancement: int,
 * 					Implant: int,
 * 					Relic: int
 * 				},
 * 				TertiaryValue: int,
 * 				AugmentSlots: int,
 * 				EnhancementSlots: int,
 * 				Weapon: object {
 * 					WeaponPower: int,
 * 					GetWeaponString(eWeaponType): object {
 * 						WeaponMin: int,
 * 						WeaponMax: int
 * 					}
 * 				}
 * 			}
 * 		]
 * }
 */

//TODO: Create like XmlConstants.h

#define GearLevel "gear_levels"
#define Resurrected 0
#define Revanite 1

#endif /* JSONCONSTANTS_H_ */
