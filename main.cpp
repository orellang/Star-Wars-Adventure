/*********************************************************************
** Program Filename: main.cpp
** Author: Gabriel Orellana
** Date: 11/25/2015
** Description: Program which runs Star Wars game. It has a gameClient
** object, and runs a menu, getting user input for whether to start
** a new game, get the objective, or exit. Runs the program until user
** elects to quit.
*********************************************************************/
#include "GameClient.h"

/*********************************************************************
** Function: main
** Description: Creates GameClient object, gets user input, runs menu
** and exit when needed
** Parameters: None
** Pre-Conditions: Appropriate headers included
** Post-Conditions: creates GameClient object, displays main menu, 
** runs game loop, exits
*********************************************************************/
int main()
{
	int usrMenuChoice; // hold user menu selection


	GameClient gameClient;
	
	
	do // loop running game until user elects to exit
	{
		GameClient gameClient;
		gameClient.startMenu(); // Runs start menu

		cin >> usrMenuChoice;

		if (usrMenuChoice == 1) // Run new game intro
		{
			gameClient.gameIntro();

			while (!gameClient.getGameOver()) // runs game
			{
				gameClient.runMenu();
			}
		}
		else if (usrMenuChoice == 2) // displays objectives
		{
			gameClient.gameObjectives();
		}
	} while (usrMenuChoice > 0 && usrMenuChoice < 3);
	

	return 0;
}