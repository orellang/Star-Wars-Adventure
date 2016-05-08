/*********************************************************************
** Program Filename: PowerTrench.h
** Author: Gabriel Orellana
** Date: 11/25/2015
** Description: header file for derived class PowerTrench.
** Has  3 bool members and menu, special, and exit functions.
*********************************************************************/
#ifndef POWERTRENCH_H	
#define POWERTRENCH_H

#include "Space.h"

class PowerTrench : public Space
{
protected:

	bool hidFromStormtrooper;
	bool gotCaught;
	bool tractorBeamOn;

public:

	PowerTrench();
	void spaceMenu();
	void spaceMenuVisited();
	Space* exitOptions();
	void spaceSpecial();
};


#endif