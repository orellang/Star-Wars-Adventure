/*********************************************************************
** Program Filename: Cell.h
** Author: Gabriel Orellana
** Date: 11/25/2015
** Description: header file for derived class Cell.
** Has bool member and menu, special, and exit functions.
*********************************************************************/
#ifndef CELL_H	
#define CELL_H

#include "Space.h"

class Cell : public Space
{
protected:

	bool hitOnLeia;

public:

	Cell();
	void spaceMenu();
	void spaceMenuVisited();
	Space* exitOptions();
	void spaceSpecial();
};


#endif

