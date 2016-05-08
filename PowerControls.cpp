/*********************************************************************
** Program Filename: PowerControls.cpp
** Author: Gabriel Orellana
** Date: 11/25/2015
** Description: implementation file for derived class PowerControls.
** Has bool member and menu, special, and exit functions.
*********************************************************************/
#include "PowerControls.h"

// Default constructor variables and adding item
PowerControls::PowerControls()
{
	powerOff = false;
	spaceHasItem = true;
	setPreviousRoomOpen(true);
	spaceItem = "Tractor Beam Off";
}

/*********************************************************************
** Function: spaceMenu
** Description: Displays menu. User can look for games, power off 
** tractor beam, or exit area.
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: menu displayed and variables set
*********************************************************************/
void PowerControls::spaceMenu()
{
	cout << "\nYou examine the Tractor Beam power controls.\n";
	cout << "There are several lights on it that are red, indicating power is on.\n";
	
	cout << "What do you want to do?\n" << endl;
	cout << "[1] See if it has any games" << endl;
	cout << "[2] Power down the Tractor Beam" << endl;
	cout << "[3] Exit controls" << endl;
	cout << "Enter selection: ";
	spaceVisited = true;
}
/*********************************************************************
** Function: spaceMenu
** Description: Displays appropriate menu. User can look for games, power off
** tractor beam, or exit area.
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: menu displayed and variables set
*********************************************************************/
void PowerControls::spaceMenuVisited()
{
	cout << "\nYou re-examine the Tractor Beam power controls.\n";

	cout << "What do you want to do?\n" << endl;
	cout << "[1] See if it has any games" << endl;
	cout << "[2] Power down the Tractor Beam" << endl;
	cout << "[3] Exit controls" << endl;
	cout << "Enter selection: ";
}

/*********************************************************************
** Function: spaceSpecial
** Description: displays appropriate message
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: appropriate message displayed
*********************************************************************/
void PowerControls::spaceSpecial()
{
	cout << "\nIt looks like all the games have been disabled.\n";
	cout << "You reminisce to the good old days when all windows computers\n";
	cout << "had pinball and several card games for time wasting at work.\n";
}

/*********************************************************************
** Function: exitOptions
** Description: Displays menu for exits and returns user choice
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: user choice for exit location returned.
*********************************************************************/
Space* PowerControls::exitOptions()
{
	cout << "\nYou step away from the controls." << endl;
	return previousRoom;
}