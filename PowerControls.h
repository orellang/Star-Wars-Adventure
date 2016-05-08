/*********************************************************************
** Program Filename: PowerControls.h
** Author: Gabriel Orellana
** Date: 11/25/2015
** Description: header file for derived class PowerControls.
** Has bool member and menu, special, and exit functions.
*********************************************************************/
#ifndef POWERCONTROLS_H	
#define POWERCONTROLS_H

#include "Space.h"

class PowerControls : public Space
{
protected:

	bool powerOff;

public:

	PowerControls();
	void spaceMenu();
	void spaceMenuVisited();
	Space* exitOptions();
	void spaceSpecial();
};


#endif

