/*********************************************************************
** Program Filename: PowerTrench.cpp
** Author: Gabriel Orellana
** Date: 11/25/2015
** Description: implementation file for derived class PowerTrench.
** Has  3 bool members and menu, special, and exit functions.
*********************************************************************/
#include "PowerTrench.h"

// Default constructor
PowerTrench::PowerTrench()
{
	hidFromStormtrooper = false;
	tractorBeamOn = true;
	gotCaught = false;
	previousRoomOpen = true;
}

/*********************************************************************
** Function: spaceMenu
** Description: Displays menu. User can hide, search for items or exit area.
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: message displayed
*********************************************************************/
void PowerTrench::spaceMenu()
{
	cout << "\nYou enter a humming service trench that powers the huge tractor beam.\n";
	cout << "The trench seems to be a hundred miles deep and\n";
	cout << "The clacking sound of huge switching devices can be heard.\n";
	cout << "There is a narrow ledge leading to a control panel that\n";
	cout << "connects two large cables. There is a computer terminal there.\n";
	cout << "It looks like someone powered the tractor beam back on";
	cout << " after Obi-Wan turned it off!\n";
	cout << "You should power it down or there is no way you're getting out of here.\n";
	cout << "There is a door opposite the one you entered through.\n";
	cout << "As you sit there pondering all this,\n";
	cout << "you hear the sound of footsteps approaching.\n";

	cout << "What do you want to do?\n" << endl;
	cout << "[1] Hide behind the control panel" << endl;
	cout << "[2] Look for items" << endl;
	cout << "[3] Other options" << endl;
	cout << "Enter selection: ";
	spaceVisited = true;
}

/*********************************************************************
** Function: spaceMenuVisited
** Description: Displays appropriate. If User didn't hide, they lose 10
** turns, uer can search for items or exit area. sets variables as 
** appropriate. If user
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: message displayed and variables set
*********************************************************************/
void PowerTrench::spaceMenuVisited()
{
	if (player->getUtilityBelt()->getBeltItem("Tractor Beam Off"))
	{
		tractorBeamOn = false;
	}
	// If you don't choose to hide
	if (!hidFromStormtrooper && !gotCaught)
	{
		cout << "A detachment of stormtroopers walks in while you are standing there!\n";
		cout << "A prolonged firefight ensues.\n";
		cout << "You manage to defeat them but it has cost you valuable time.\n";

		setBonusTime(-10);
		cout << "You lost 10 turns!\n";
		gotCaught = true;
		compartmentAOpen = true;
		nextRoomOpen = true;
	}

	// Menu for room if tractor beam is on
	if (tractorBeamOn)
	{
		cout << "\nYou enter a humming service trench that powers the huge tractor beam.\n";
		cout << "The power is still on which means you can't leave in the Falcon yet.\n";
		cout << "There is a narrow ledge leading to a control panel that\n";
		cout << "connects two large cables. There is a computer terminal there.\n";
		cout << "There is a door opposite the one you entered through.\n";
	}

	// Menu for room is tractor beam off
	else 
	{
		cout << "\nYou enter a humming service trench that powers the huge Tractor Beam.\n";
		cout << "The power is off to the Tractor Beam which means you can escape!\n";
		cout << "There is a narrow ledge leading to a control panel that\n";
		cout << "connects two large cables. There is a computer terminal there.\n";
		cout << "There is a door opposite the one you entered through.\n";
	}

	cout << "What do you want to do?\n" << endl;
	cout << "[1] Hide behind the control panel" << endl;
	cout << "[2] Look for items" << endl;
	cout << "[3] Other options" << endl;
	cout << "Enter selection: ";
}

/*********************************************************************
** Function: spaceSpecial
** Description: hides from stormtroopers and displays appropriate message
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: changes variables and displays appropriate message.
*********************************************************************/
void PowerTrench::spaceSpecial()
{
	if (hidFromStormtrooper || gotCaught) // if you hid or were caught
	{
		cout << "\nThe stormtroopers are gone now, so you're hiding for no reason....\n";
	}
	else // if you hide opens rooms
	{
		cout << "\nYou hide behind the control panel just in time.\n";
		cout << "The door slides open and a detachment of stormtroopers";
		cout << " marches to the power trench.\n";
		cout << "The officer in charge tells two of them to stay and secure the area.\n";
		cout << "The other stormtroopers depart leaving the two in the room.\n";
		cout << "You can't go anywhere while they're there.\n";
		cout << "You wave your hands in desperation and the stormtroopers react.\n";
		cout << "They head off down the hallway to investigate";
		cout << " some noise they just imagined.\n";
		cout << "The area is clear again.\n";

		hidFromStormtrooper = true;
		compartmentAOpen = true;
		nextRoomOpen = true;

	}
}

/*********************************************************************
** Function: exitOptions
** Description: Displays menu for exits and returns user choice
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: user choice for exit location returned.
*********************************************************************/
Space* PowerTrench::exitOptions()
{
	int exitChoice;
	cout << "\nOther Options:" << endl;
	cout << "[1] Exit through far door" << endl;
	cout << "[2] Check power controls" << endl;
	cout << "[3] Return to Trash Compactor" << endl;
	cout << "Enter selection: ";
	cin >> exitChoice;

	while (exitChoice < 1 || exitChoice > 3)
	{
		cout << "Enter valid selection:";
		cin >> exitChoice;
	}

	if (exitChoice == 1)
	{
		if (!nextRoomOpen)
		{
			cout << "You hear footsteps approaching. Its not safe to leave yet.\n";
			return this;

		}
		else
		{
			cout << "\nYou exit through the far door." << endl;
			return nextRoom;
		}
	}
	else if (exitChoice == 2)
	{
		if (compartmentAOpen)
		{
			cout << "\nYou examine the power controls." << endl;
			return compartmentA;

		}
		else
		{
			cout << "You hear footsteps approaching. Someone is coming!\n";
			return this;
		}
	}
	else if (exitChoice == 3)
	{
		cout << "\nYou return to the Trash Compactor.\n";
		return previousRoom;
	}
	return this;
}