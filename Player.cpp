/*********************************************************************
** Program Filename: Player.cpp
** Author: Gabriel Orellana
** Date: 11/25/2015
** Description: Implementation file for Player class. Has pointer to Space,
** belt object, and 2 bool members. Has constructor, and functions to
** get and set location, gameWon, and gameOver.
*********************************************************************/
#include "Player.h"

// Default constructor setting location to NULL
Player::Player()
{
	location = NULL;
	utilityBelt.setBeltSize(6);
	gameOver = false;
	gameWon = false;
}

// Get utilityBelt
Belt* Player::getUtilityBelt()
{
	return &utilityBelt;
}
// Get player location
Space* Player::getLocation()
{
	return location;
}

// Set player location
void Player::setLocation(Space* l)
{
	location = l;
}

void Player::getItem(string item)
{
	getUtilityBelt()->addBeltItem(item);
}

// Get/set game over/won
bool Player::getGameOver()
{
	return gameOver;
}
void Player::setGameOver(bool set)
{
	gameOver = set;
}
// Get/set game over
bool Player::getGameWon()
{
	return gameWon;
}
void Player::setGameWon(bool set)
{
	gameWon = set;
}