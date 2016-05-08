/*********************************************************************
** Program Filename: Belt.h
** Author: Gabriel Orellana
** Date: 11/27/2015
** Description:  Header file for Belt class with vector of 
** of strings, int for size, constructor setting size and functions to 
** add and remove items from belt and display belt items.
*********************************************************************/
#ifndef BELT_H
#define BELT_H

#include <vector>
using std::vector;
#include <string>
using std::string;

class Belt
{
protected:

	vector<string> beltItems; // holds items
	int beltSize; // number of items belt can hold

public:

	Belt(); // default constructor
	void setBeltSize(int);
	bool getBeltItem(string);
	bool addBeltItem(string); // add item to belt
	bool removeBeltItem(string); // remove item from belt
	void displayBeltItems(); // displays all items in belt
};


#endif
