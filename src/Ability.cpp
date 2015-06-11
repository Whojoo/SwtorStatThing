/*
 * Ability.cpp
 *
 *  Created on: 11 jun. 2015
 *      Author: Robin
 */

#include "Ability.h"

sAbilityTick* sAbility::First()
{
	if (ticks)
	{
		//ticks already points to first.
		currentTick = 0;
		return ticks;
	}
	else
	{
		return 0x0;
	}
}

sAbilityTick* sAbility::Next()
{
	if (ticks && ++currentTick < numOfTicks)
		return ticks + currentTick;
	else
		return 0x0;
}

sAbilityTick* sAbility::Previous()
{
	if (ticks && --currentTick >= 0)
		return ticks + currentTick;
	else
		return 0x0;
}

void sAbility::AddTick(sAbilityTick tick)
{
	if (!ticks)
	{
		ticks = new sAbilityTick[1];
		numOfTicks = 0; //Gets upped later.
	}
	else
	{
		//Put in temporary and fill it.
		sAbilityTick* temp = new sAbilityTick[numOfTicks + 1];
		for (int i = 0; i < numOfTicks; i++)
		{
			temp[i] = ticks[i];
		}

		//Delete old, point to new.
		delete[] ticks;
		ticks = temp;
		temp = 0x0;
	}

	//Add the new one.
	ticks[numOfTicks++] = tick;
}
