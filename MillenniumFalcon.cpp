/*********************************************************************
** Program Filename: MillenniumFalcon.cpp
** Author: Gabriel Orellana
** Date: 11/25/2015
** Description: Implementation file for derived class MillenniumFalcon.
** Has bool member and menu, special, and exit functions.
*********************************************************************/
#include "MillenniumFalcon.h"

// Default constructor setting stormtroopers killed to false
MillenniumFalcon::MillenniumFalcon()
{
	stormtroopersKilled = false;
}

/*********************************************************************
** Function: spaceMenu
** Description: Displays menu and gets user input. User lure stormtroopers
** search for items or exit area.
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: menu displayed
*********************************************************************/
void MillenniumFalcon::spaceMenu()
{
	// Checks if user has turned off tractor beam, if so, opens door to cockpit
	if (player->getUtilityBelt()->getBeltItem("Tractor Beam Off"))
	{
		setPreviousRoomOpen(true);
	}

	// Checks if user has picked up stormtrooper armor, if so, opens door to hangar bay
	if (player->getUtilityBelt()->getBeltItem("Stormtrooper Armor"))
	{
		setNextRoomOpen(true);
	}

	cout << "\nYou are now inside the main cabin of the renowned Millennium Falcon." << endl;
	cout << "It's the ship that made the Kessel run in less than 12 parsecs, FYI." << endl;
	cout << "Unfortunately you aren't going anywhere as long as that tractor beam is on.\n";
	cout << "You need to figure out a way to get off the ship without being detected,\n";
	cout << "and disable it." << endl;
	cout << "You hear stormtroopers standing at the base of the exit ramp." << endl;

	cout << "\nWhat do you want to do?\n" << endl;
	cout << "[1] Yell, \"We need a little help in here!\"" << endl;
	cout << "[2] Check for items" << endl;
	cout << "[3] Other options" << endl;
	cout << "Enter selection: ";
}

/*********************************************************************
** Function: spaceMenuVisited
** Description: Displays menu for when space has been visited and gets
** user input. User lure stormtroopers search for items or exit area.
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: menu displayed
*********************************************************************/
void MillenniumFalcon::spaceMenuVisited()
{
	// Checks if user has turned off tractor beam, if so, opens door to cockpit
	if (player->getUtilityBelt()->getBeltItem("Tractor Beam Off"))
	{
		setPreviousRoomOpen(true);
	}

	// Checks if user has picked up stormtrooper armor, if so, opens door to hangar bay
	if (player->getUtilityBelt()->getBeltItem("Stormtrooper Armor"))
	{
		setNextRoomOpen(true);
	}

	cout << "\nYou are back in the Falcon." << endl;

	cout << "\nWhat do you want to do?\n" << endl;
	cout << "[1] Yell, \"We need a little help in here!\"" << endl;
	cout << "[2] Check for items" << endl;
	cout << "[3] Other options" << endl;
	cout << "Enter selection: ";
}


/*********************************************************************
** Function: spaceSpecial
** Description: runs message, sets space item to stormtrooper armor,
** spaceHasItem to true, and stormtroopers killed to true.
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: displays message and variables set.
*********************************************************************/
void MillenniumFalcon::spaceSpecial()
{
	if (stormtroopersKilled) // If user already chose this option
	{
		cout << "\nYou yell but there is no one there to respond." << endl;
	}
	else
	{
		cout << "\nThe stormtroopers come marching up the ramp and you imagine\n";
		cout << "the look of surprise that must be on their faces as you fire\n";
		cout << "your blaster at them." << endl;
		cout << "They fall to the ground in a pile. That armor sure would be useful.\n";

		spaceItem = "Stormtrooper Armor";
		spaceHasItem = true;
		stormtroopersKilled = true;
	}
}

/*********************************************************************
** Function: exitOptions
** Description: Displays menu for exits and returns user choice
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: user choice for exit location returned.
*********************************************************************/
Space* MillenniumFalcon::exitOptions()
{
	int exitChoice;
	cout << "\nOther Options:" << endl;
	cout << "[1] Exit via ramp to Hangar Bay" << endl;
	cout << "[2] Enter Cockpit" << endl;
	cout << "[3] Enter Cargo Compartment" << endl;
	cout << "Enter selection: ";
	cin >> exitChoice;

	// validates selection
	while (exitChoice < 1 || exitChoice > 3)
	{
		cout << "Enter valid selection:";
		cin >> exitChoice;
	}

	if (exitChoice == 1)
	{
		if (!nextRoomOpen) // if space isn't open return current space
		{
			cout << "\nYou can't go out there without a disguise." << endl;
			cout << "Find something to make you less... noticeable." << endl;
			return this;
		}
		else // If space is open return nextRoom
		{
			cout << "\nYou venture out in your newly aquired Stormtrooper Armor." << endl;
			setSpaceVisited(true);
			return nextRoom;
		}
	}
	else if (exitChoice == 2)
	{
		if (getPreviousRoomOpen()) // If space is open return previousRoom
		{
			cout << "\nYou enter the cockpit." << endl;
			setSpaceVisited(true);
			return previousRoom;
		}
		else // If space isn't open
		{
			cout << "\nYou can't leave until you deactivate the tractor beam!" << endl;
			return this;
		}
	}
	else if (exitChoice == 3)
	{
		// Returns compartmentA
		cout << "\nYou enter the cargo compartment." << endl;
		setSpaceVisited(true);
		return compartmentA;
	} 
	return this;
}