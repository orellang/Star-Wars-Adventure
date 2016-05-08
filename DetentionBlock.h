/*********************************************************************
** Program Filename: DetentionBlock.h
** Author: Gabriel Orellana
** Date: 11/25/2015
** Description: header file for derived class DetentionBlock.
** Has bool member and menu, special, and exit functions.
*********************************************************************/
#ifndef DETENTIONBLOCK_H	
#define DETENTIONBLOCK_H

#include "Space.h"

class DetentionBlock : public Space
{
protected:

	bool commsAnswered;

public:

	DetentionBlock();
	void spaceMenu();
	void spaceMenuVisited();
	Space* exitOptions();
	void spaceSpecial();
};


#endif

