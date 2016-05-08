/*********************************************************************
** Program Filename: clearScreen.cpp
** Author: Gabriel Orellana
** Date: 11/25/2015
** Description: Class clearScreen. Has function to pause until user 
** hits enter, then clears the screen.
*********************************************************************/
#ifndef CLEARSCREEN_HPP
#define CLEARSCREEN_HPP
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class ClearScreen
{
public:
	void clearScreen() // Pauses program until user hits enter, then clears screen
	{
		// pause for user to be ready to continue
		cout << "\nPress ENTER to continue." << endl;
		cout << std::flush;
		cin.sync();
		cin.ignore();
		//cin.get();
		system("CLS");
	}

};

#endif

