/*********************************************************************
** Program Filename: CentralCoreShaft.cpp
** Author: Gabriel Orellana
** Date: 11/25/2015
** Description: implementation file for derived class CentralCoreShaft.
** Has 2 bool members and menu, special, and exit functions.
*********************************************************************/
#include "CentralCoreShaft.h"

// Default constructor setting variables and adding item
CentralCoreShaft::CentralCoreShaft()
{
	rappelledAcross = false;
	spaceHasItem = true;
	spaceItem = "grappling hook";
}

/*********************************************************************
** Function: spaceMenu
** Description: Displays menu. User can jump across, use item, 
** or exit area.
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: menu displayed
*********************************************************************/
void CentralCoreShaft::spaceMenu()
{
	cout << "\nYou race through the hatch onto a narrow bridge\n";
	cout << "that spans a huge, deep shaft that seems to go into infinity.\n";
	cout << "There is a door on the other side but unfortunately\n";
	cout << "the bridge has been retracted into the wall of the shaft,\n";
	cout << "and you almost rush into the abyss.\n";
	cout << "You lose your balance off the end of the bridge\n";
	cout << "but Leia, behind you, takes hold of your arm and pulls you back.\n";
	cout << "Blasts from the stormtroopers' laser guns explode nearby\n";
	cout << "reminding you of the oncoming danger.\n";
	cout << "You fire back at the advancing troops.\n";
	cout << "Leia reaches over and hits a switch that pops the hatch door shut\n";
	cout << "with a resounding boom, leaving you precariously perched\n";
	cout << "on a short piece of bridge overhang.\n";
	cout << "Laserfire from the troopers continues to hit the steel door.\n";
	cout << "The stormtroopers are coming and there's no door lock!\n";
	cout << "In a moment of panic, you blast the controls.\n";
	cout << "\"That oughta hold it for a while\", you say proudly.\n";
	cout << "Leia says we need to find the controls that extend the bridge.\n";
	cout << "Realization of what you've done creeps over you.\n";
	cout << "\"Oh, I think I just blasted it....\"\n";
	cout << "Two stormtroopers appear on an overhang accross the abyss from you.\n";
	cout << "You don't have much time to get out of this mess.\n";

	cout << "What do you want to do?\n" << endl;
	cout << "[1] Jump across" << endl;
	cout << "[2] Check your stormtrooper belt" << endl;
	cout << "[3] Other options" << endl;
	cout << "Enter selection: ";

	spaceVisited = true;
}

/*********************************************************************
** Function: spaceMenuVisited
** Description: Displays menu. User can jump across, use item,
** or exit area.
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: menu displayed
*********************************************************************/
void CentralCoreShaft::spaceMenuVisited()
{
	if (rappelledAcross)
	{
		cout << "You are on the farside of the chasm.\n";
	}

	else
	{
		cout << "\nYou pass through the hatch onto a narrow bridge\n";
		cout << "that spans a huge, deep shaft that seems to go into infinity.\n";
	}
	
	cout << "There is a door on the other side but unfortunately\n";
	cout << "the bridge has been retracted into the wall of the shaft,\n";

	cout << "What do you want to do?\n" << endl;
	cout << "[1] Jump across" << endl;
	cout << "[2] Check your stormtrooper belt" << endl;
	cout << "[3] Other options" << endl;
	cout << "Enter selection: ";
}

/*********************************************************************
** Function: spaceSpecial
** Description: checks if user has grappling hook, displays appropriate 
** message and sets variables. If user does not have grappling hook, 
** game is over, if user does, nextSpace is opened.
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: changes lightsOn variable to opposite, displays
** appropriate message.
*********************************************************************/
void CentralCoreShaft::spaceSpecial()
{
	if (!rappelledAcross)
	{
		if (spaceHasItem) // If user hasn't picked up grappling hook, game is over
		{
			cout << "\nYou bravely, and foolishly, take a leap of faith.\n";
			cout << "...................\n";
			cout << "...................\n";
			cout << "...................\n";
			cout << "You plunge to your death with a pang of regret\n";
			cout << "that you did not exhaust your options before resorting to this.\n";

			player->setGameOver(true);
		}
		else if (!rappelledAcross) // if user has grappling hook
		{
			cout << "\nYou pull out your newly found grappling hook and take careful aim\n";
			cout << "before flinging it madly at a pipe midway across the chasm.\n";
			cout << "Miraculously it wraps around the pipes and hooks onto itself!\n";
			cout << "You tug on the rope to make sure it is secure,\n";
			cout << "then grab the princess in your arms.\n";
			cout << "Leia looks at you, then kisses you quickly on the lips.\n";
			cout << "It's nice but also strangely like kissing your sister.....\n";
			cout << "Nevermind that. You swing across to the other side safely.\n";

			nextRoomOpen = true;
			rappelledAcross = true;
		}
	}
	else // user goes back to original side
	{
		cout << "You rappel back across the chasm.\n";
		rappelledAcross = !rappelledAcross;
	}
	
}

/*********************************************************************
** Function: exitOptions
** Description: Displays menu for exits and returns user choice
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: user choice for exit location returned.
*********************************************************************/
Space* CentralCoreShaft::exitOptions()
{
	int exitChoice;
	cout << "\nOther Options:" << endl;
	cout << "[1] Exit through far door" << endl;
	cout << "[2] Return to Power Control room" << endl;
	cout << "Enter selection: ";
	cin >> exitChoice;

	while (exitChoice < 1 || exitChoice > 2)
	{
		cout << "Enter valid selection:";
		cin >> exitChoice;
	}

	if (exitChoice == 1)
	{
		if (rappelledAcross && nextRoomOpen)
		{
			cout << "\nYou exit through the far door.\n";
			nextRoom->setCompartmentAOpen(true);
			return nextRoom;

		}
		else
		{
			cout << "\nYou need to cross the chasm to be able to exit." << endl;

			return this;
		}
	}
	else if (exitChoice == 2)
	{
		if (!rappelledAcross)
		{
			cout << "\nYou blasted the controls so it won't open...." << endl;
			return this;

		}
		else
		{
			cout << "\nYou need to cross the chasm to get to this door.\n";
			return this;
		}
	}
	return this;

}