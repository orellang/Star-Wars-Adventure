/*********************************************************************
** Program Filename: CargoCompartment.h
** Author: Gabriel Orellana
** Date: 11/25/2015
** Description: header file for derived class CargoCompartment. 
** Has bool member and menu, special, and exit functions.
*********************************************************************/
#ifndef CARGOCOMPARTMENT_H	
#define CARGOCOMPARTMENT_H

#include "Space.h"

class CargoCompartment : public Space
{
protected:
	
	bool lightsOn;

public:

	CargoCompartment();
	void spaceMenu();
	void spaceMenuVisited();
	Space* exitOptions();
	void spaceSpecial();	
};


#endif
