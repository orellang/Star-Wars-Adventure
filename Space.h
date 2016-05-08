/*********************************************************************
** Program Filename: Space.h
** Author: Gabriel Orellana
** Date: 11/25/2015
** Description: header file for abstract class Space. Has pointer 
** to Player 4 space pointers, 6 bool, string, and int members. Has 
** functions to and 2 bool members. Has constructor, and functions to 
** get and set all member variables, set all Space pointers
** simultaneously, and pure virtual functions. 
*********************************************************************/
#include "Player.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;

class Player; // forward declaration of Player class

#ifndef SPACE_H
#define SPACE_H

class Space
{
protected:

	Player* player;
	Space *nextRoom, *previousRoom, *compartmentA, *compartmentB;
	bool nextRoomOpen, previousRoomOpen, compartmentAOpen, compartmentBOpen;
	bool spaceVisited;
	bool spaceHasItem;
	string spaceItem;
	int bonusTime;

public:
	Space();
	bool getSpaceVisited(); // returns whether room has been visited before
	void setSpaceVisited(bool); // set whether room has been visited
	void setAdjoiningSpaces(Space*, Space*, Space*, Space*); // sets all Space pointers
	bool validateInput(int input); // validates user input for menu
	
	
	// Get/set item and get spaceHasItem
	string getItem();
	void setItem(string);
	bool getSpaceHasItem();
	void setSpaceHasItem(bool);
	Player* getPlayer();
	void setPlayer(Player*);
	int getBonusTime();
	void setBonusTime(int);

	// Get/set Space pointers
	Space* getNextRoom();
	Space* getpreviousRoom();
	Space* getCompartmentA();
	Space* getCompartmentB();
	void setNextRoom(Space*);
	void setPreviousRoom(Space*);
	void setCompartmentA(Space*);
	void setCompartmentB(Space*);

	// get/set open variables
	void setNextRoomOpen(bool);
	void setPreviousRoomOpen(bool);
	void setCompartmentAOpen(bool);
	void setCompartmentBOpen(bool);
	bool getNextRoomOpen();
	bool getPreviousRoomOpen();
	bool getCompartmentAOpen();
	bool getCompartmentBOpen();

	// virtual functions
	virtual void spaceMenu() = 0; 
	virtual void spaceMenuVisited() = 0;
	virtual void spaceSpecial() = 0;
	virtual Space* exitOptions() = 0;
};

#endif