/*********************************************************************
** Program Filename: Space.cpp
** Author: Gabriel Orellana
** Date: 11/25/2015
** Description: Implementation file for abstract class Space. Has pointer
** to Player 4 space pointers, 6 bool, string, and int members. Has
** functions to and 2 bool members. Has constructor, and functions to
** get and set all member variables, set all Space pointers
** simultaneously, and pure virtual functions.
*********************************************************************/
#include "Space.h"

// Default constructor setting space pointers to null and all bools to false
Space::Space()
{
	nextRoom = NULL, previousRoom = NULL, compartmentA = NULL, compartmentB = NULL;
	nextRoomOpen = false, previousRoomOpen = false;
	compartmentAOpen = false, compartmentBOpen = false;
	spaceVisited = false;
	spaceHasItem = false;
	bonusTime = 0;
}

// Finds item in space items and returns it while removing item from spaceItems
string Space::getItem()
{
	spaceHasItem = false;
	return spaceItem;
}

// Adds item to spaceItems
void Space::setItem(string item)
{
	spaceItem = item;
	spaceHasItem = true;
}

bool Space::getSpaceHasItem()
{
	return spaceHasItem;
}
void Space::setSpaceHasItem(bool set)
{
	spaceHasItem = set;
}

// Get/set bonus time
int Space::getBonusTime()
{
	return bonusTime;
}
void Space::setBonusTime(int time)
{
	bonusTime = time;
}

// returns spaceVisited
bool Space::getSpaceVisited()
{
	return spaceVisited;
}

// sets spaceVisited
void Space::setSpaceVisited(bool sV)
{
	spaceVisited = sV;
}

// sets adjoining spaces
void Space::setAdjoiningSpaces(Space* next, Space* previous, Space* a, Space* b)
{
	nextRoom = next;
	previousRoom = previous;
	compartmentA = a;
	compartmentB = b;
}

// Get/set Space pointers
Space* Space::getNextRoom()
{
	return nextRoom;
}
Space* Space::getpreviousRoom()
{
	return previousRoom;
}
Space* Space::getCompartmentA()
{
	return compartmentA;
}
Space* Space::getCompartmentB()
{
	return compartmentB;
}
void Space::setNextRoom(Space* nR)
{
	nextRoom = nR;
}
void Space::setPreviousRoom(Space* pR)
{
	previousRoom = pR;
}
void Space::setCompartmentA(Space* cA)
{
	compartmentA = cA;
}
void Space::setCompartmentB(Space* cB)
{
	compartmentB = cB;
}

// Get/set open variables
void Space::setNextRoomOpen(bool status)
{
	nextRoomOpen = status;
}
void Space::setPreviousRoomOpen(bool status)
{
	previousRoomOpen = status;
}
void Space::setCompartmentAOpen(bool status)
{
	compartmentAOpen = status;
}
void Space::setCompartmentBOpen(bool status)
{
	compartmentBOpen = status;
}
bool Space::getNextRoomOpen()
{
	return nextRoomOpen;
}
bool Space::getPreviousRoomOpen()
{
	return previousRoomOpen;
}
bool Space::getCompartmentAOpen()
{
	return compartmentAOpen;
}
bool Space::getCompartmentBOpen()
{
	return compartmentBOpen;
}

// Checks user input to see if valid for menu
bool Space::validateInput(int input)
{
	if (input >= 1 && input <= 3)
		return true;
	else
	{
		cout << "Please enter a valid menu selection: " << endl;
		return false;
	}
}

// Get and set player
Player* Space::getPlayer()
{
	return player;
}
void Space::setPlayer(Player* p)
{
	player = p;
}