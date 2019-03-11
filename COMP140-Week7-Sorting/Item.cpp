#include "stdafx.h"
#include "Item.h"

Item::Item()
{
	Name = "name";
	Strength = 1.0f;
	Quality = 1.0f;
	Cost = 1;
}

Item::Item(const std::string & name, float quality, float strength, int cost)
{
	Name = name;
	Quality = quality;
	Strength = strength;
	Cost = cost;
}

Item::~Item()
{
}

void Item::Display()
{
	std::cout << "Name: " << Name << " Strength " << Strength << 
		" Quality " << Quality << " Cost " << Cost << std::endl;
}
