/*********************************************************************
** Program Filename: CommandOffice.cpp
** Author: Gabriel Orellana
** Date: 11/25/2015
** Description: implementation file for derived class CommandOffice.
** Has bool member and menu, special, and exit functions.
*********************************************************************/
#include "CommandOffice.h"

// Default constructor setting space item, setting checked system to 
// false and spaceHasItem to true
CommandOffice::CommandOffice()
{
	spaceItem = "comlink";
	checkedSystem = false;
	spaceHasItem = true;
}

/*********************************************************************
** Function: spaceMenu
** Description: Displays menu. User can access imperial network, search
** for items, or exit area.
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: menu displayed 
*********************************************************************/
void CommandOffice::spaceMenu()
{
	cout << "\nYou cross the hangar bay and quiety enter the nearby Command Office.\n";
	cout << "Fortunately it's unoccupied. There is a turbolift in the corner.\n";
	cout << "The only other door leads back to the docking bay.\n";
	cout << "You need to find a way to reach the tractor beam power controls.\n";
	cout << "There is a computer outlet that may be of some use." << endl;

	cout << "What do you want to do?\n" << endl;
	cout << "[1] Have R2D2 plug into the entire Imperial Network" << endl;
	cout << "[2] Look for items" << endl;
	cout << "[3] Exit comms room" << endl;
	cout << "Enter selection: ";
}

/*********************************************************************
** Function: spaceMenuVisited
** Description: Displays menu for when space has been visited.
** User can access imperial network, search for items, or exit area.
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: menu displayed
*********************************************************************/
void CommandOffice::spaceMenuVisited()
{
	cout << "\nYou are back in the Command Office." << endl;
	cout << "Fortunately it's still unoccupied. There is a turbolift in the corner.\n";
	cout << "The only other door leads back to the docking bay.\n";
	cout << "There is a computer outlet that may be of some use." << endl;

	cout << "What do you want to do?\n" << endl;
	cout << "[1] Have R2D2 plug into the entire Imperial Network" << endl;
	cout << "[2] Look for items" << endl;
	cout << "[3] Other options" << endl;
	cout << "Enter selection: ";
}

/*********************************************************************
** Function: spaceSpecial
** Description: Changes checkedSystem and nextRoomOpen to true and displays 
** appropriate message
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: message displayed and variables set.
*********************************************************************/
void CommandOffice::spaceSpecial()
{
	if (!checkedSystem) // if system hasn't been checked
	{
		cout << "\nR2 plugs in to the network and begins searchinig.\n";
		cout << "He says he found the reactors which power the Tractor Beam!\n";
		cout << "Obi-Wan volunteers to go shut the power down." << endl;
		cout << "After Obi-Wan leaves, R2 begins beeping excitedly. He's found Princess Leia!\n";
		cout << "She is being held on level 5 in Detention Block A A-twenty-three and\n";
		cout << "is scheduled to be terminated! You've got to do something!\n";
		checkedSystem = true;
		nextRoomOpen = true;
	}
	else // if system has been checked
	{
		cout << "\nYou already checked the network." << endl;
	}
}

/*********************************************************************
** Function: exitOptions
** Description: Displays menu for exits and returns user choice
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: user choice for exit location returned.
*********************************************************************/
Space* CommandOffice::exitOptions()
{
	int exitChoice;
	cout << "\nOther Options:" << endl;
	cout << "[1] Take Turbolift" << endl;
	cout << "[2] Return to Hangar Bay" << endl;
	cout << "Enter selection: ";
	cin >> exitChoice;

	while (exitChoice < 1 || exitChoice > 2)
	{
		cout << "Enter valid selection:";
		cin >> exitChoice;
	}

	if (exitChoice == 1)
	{
		if (!nextRoomOpen) // if space not open
		{
			cout << "\nYou can't go anywhere until you know where you need to go." << endl;
			cout << "Find out where the Tractor Beam power controls are." << endl;
			return this;
		}
		else // if space open
		{
			cout << "\nYou take the Turbolift up to the level 5 detention block\n";
			cout << "You leave R2D2 and C3PO behind as they will only get in the way" << endl;
			return nextRoom;
		}
	}
	else if (exitChoice == 2)
	{
		cout << "\nYou return to the Millennium Falcon" << endl;
		return previousRoom;
	}
	
	return this;
}