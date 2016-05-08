/*********************************************************************
** Program Filename: TrashCompactor.h
** Author: Gabriel Orellana
** Date: 11/25/2015
** Description: header file for derived class TrashCompactor.
** Has bool member and menu, special, and exit functions.
*********************************************************************/
#ifndef TRASHCOMPACTOR_H	
#define TRASHCOMPACTOR_H

#include "Space.h"

class TrashCompactor : public Space
{
protected:

	bool usedCommunicator;

public:

	TrashCompactor();
	void spaceMenu();
	void spaceMenuVisited();
	Space* exitOptions();
	void spaceSpecial();
};


#endif


