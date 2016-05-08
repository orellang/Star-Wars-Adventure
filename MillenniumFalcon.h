/*********************************************************************
** Program Filename: MillenniumFalcon.h
** Author: Gabriel Orellana
** Date: 11/25/2015
** Description: header file for derived class CargoCompartment.
** Has bool member and menu, special, and exit functions.
*********************************************************************/
#ifndef MILLENNIUMFALCON_H	
#define MILLENNIUMFALCON_H

#include "Space.h"

class MillenniumFalcon : public Space
{
protected:

	bool stormtroopersKilled;

public:

	MillenniumFalcon();
	void spaceMenu();
	void spaceMenuVisited();
	Space* exitOptions();
	void spaceSpecial();
};

#endif
