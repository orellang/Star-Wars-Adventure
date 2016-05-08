/*********************************************************************
** Program Filename: Cockpit.cpp
** Author: Gabriel Orellana
** Date: 11/25/2015
** Description: implementation file for derived class Cockpit.
** Has menu, special, and exit functions.
*********************************************************************/
#include "Cockpit.h"

// Default constructor setting previousRoomOpen to true
Cockpit::Cockpit()
{
	setPreviousRoomOpen(true);
}

/*********************************************************************
** Function: spaceMenu
** Description: Displays menu and gets user input. User can complete 
** game, search for items, or exit area.
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: menu displayed
*********************************************************************/
void Cockpit::spaceMenu()
{
	cout << "\nYou enter the cockpit and Han and Chewie take the controls." << endl;
	cout << "Laser bolts from the stormtroopers outside pelt the side of the Falcon.\n";
	cout << "Now would be a good time to leave." << endl;

	cout << "What do you want to do?\n" << endl;
	cout << "[1] Get the heck out of there" << endl;
	cout << "[2] Look for items" << endl;
	cout << "[3] Exit Cockpit" << endl;
	cout << "Enter selection: ";
}

/*********************************************************************
** Function: spaceMenuVisited
** Description: Same as spaceMenu
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: menu displayed
*********************************************************************/
void Cockpit::spaceMenuVisited()
{
	cout << "\nYou enter the cockpit and Han and Chewie take the controls." << endl;
	cout << "Laser bolts from the stormtroopers outside pelt the side of the Falcon.\n";
	cout << "Now would be a good time to leave." << endl;

	cout << "What do you want to do?\n" << endl;
	cout << "[1] Get the heck out of there" << endl;
	cout << "[2] Look for items" << endl;
	cout << "[3] Exit Cockpit" << endl;
	cout << "Enter selection: ";
}

/*********************************************************************
** Function: spaceSpecial
** Description: displays message and sets gameWon to true
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: message displayed, gameWon set to true.
*********************************************************************/
void Cockpit::spaceSpecial()
{
	cout << "\nHan pulls back on the controls and the ship begins to move.\n";
	cout << "You can hear the dull thud of laser bolts bouncing\n";
	cout << "off the outside of the ship as Chewie adjusts his controls.\n";
	cout << "The Millennium Falcon powers away from the Death Star docking bay,\n";
	cout << "makes a spectacular turn and disappears into the vastness of space.\n";
	cin.get();

	player->setGameWon(true);
}

/*********************************************************************
** Function: exitOptions
** Description: Displays exit message and returns nextRoom
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: nextRoom returned.
*********************************************************************/
Space* Cockpit::exitOptions()
{
	cout << "\nYou exit the cockpit." << endl;
	spaceVisited = true;
	return nextRoom;
}