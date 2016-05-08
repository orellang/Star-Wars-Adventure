/*********************************************************************
** Program Filename: HangarBay.h
** Author: Gabriel Orellana
** Date: 11/25/2015
** Description: header file for derived class HangarBay.
** Has two bool members and menu, special, and exit functions.
*********************************************************************/
#ifndef HANGARBAY_H	
#define HANGARBAY_H

#include "Space.h"

class HangarBay : public Space
{
protected:

	bool blastDoorsOpen;
	bool obiWanDead;

public:

	HangarBay();
	void spaceMenu();
	void spaceMenuVisited();
	Space* exitOptions();
	void spaceSpecial();
};


#endif
