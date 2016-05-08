/*********************************************************************
** Program Filename: TrashCompactor.cpp
** Author: Gabriel Orellana
** Date: 11/25/2015
** Description: implementation file for derived class TrashCompactor.
** Has bool member and menu, special, and exit functions.
*********************************************************************/
#include "TrashCompactor.h"

// Default constructor setting usedCommunicator to false
TrashCompactor::TrashCompactor()
{
	usedCommunicator = false;
}

/*********************************************************************
** Function: spaceMenu
** Description: Displays menu. User can toggle use an item, search for
** items, or exit area.
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: menu displayed
*********************************************************************/
void TrashCompactor::spaceMenu()
{
	cout << "\nYou tumble into a large room filled with garbage and muck.\n";
	cout << "Once on your feet, you stumble around looking for an exit.\n";
	cout << "Han and Leia are already bickering.\n";
	cout << "\"What an incredible smell you've discovered! Let's get out of here!\"\n";
	cout << "You finds small hatchway and struggle to get it open.\n";
	cout << "It won't budge....\n";
	cout << "Han in his infinite wisdom decides shooting it is the best option.\n";
	cout << "The blaster bolt bounces off the door and ricochets wildly around\n";
	cout << "nearly hitting all of you.\n";
	cout << "\"Put that thing away! You're going to get us all killed!\" Leia screams\n";
	cout << "As they continue yelling at each other, there is a loud creaking and\n";
	cout << "the walls of the room start moving together.";
	cout << "You need to find a way to get the door open and fast!" << endl;
	

	cout << "What do you want to do?\n" << endl;
	cout << "[1] Use an item" << endl;
	cout << "[2] Look for items" << endl;
	cout << "[3] Exit compactor" << endl;
	cout << "Enter selection: ";

	spaceVisited = true;
}

/*********************************************************************
** Function: spaceMenu
** Description: Displays menuif space has been visited.
** User can toggle use an item, search for items, or exit area.
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: menu displayed
*********************************************************************/
void TrashCompactor::spaceMenuVisited()
{
	cout << "\nYou are in the Trash Compactor.\n";
	cout << "It stinks and you really don't want to be here.\n";

	if (usedCommunicator) 
	{
		cout << "The walls have stopped moving and the door is unlocked.\n" << endl;
	}
	else
	{
		cout << "The walls are still closing in and time is short!\n";
	}

	cout << "What do you want to do?\n" << endl;
	cout << "[1] Use an item" << endl;
	cout << "[2] Look for items" << endl;
	cout << "[3] Exit compactor" << endl;
	cout << "Enter selection: ";
}

/*********************************************************************
** Function: spaceSpecial
** Description: checks if user has comlink, nextRoom is opened, if not
** game is over. displays appropriate message
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: displays appropriate message. Room opened or game
** over
*********************************************************************/
void TrashCompactor::spaceSpecial()
{
	if (!usedCommunicator)
	{
		if (player->getUtilityBelt()->getBeltItem("comlink")) // If user has comlink
		{
			cout << "\nYou pull out the comlink you found in the Command Office.\n";
			cout << "\"Threepio! Come in Threepio! Threepio!  Where could he be?\"\n";
			cout << "He doesn't respond. The walls are closing quickly. You don't have much time.\n";
			cout << "With seconds to go before you are crushed, he finally answers.\n";
			cout << "You scream at him to shut down all the garbage mashers on the detention level.\n";
			cout << "Just as you are about to be crushed, the walls slowly rumble to a halt.\n";
			cout << "The group celebrates, and C3PO tells R2 to unlock the door.\n";

			nextRoomOpen = true;
			usedCommunicator = true;
		}
		else // if user doesn't have comlink game is over
		{
			cout << "\nUnfortunately, none of the items you have are of any use.\n";
			cout << "You regret not being more thorough in your searches of the rooms\n";
			cout << "that you have traveled through.\n";
			cout << "As the walls close in, you really wish you had a second chance at it all...\n";
			cin.get();
			player->setGameOver(true);
		}
	}
	else // if comlink was already used
	{
		cout << "\nYou've already stopped the walls and unlocked the door.\n";
		cout << "There is no need to use an item here." << endl;
	}
}

/*********************************************************************
** Function: exitOptions
** Description: Displays menu for exits and returns user choice
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: user choice for exit location returned.
*********************************************************************/
Space* TrashCompactor::exitOptions()
{
	if (nextRoomOpen)
	{
		cout << "\nYou climb through the trash to the door and exit the compactor." << endl;
		cout << "You head down the hallway and enter a room at the end of the hall." << endl;
		spaceVisited = true;
		return nextRoom;
	}
	else
	{
		cout << "The exit door is sealed tight!" << endl;
		return this;
	}
	
}