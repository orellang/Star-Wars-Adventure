/*********************************************************************
** Program Filename: Cockpit.h
** Author: Gabriel Orellana
** Date: 11/25/2015
** Description: header file for derived class Cockpit.
** Has menu, special, and exit functions.
*********************************************************************/
#ifndef COCKPIT_H	
#define COCKPIT_H

#include "Space.h"

class Cockpit : public Space
{
protected:

public:

	Cockpit();
	void spaceMenu();
	void spaceMenuVisited();
	Space* exitOptions();
	void spaceSpecial();
};


#endif
