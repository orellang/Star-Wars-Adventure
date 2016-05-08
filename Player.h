/*********************************************************************
** Program Filename: Player.h
** Author: Gabriel Orellana
** Date: 11/25/2015
** Description: header file for Player class. Has pointer to Space, 
** belt object, and 2 bool members. Has constructor, and functions to
** get and set location, gameWon, and gameOver.
*********************************************************************/
#ifndef PLAYER_H
#define PLAYER_H

#include "Space.h"
#include "Belt.h"

class Player
{
protected:
	
	Space* location;
	Belt utilityBelt;
	bool gameOver;
	bool gameWon;

public:

	Player();
	Belt* getUtilityBelt();
	Space* getLocation();
	void setLocation(Space*);
	void getItem(string);
	bool getGameWon();
	void setGameWon(bool);
	bool getGameOver();
	void setGameOver(bool);
};


#endif