#include "Cell.h"

// Default constructor setting lights to off
Cell::Cell()
{
	hitOnLeia = false;
	spaceHasItem = true;
	setPreviousRoomOpen(true);
	spaceItem = "Princess Leia";
}

/*********************************************************************
** Function: spaceMenu
** Description: Displays menu and gets user input. User can toggle
** lights or exit area.
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: returns Space pointer for area player travels to
** next
*********************************************************************/
void Cell::spaceMenu()
{
	cout << "\nYou enter the cell and see the dazzling young princess.\n";
	cout << "She had been sleeping and is now looking at you\n";
	cout << "with an uncomprehending look on her face.\n";
	cout << "You are stunned by her incredible beauty and\n";
	cout << "stand staring at her with your mouth hanging open.\n";
	cout << "There is something about her that reminds you of yourself.\n";
	cout << "Almost like you could be......nevermind.\n";
	cout << "She sits up and says, \"Aren't you a little short to be a stormtrooper?\"\n";
	cout << "You snap out of it and tell her your name and\n";
	cout << "that you're here to rescue her. ";
	cout << "She seems incredulous.....\n";

	cout << "What do you want to do?\n" << endl;
	cout << "[1] Put the moves on her" << endl;
	cout << "[2] Convince her to come with you" << endl;
	cout << "[3] Exit cell" << endl;
	cout << "Enter selection: ";
}

void Cell::spaceMenuVisited()
{
	cout << "\nYou reenter the cell." << endl;

	cout << "What do you want to do?\n" << endl;
	cout << "[1] Put the moves on her" << endl;
	cout << "[2] Tell her about Obi-Wan and R2D2" << endl;
	cout << "[3] Exit cell" << endl;
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
void Cell::spaceSpecial()
{
	if (!hitOnLeia)
	{
		cout << "\nYou try all your best pickup lines but she seem unimpressed.\n";
		cout << "Perhaps if you tried another tactic she might come with you." << endl;
		hitOnLeia = true;
	}
	else
	{
		cout << "\nYou already tried this and it didn't go well." << endl;
	}
}

/*********************************************************************
** Function: exitOptions
** Description: Displays menu for exits and returns user choice
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: user choice for exit location returned.
*********************************************************************/
Space* Cell::exitOptions()
{
	cout << "\nYou exit the cell." << endl;
	spaceVisited = true;
	return previousRoom;
}