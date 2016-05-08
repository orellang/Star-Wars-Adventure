/*********************************************************************
** Program Filename: GameClient.cpp
** Author: Gabriel Orellana
** Date: 11/25/2015
** Description: Implementation file for GameClient class. Has 
** clearScreen object vector of Space pointers, int and bool variables,
** has all Spaces needed for game. Has get/set functions for int and 
** bool variables, and functions to add spaces, run start menu, game 
** menu, intro, objectives, gameWon, and gameOver.
*********************************************************************/
#include "GameClient.h"

// Default constructor sets timer to 0, gameOver to false, and points Spaces 
// To each other as necessary
GameClient::GameClient()
{
	timer = 50;
	gameOver = false;
	smuggledGoods.setAdjoiningSpaces(&theFalcon, NULL, NULL, NULL);
	theFalcon.setAdjoiningSpaces(&hangarBay, &cockpit, &smuggledGoods, NULL);
	hangarBay.setAdjoiningSpaces(&commandOffice, &theFalcon, &centralShaft, NULL);
	commandOffice.setAdjoiningSpaces(&detentionBlock, &theFalcon, NULL, NULL);
	detentionBlock.setAdjoiningSpaces(&trashCompactor, NULL, &cell, NULL);
	cell.setAdjoiningSpaces(NULL, &detentionBlock, NULL, NULL);
	trashCompactor.setAdjoiningSpaces(&powerTrench, NULL, NULL, NULL);
	powerTrench.setAdjoiningSpaces(&centralShaft, &trashCompactor, &powerControls, NULL);
	powerControls.setAdjoiningSpaces(NULL, &powerTrench, NULL, NULL);
	centralShaft.setAdjoiningSpaces(&hangarBay, &powerTrench, NULL, NULL);
	cockpit.setAdjoiningSpaces(&theFalcon, NULL, NULL, NULL);
	player.setLocation(&smuggledGoods);
}

// Get/set gameOver and timer
bool GameClient::getGameOver()
{
	return gameOver;
}
void GameClient::setGameOver(bool set)
{
	gameOver = set;
}
int GameClient::getTimer()
{
	return timer;
}
void GameClient::setTimer(int time)
{
	timer = time;
}

// add Game spaces
void GameClient::addGameSpace(Space* s)
{
	// checks if space is already in gameSpaces and adds if it isn't
	bool spaceExists = false;

	for (int i = 0; i < gameSpaces.size(); i++)
	{
		if (s == gameSpaces[i])
		{
			spaceExists = true;
		}
	}

	// if space already in gameSpaces
	if (!spaceExists)
	{
		gameSpaces.push_back(s);
	}
	else
		cout << "Space already added." << endl;
}

/*********************************************************************
** Function: runMenu
** Description: runs space menu for player location. Gets user menu 
** choice and runs appropriate function. Checks for gameOver and 
** gameWon.
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: menu run until player space changed.
*********************************************************************/
void GameClient::runMenu()
{
	int menuChoice;
	Space* spaceToRun = player.getLocation(); // Gets starting Space
	spaceToRun->setPlayer(&player); // Sets player pointer for starting space

	do // Loop run until gameOver or player leaves current space
	{
		// Run initial menu 
		if (!spaceToRun->getSpaceVisited())
			spaceToRun->spaceMenu();
		// Run menu when space has been visited
		else
			spaceToRun->spaceMenuVisited();

		cin >> menuChoice; // Get user menu choice

		// Validate input
		while (!spaceToRun->validateInput(menuChoice))
		{
			cin >> menuChoice;
		}

		switch (menuChoice)
		{
		//Run space special function
		case 1:
			spaceToRun->spaceSpecial();
			break;
		
		// Check for space item, if it has one, add it to player belt
		case 2:
			if (spaceToRun->getSpaceHasItem())
			{
				string itemPickedUp = spaceToRun->getItem();
				player.getItem(itemPickedUp);
				cout << "\nYou picked up " << itemPickedUp << "!" << endl;
				spaceToRun->setSpaceHasItem(false);
			}
			else
				cout << "\nNo items available." << endl;
			break;

		// Run exit options
		case 3:
			spaceToRun = spaceToRun->exitOptions();
			player.getLocation()->setPlayer(NULL);
			player.setLocation(spaceToRun);
			player.getLocation()->setPlayer(&player);
		}

		// Check if game is over
		if (player.getGameOver())
		{
			runGameOver();
		}
		// Check if game has been won
		if (player.getGameWon())
		{
			runGameWon();
		}

		// Check if player has had turns adjusted
		timer += (spaceToRun->getBonusTime());
		spaceToRun->setBonusTime(0);
		timer--;// decrement timer
		
		if (timer < 0) // If timer runs out, game is over
		{
			cout << "\nYou ran out of time and were captured!\n";
			runGameOver();
		}

		// Display turns remaining
		if (!player.getGameOver() && !player.getGameWon())
		cout << "\n" << timer << " turns remaining before you are caught.\n";

		cin.get();
		cS.clearScreen();
		
	
	} while (menuChoice != 3 && !gameOver);
}

/*********************************************************************
** Function: startMenu
** Description: Displays start menu for game
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: menu displayed
*********************************************************************/
void GameClient::startMenu()
{
	cout << "\n                 A Long Time Ago, In A Galaxy Far, Far Away.....\n";
	cS.clearScreen();
	cout << "                  ________________.  ___     .______  \n";
	cout << "                 /                | /   \\    |   _  \\ \n";
	cout << "                |   (-----|  |----`/  ^  \\   |  |_)  | \n";
	cout << "                 \\   \\    |  |    /  /_\\  \\  |      / \n";
	cout << "            .-----)   |   |  |   /  _____  \\ |  |\\  \\-------. \n";
	cout << "            |________/    |__|  /__/     \\__\\| _| `.________| \n";
	cout << "             ____    __    ____  ___     .______    ________. \n";
	cout << "             \\   \\  /  \\  /   / /   \\    |   _  \\  /        | \n";
	cout << "              \\   \\/    \\/   / /  ^  \\   |  |_)  ||   (-----` \n";
	cout << "               \\            / /  /_\\  \\  |      /  \\   \\ \n";
	cout << "                \\    /\\    / /  _____  \\ |  |\\  \\---)   | \n";
	cout << "                 \\__/  \\__/ /__/     \\__\\|__| `._______/ \n";
	cout << "\n";
	cout << "                EPISODE IV.V: ESCAPE FROM THE DEATH STAR\n";
	cout << endl;
	
	cout << "[1] Start New Game\n";
	cout << "[2] See Game Objectives\n";
	cout << "[ANY OTHER INPUT] Exit program\n";
	cout << "Enter your selection: ";
}

/*********************************************************************
** Function: gameIntro
** Description: Displays game intro messages
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: intro displayed
*********************************************************************/
void GameClient::gameIntro()
{
	cS.clearScreen();
	cout << "\n                   YOU ARE THE DARING YOUNG\n";
	cout << "                  HERO LUKE SKYWALKER.  WHILE\n";
	cout << "                TRAVELLING WITH OBI-WAN, HAN SOLO,\n";
	cout << "               CHEWBACCA, R2D2, AND C3PO ON YOUR WAY\n";
	cout << "              TO DELIVER THE DEATH STAR PLANS, YOU COME\n";
	cout << "             OUT OF HYPERSPACE NEAR ALDERAAN,ONLY TO FIND\n";
	cout << "           THAT THE PLANET HAD BEEN DESTROYED!\n";
	cout << endl;
	cout << "         YOU APPROACH A NEARBY MOON, AND REALIZE TOO LATE IT\n";
	cout << "        IS NO MOON, BUT RATHER, THE EMPIRE'S NEW ULTIMATE WEAPON,\n";
	cout << "       THE DREADED DEATH STAR! YOUR ATTEMPTS TO RETREAT ARE IN VAIN      \n";
	cout << "      AND THE FALCON IS CAUGHT IN A TRACTOR BEAM!      \n";
	cout << endl;
	cout << "    AS YOUR SHIP IS BROUGHT ON BOARD, YOU AND YOUR COMPANIONS HIDE IN\n";
	cout << "   THE FALCON'S SMUGGLING COMPARTMENTS. YOU MUST FIND A WAY TO DEACTIVATE      \n";
	cout << "  THE TRACTOR BEAM AND ESCAPE BEFORE YOU ARE CAPTURED OR ELSE THERE WILL BE\n";
	cout << " NOTHING TO STOP THE EMPIRE.....     \n";

	cS.clearScreen();

	cout << "\nYou will play as Luke Skywalker.\n";
	cout << "You have a utility belt which can carry 6 items.\n";
	cout << "You have 50 turns to find a way to escape the Death Star\n";
	cout << "before you are caught and it is Game Over.\n";
	cout << "Don't waste your turns. There are ways to gain additional turns\n";
	cout << "as well as lose turns, so choose wisely.\n";

	cS.clearScreen();
}

/*********************************************************************
** Function: gameObjectives
** Description: Displays game objectives
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: objectives displayed
*********************************************************************/
void GameClient::gameObjectives()
{
	cout << "\nThe objectives for the game are to: \n";
	cout << "Find a way off the ship by getting the stormtrooper armor.\n";
	cout << "Discover Princess Leia is being held on board by accessing the network.\n";
	cout << "Resuce Princess Leia.\n";
	cout << "Deactivate the tractor beam.\n";
	cout << "Escape from the Death Star.\n";
	cout << "All before the timer runs out and without dying.\n";

	cin.get();
	cS.clearScreen();
}

/*********************************************************************
** Function: runGameOver
** Description: Displays game over message and sets game over to true
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: intro displayed and gameover set
*********************************************************************/
void GameClient::runGameOver()
{
	cS.clearScreen();
	cout << "\nYou have failed the mission.\n";
	cout << "There is now nothing to stop the Empire.\n";
	cout << "The fate of the galaxy is sealed......" << endl;
	cout << "\nGAME OVER\n";
	setGameOver(true);
}

/*********************************************************************
** Function: runGameWon
** Description: Displays game won message and sets game over to true
** Parameters: none
** Pre-Conditions: object instantiated
** Post-Conditions: intro displayed and gameover set
*********************************************************************/
void GameClient::runGameWon()
{
	cS.clearScreen();
	cout << "\nAs Han pilots the Falcon away from the Death Star,\n";
	cout << "the realization that Obi-Wan is gone sinks in.\n";
	cout << "You don't have time to mourn at the moment though,\n";
	cout << "as you hear Han shouting about enemy fighters closing fast.\n";
	cout << "You run to man the guns, and after a thrilling battle\n";
	cout << "the fighters are defeated and you make the jump to lightspeed.\n";
	cout << "You successfully escape with the plans which can destroy the Death Star.\n";
	cout << "Though the loss of Obi-Wan weighs heavily on your heart,\n";
	cout << "you feel as if he is still with you somehow...\n";
	cout << endl;
	cout << endl;
	cout << "THE END\n";
	setGameOver(true);

}