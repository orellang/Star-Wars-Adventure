/*********************************************************************
** Program Filename: UtilityBelt.h
** Author: Gabriel Orellana
** Date: 11/27/2015
** Description:  Implementation file for UtilityBelt class with vector of
** of strings, int for size, constructor setting size and functions to
** add and remove items from belt and display belt items.
*********************************************************************/
#include "Belt.h"
#include <algorithm>
#include <iostream>

// Constructor setting beltSize
Belt::Belt()
{
	beltSize = 0;
}

// Set belt size
void Belt::setBeltSize(int s)
{
	beltSize = s;
}

/*********************************************************************
** Function: addBeltItem
** Description: checks if item is in belt, if not and if belt is not 
** full, adds item to belt. Returns true if item added or false if not
** Parameters: string
** Pre-Conditions: utility belt object
** Post-Conditions: returns bool for item added or not
*********************************************************************/
bool Belt::addBeltItem(string newItem)
{
	bool itemInBelt = false;

	for (int i = 0; i < beltItems.size(); i++)
	{
		if (newItem == beltItems[i])
		{
			itemInBelt = true;
		}
	}

	if (beltItems.size() < beltSize && !itemInBelt)
	{
		beltItems.push_back(newItem);
		return true;
	}
	else
		return false;
}

// get belt item
bool Belt::getBeltItem(string item)
{
	for (int i = 0; i < beltItems.size(); i++)
	{
		if (item == beltItems[i])
		{
			return true;
		}
	}
	return false;
}
/*********************************************************************
** Function: removeBeltItem
** Description: checks if item is in belt, if it is, removes item and 
** returns true, if not returns false
** Parameters: string
** Pre-Conditions: utility belt object
** Post-Conditions: returns bool for item removed or not
*********************************************************************/
bool Belt::removeBeltItem(string itemToRemove)
{
	for (int i = 0; i < beltItems.size(); i++)
	{
		if (itemToRemove == beltItems[i])
		{
			beltItems.erase(beltItems.begin() + i);
			return true;
		}
	}
	return false;
}

void Belt::displayBeltItems()
{
	std::cout << "Belt items: \n";
	for (int i = 0; i < beltItems.size(); i++)
	{
		std::cout << i+1 << ". " << beltItems[i] <<std::endl;
	}

}
