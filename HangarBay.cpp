/*********************************************************************
** Program Filename: HangarBay.cpp
** Author: Gabriel Orellana
** Date: 11/25/2015
** Description: implementation file for derived class HangarBay.
** Has two bool members and menu, special, and exit functions.
*********************************************************************/
#include "HangarBay.h"

// Default constructor sets blastDoorsOpen and obiWanDead to false
// Sets previous and next room open to true
HangarBay::HangarBay()
{
	blastDoorsOpen = false;
	obiWanDead = false;
	previousRoomOpen = true;
	nextRoomOpen = true;

}

/*********************************************************************
** Function: spaceMenu
** Description: Displays menu. User open blast doors, search for items
** or exit area.
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: displays menu, returns Space pointer for area 
** player travels to next
*********************************************************************/
void HangarBay::spaceMenu()
{
	cout << "\nYou enter the hangar bay where the Falcon is being kept and\n";
	cout << "and hide behind some cargo containers.\n";
	cout << "There are stormtroopers scattered throughout the bay\n";
	cout << "so you need to keep a low profile.\n";
	cout << "The ramp to the falcon is down.\n";
	cout << "There are some blast doors across the way that are closed.\n";
	cout << "Near the ramp to the Falcon there is a door to a small room.\n";
	cout << "There is a hallway leading off to the side.\n";

	cout << "What do you want to do?\n" << endl;
	cout << "[1] Open the blast doors" << endl;
	cout << "[2] Look for items" << endl;
	cout << "[3] Other options" << endl;
	cout << "Enter selection: ";
}

/*********************************************************************
** Function: spaceMenuVisited
** Description: Displays menu for when space has been visited.
** User open blast doors, search for items or exit area.
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: displays menu, returns Space pointer for area
** player travels to next
*********************************************************************/
void HangarBay::spaceMenuVisited()
{
	cout << "\nYou enter the hangar bay where the Falcon is being kept and\n";
	cout << "and hide behind some cargo containers.\n";
	cout << "There are stormtroopers scattered throughout the bay\n";
	cout << "so you need to keep a low profile.\n";
	cout << "The ramp to the falcon is down.\n";

	if (blastDoorsOpen) // If blast doors are open message says so
		cout << "There are some blast doors across the way that are open." << endl;

	else
		cout << "There are some blast doors across the way that are closed." << endl;

	cout << "Near the ramp to the Falcon there is a door to a small room.\n";
	cout << "There is a hallway leading off to the side.\n";

	cout << "What do you want to do?\n" << endl;
	cout << "[1] Open the blast doors" << endl;
	cout << "[2] Look for items" << endl;
	cout << "[3] Other options" << endl;
	cout << "Enter selection: ";
}

/*********************************************************************
** Function: spaceSpecial
** Description: Checks if blast doors are open and if obi wan is dead
** if both are false and player has deactivated the tractor beam, it
** displays message describing obi wan's death and sets spaceVisited, 
** blastDoorsOpen, and obiWanDead to true. Sets nextRoomOpen and 
** compartmentAOpen to false. If obi wan is already dead, opens or shuts
** doors based on their status.
** appropriate message
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: displays appropriate message and sets variables
*********************************************************************/
void HangarBay::spaceSpecial()
{
	if (!blastDoorsOpen && !obiWanDead) // if doors are shut and obi wan is alive
	{
		if (player->getUtilityBelt()->getBeltItem("Tractor Beam Off")) // if tractor beam off
		{
			cout << "\nR2 hooks into a nearby data port and is able to open the doors.\n";
			cout << "As they slowly slide open, you see Obi-Wan locked in combat\n";
			cout << "with the Dark Lord Darth Vader!" << endl;
			cout << "Obi-Wan sees you out of the corner of his eye.\n";
			cout << "You watch in disbelief as he lowers his guard.\n";
			cout << "Darth Vader brings his sword down, cutting Obi-Wan in half!\n";
			cout << "Obi-Wan seems to disappear as the blade passes through him.\n";
			cout << "You yell out in horror, attracting the attention of the stormtroopers.\n";
			cout << "You hear Obi-Wan's voice in your head saying, \"Run, Luke! Run!\"\n";
			cout << "You've got to get out of there now.\n";

			spaceVisited = true;
			nextRoomOpen = false;
			compartmentAOpen = false;
			blastDoorsOpen = true;
			obiWanDead = true;
		}
		else // if obi wan is alive and tractor beam on
		{
			cout << "\nR2 tries to open the blast doors but they won't respond.\n";
		}
	}
	else if (blastDoorsOpen)
	{
		cout << "\nYou shut the blast doors.\n";
		blastDoorsOpen = false;
	}
	else
	{
		cout << "\nYou open the blast doors.\n";
		blastDoorsOpen = true;
	}


	
}

/*********************************************************************
** Function: exitOptions
** Description: Displays menu for exits and returns user choice
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: user choice for exit location returned.
*********************************************************************/
Space* HangarBay::exitOptions()
{
	int exitChoice;
	cout << "\nOther Options:" << endl;
	cout << "[1] Enter small room" << endl;
	cout << "[2] Return to Millennium Falcon" << endl;
	cout << "[3] Go down hallway" << endl;
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
			cout << "\nThe stormtroopers move to block you. You can't go that way." << endl;
			return this;
		}
		else
		{
			cout << "\nYou enter the small room near the ramp to the Falcon.\n";
			spaceVisited = true;
			return nextRoom;
		}
	}
	else if (exitChoice == 2)
	{
		cout << "\nYou return to the Millennium Falcon" << endl;
		spaceVisited = true;
		return previousRoom;
	}
	else if (exitChoice == 3)
	{
		if (!compartmentAOpen)
		{
			cout << "\nThe stormtroopers move to block you. You can't go that way." << endl;
			return this;
		}
		else
		{
			cout << "\nYou head back down the hallway to the Central Core Shaft.\n";
			return compartmentA;
		}
	}

	return this;
}