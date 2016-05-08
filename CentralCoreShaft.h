/*********************************************************************
** Program Filename: CentralCoreShaft.h
** Author: Gabriel Orellana
** Date: 11/25/2015
** Description: header file for derived class CentralCoreShaft.
** Has 2 bool members and menu, special, and exit functions.
*********************************************************************/
#ifndef CENTRALCORESHAFT_H	
#define CENTRALCORESHAFT_H

#include "Space.h"

class CentralCoreShaft : public Space
{
protected:

	bool lightsOn;
	bool rappelledAcross;

public:

	CentralCoreShaft();
	void spaceMenu();
	void spaceMenuVisited();
	Space* exitOptions();
	void spaceSpecial();
};


#endif
