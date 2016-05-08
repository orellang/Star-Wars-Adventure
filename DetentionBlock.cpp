/*********************************************************************
** Program Filename: DetentionBlock.cpp
** Author: Gabriel Orellana
** Date: 11/25/2015
** Description: implementation file for derived class DetentionBlock.
** Has bool member and menu, special, and exit functions.
*********************************************************************/
#include "DetentionBlock.h"

// Default constructor setting commsAnswered, spaceHasItem, and spaceItem
DetentionBlock::DetentionBlock()
{
	commsAnswered = false;
	spaceHasItem = true;
	spaceItem = "Cell Keys";
}

/*********************************************************************
** Function: spaceMenu
** Description: Displays menu. User answer comms, search for items,
** or exit area. Checks if user has Cell Keys and Princess Leia. If 
** so, sets appropriate variables to true
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: menu displayed and variables set.
*********************************************************************/
void DetentionBlock::spaceMenu()
{
	// If user has cell keys, opens cells
	if (player->getUtilityBelt()->getBeltItem("Cell Keys"))
	{
		setCompartmentAOpen(true);
		setCompartmentBOpen(true);
	}
	// If user has Princess Leia, opens nextRoom
	if (player->getUtilityBelt()->getBeltItem("Princess Leia"))
	{
		setNextRoomOpen(true);
	}
		
	cout << "\nYou decide to pretend Chewie is your prisoner and\n";
	cout << "place a pair of electronic cuffs on him.\n";
	cout << "The elevator doors open and Han mutters something about\n";
	cout << "how this is not going to work which you find less than reassuring.\n";
	cout << "As an Imperial officer steps forward to question you,\n";
	cout << "Chewie breaks loose and goes on a rampage\n";
	cout << "while you and Han take out all the guards and cameras with your blasters.\n";
	cout << "As the smoke clears, you hear a voice over the comm asking what happened.\n";
	cout << "The Detention Block has two cells which could hold Princess Leia and\n";
	cout << "the comms panel which keeps crackling with a voice asking for your status.\n";

	cout << "What do you want to do?\n" << endl;
	cout << "[1] Answer the comms" << endl;
	cout << "[2] Look for items" << endl;
	cout << "[3] Other options" << endl;
	cout << "Enter selection: ";
}

/*********************************************************************
** Function: spaceMenuVisited
** Description: Displays menu for when space has been visited.
** User answer comms, search for items, or exit area. Checks if user 
** has Cell Keys and Princess Leia. If so, sets appropriate variables
** to true.
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: menu displayed and variables set.
*********************************************************************/
void DetentionBlock::spaceMenuVisited()
{
	// If user has cell keys, opens cells
	if (player->getUtilityBelt()->getBeltItem("Cell Keys"))
	{
		setCompartmentAOpen(true);
		setCompartmentBOpen(true);
	}
	// If user has Princess Leia, opens nextRoom
	if (player->getUtilityBelt()->getBeltItem("Princess Leia"))
	{
		setNextRoomOpen(true);
	}
	cout << "\nYou are in the Detention Block.\n";
	cout << "The Detention Block has two cells and some grating\n";

	if (!commsAnswered)
	{
		cout << "The comms panel keeps crackling with a voice asking for your status.\n";
	}
	
	cout << "What do you want to do?\n" << endl;
	cout << "[1] Answer the comms" << endl;
	cout << "[2] Look for items" << endl;
	cout << "[3] Other options" << endl;
	cout << "Enter selection: ";
}

/*********************************************************************
** Function: spaceSpecial
** Description: displays appropriate message and sets variables to true
** adds bonus time
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: message displayed and variables set
*********************************************************************/
void DetentionBlock::spaceSpecial()
{
	if (!commsAnswered) // if comms haven't been answered yet
	{
		cout << "\nHan picks up the comlink, trying to sound official.\n";
		cout << "\"Everything is under control. Situation normal.\" he says.\n";
		cout << "The voice on the other end doesn't seem to be buying it.\n";
		cout << "Han starts to sound nervous. \"Uh... had a slight weapons malfunction.\n";
		cout << "But, uh, everything's perfectly all right now. We're fine.\n";
		cout << "We're all fine here, now, thank you. How are you?\"\n";
		cout << "They definitely aren't buying it, but Han mentions something\n";
		cout << "about a reactor leak before he blasts the comlink.\n";
		cout << "That should buy you a little time.\n";
		commsAnswered = true;
		setSpaceVisited(true);
		setBonusTime(10); // adds 10 turns
		cout << "Added 10 turns before capture!\n";
	}
	else
	{
		cout << "\nHan blasted the comlink so you really can't do much with it now." << endl;
	}
}

/*********************************************************************
** Function: exitOptions
** Description: Displays menu for exits and returns user choice
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: user choice for exit location returned.
*********************************************************************/
Space* DetentionBlock::exitOptions()
{
	int exitChoice;
	cout << "\nOther Options:" << endl;
	cout << "[1] Check Cell 2187" << endl;
	cout << "[2] Check Cell 2188" << endl;
	cout << "[3] Check grating" << endl;
	cout << "[4] Head back down Turbolift" << endl;
	cout << "Enter selection: ";
	cin >> exitChoice;

	while (exitChoice < 1 || exitChoice > 4)
	{
		cout << "Enter valid selection:";
		cin >> exitChoice;
	}

	if (exitChoice == 1)
	{
		if (compartmentAOpen)
		{
			cout << "\nYou check Cell 2187." << endl;
			setSpaceVisited(true);
			return compartmentA;
			
		}
		else
		{
			cout << "\nThe cell is locked. It looks like you need a key." << endl;

			return this;
		}
	}
	else if (exitChoice == 2)
	{
		if (compartmentBOpen)
		{
			cout << "\nYou check Cell 2188." << endl;
			cout << "Looking inside, you see that it is empty....\n";
			setSpaceVisited(true);
			return this;

		}
		else
		{
			cout << "\nThe cell is locked. It looks like you need a key." << endl;
			return this;
		}
	}
	else if (exitChoice == 3)
	{
		if (nextRoomOpen)
		{
			cout << "\nPrincess Leia blasts open the grating.\n";
			cout << "Han asks her what the hell she's doing and she responds,\n";
			cout << "\"Somebody has to save our skins. Into the garbage chute, wise guy.\"\n";
			setSpaceVisited(true);
			return nextRoom;

		}
		else
		{
			cout << "\nYou look at the grating but aren't sure what to do." << endl;
			return this;
		}
	}
	else if (exitChoice == 4)
	{
		cout << "\nA company of stormtroopers is heading up that way.\n";
		cout << "It Looks like you managed to cut off our only escape route.\n";
		cout << "You won't be using the turbolift anytime soon." << endl;
		return this;
	}
	return this;
}