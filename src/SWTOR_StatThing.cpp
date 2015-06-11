//============================================================================
// Name        : SWTOR_StatThing.cpp
// Author      : Whojoo
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "functions.h"

#define VirulencePath "xml_files/sniper/virulence.xml"
#define Virulence "Virulence"

int main()
{
	Start(VirulencePath, Virulence, eWeapon_Sniper);

	return 0;
}
