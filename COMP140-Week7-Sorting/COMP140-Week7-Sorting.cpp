// COMP140-Week7-Sorting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Item.h"

//Sort function, this will sort items by name
bool sortByName(Item * a, Item* b) 
{
	return a->GetName() < b->GetName();
}

int main()
{


	//Add a bunch of items to a vector
	std::vector<Item*> items;
	Item * sword = new Item("sword", 1.0f, 5.0f, 100);
	Item * axe = new Item("axe", 2.0f, 1.0f, 50);
	Item * wand = new Item("wand", 10.0f, 6.0f, 200);
	Item * daggger = new Item("dagger", 4, 0.5, 70);
	items.push_back(sword);
	items.push_back(axe);
	items.push_back(wand);
	items.push_back(daggger);

	//used to hold user input
	char input;
	//Used to control the game
	bool quit = false;

	//While loop, this is a typical game loop which is controlled by a boolean
	while (!quit)
	{
		//Iterate using the for range loop and call display on each items.
		//note the use of the auto keyword
		for (auto item : items)
		{
			item->Display();
		}

		//Grab input from std input
		std::cin >> input;

		//q for quit has been pressed
		if (input == 'q')
		{
			quit = true;
		}
		//n for sort by name
		else if (input == 'n')
		{
			//call std::sort and pass in predicate function
			std::sort(items.begin(), items.end(),sortByName);
		}
		//s for sort by strength
		else if (input == 's')
		{
			//call sort using a lambda expression
			//This will sort by strength
			std::sort(items.begin(), items.end(), [](Item* a, Item* b)
			{
				return a->GetStrength() < b->GetStrength();
			});
		}
	}

	//Standard way to clear out a vector of pointers;
	auto iter = items.begin();
	while (iter != items.end())
	{
		//do we have some memory allocated to the iterator current location
		if (*iter)
		{
			//delete the memory that the iterator is pointing too
			delete (*iter);
			//earse the location the iterator is pointing to, this invalidates the current
			//iterator so we need to store the new one from the earse function
			iter = items.erase(iter);
		}
		else
		{
			//move on the iterator
			iter++;
		}
	}

	items.clear();
    return 0;
}

