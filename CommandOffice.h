/*********************************************************************
** Program Filename: CommandOffice.h
** Author: Gabriel Orellana
** Date: 11/25/2015
** Description: header file for derived class CommandOffice.
** Has bool member and menu, special, and exit functions.
*********************************************************************/
#ifndef COMMANDOFFICE_H	
#define COMMANDOFFICE_H

#include "Space.h"

class CommandOffice : public Space
{
protected:

	bool checkedSystem;

public:

	CommandOffice();
	void spaceMenu();
	void spaceMenuVisited();
	Space* exitOptions();
	void spaceSpecial();
};


#endif
