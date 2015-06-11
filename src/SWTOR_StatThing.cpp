//============================================================================
// Name        : SWTOR_StatThing.cpp
// Author      : Whojoo
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <json/json.h>
#include <pugixml.hpp>

#define Virulence "xml_files/sniper/virulence.xml"

int main()
{
	pugi::xml_document doc;
	doc.load_file(Virulence);
	pugi::xml_node abilities = doc.child("abilities");

	if (!abilities)
		return 1;

	for (pugi::xml_node it = abilities.first_child(); it; it = it.next_sibling())
	{
		std::cout << it.child_value("name") << std::endl;
	}

	return 0;
}
