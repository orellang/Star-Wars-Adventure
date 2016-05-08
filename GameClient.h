/*********************************************************************
** Program Filename: GameClient.h
** Author: Gabriel Orellana
** Date: 11/25/2015
** Description: header file for GameClient class. Has clearScreen object
** vector of Space pointers, int and bool variables, has all Spaces 
** needed for game. Has get/set functions for int and bool variables, 
** and functions to add spaces, run start menu, game menu, intro, 
** objectives, gameWon, and gameOver.
*********************************************************************/
#include "CargoCompartment.h"
#include "MillenniumFalcon.h"
#include "CommandOffice.h"
#include "DetentionBlock.h"
#include "Cell.h"
#include "TrashCompactor.h"
#include "PowerTrench.h"
#include "PowerControls.h"
#include "CentralCoreShaft.h"
#include "HangarBay.h"
#include "Cockpit.h"
#include "clearScreen.hpp"
#include "Player.h"

class GameClient
{
protected:
	
	ClearScreen cS; // used to clear screen when needed
	vector<Space*> gameSpaces; // Hold Spaces
	Player player;
	int timer;
	bool gameOver;

	// Spaces for game
	CargoCompartment smuggledGoods;
	MillenniumFalcon theFalcon;
	Cockpit cockpit;
	HangarBay hangarBay;
	CommandOffice commandOffice;
	DetentionBlock detentionBlock;
	Cell cell;
	TrashCompactor trashCompactor;
	PowerTrench powerTrench;
	PowerControls powerControls;
	CentralCoreShaft centralShaft;

public:

	GameClient();
	bool getGameOver();
	void setGameOver(bool);
	int getTimer();
	void setTimer(int);
	void addGameSpace(Space*);

	void runMenu();
	void startMenu();
	void gameIntro();
	void gameObjectives();
	void runGameWon();
	void runGameOver();

};
