/*********************************************************************
** Program Filename: CargoCompartment.cpp
** Author: Gabriel Orellana
** Date: 11/25/2015
** Description: implementation file for derived class CargoCompartment.
** Has bool member and menu, special, and exit functions.
*********************************************************************/
#include "CargoCompartment.h"

// Default constructor setting lights to off
CargoCompartment::CargoCompartment()
{
	lightsOn = false;
	setNextRoomOpen(true);
}

/*********************************************************************
** Function: spaceMenu
** Description: Displays menu. User can toggle
** lights, search for items or exit area.
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: menu displayed
*********************************************************************/
void CargoCompartment::spaceMenu()
{
	cout << "\nYou are in the cargo compartment used for hiding smuggled goods.\n";
	cout << "You comment that it's lucky Han has these and he agrees and says,\n";
	cout << "\"I never thought I'd be smuggling myself in them.\"" << endl;
	cout << "It sounds like the stormtroopers have left the ship." << endl;

	cout << "What do you want to do?\n" << endl;
	cout << "[1] Toggle the lights" << endl;
	cout << "[2] Look for items" << endl;
	cout << "[3] Exit cargo compartment" << endl;
	cout << "Enter selection: ";
}

/*********************************************************************
** Function: spaceMenuVisited
** Description: Displays menu for when space has been visited.
** User can toggle lights, search for items or exit area.
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: menu displayed
*********************************************************************/
void CargoCompartment::spaceMenuVisited()
{
	cout << "\nYou decided to return to the cargo compartment for some unknown reason." << endl;
	cout << "It's still dark." << endl;

	cout << "What do you want to do?\n" << endl;
	cout << "[1] Toggle the lights" << endl;
	cout << "[2] Look for items" << endl;
	cout << "[3] Exit cargo compartment" << endl;
	cout << "Enter selection: ";
}

/*********************************************************************
** Function: spaceSpecial
** Description: Toggles lights and displays appropriate message
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: changes lightsOn variable to opposite, displays
** appropriate message.
*********************************************************************/
void CargoCompartment::spaceSpecial()
{
	if (lightsOn == false)
	{
		cout << "\nYou turn the lights on, revealing a few space rats and a lot of dust." << endl;
		lightsOn = true;
	}
	else
	{
		cout << "\nYou turn the lights off, plunging you back into darkness." << endl;
		lightsOn = false;
	}
}

/*********************************************************************
** Function: exitOptions
** Description: Displays menu for exits and returns space* 
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: user choice for exit location returned.
*********************************************************************/
Space* CargoCompartment::exitOptions()
{
	cout << "\nYou decide to bravely exit the cargo compartment." << endl;
	spaceVisited = true;
	return nextRoom;
}