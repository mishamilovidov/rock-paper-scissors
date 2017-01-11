#include <iostream>
#include <string>
#include <sstream>
#pragma once

using namespace std;

class Player
{
private:
	string name;
	int wins;
	int losses;
	int draws;
	int fights;
	double winRecord;

public:
	//---------------------------------------------------------------------------------------
	/*
	* Constructor/Destructor
	*
	* Handles creation and deletion of Player objects.
	*
	* Parameter: name_in
	*		The name of a new player
	*/
	Player(string nameInput);
	~Player();
	//---------------------------------------------------------------------------------------
	/*
	* getName
	*
	* Returns the name of the player.
	*
	* Return:
	*		The name of the player
	*/
	string getName();
	//---------------------------------------------------------------------------------------
	/*
	* getWins
	*
	* Returns the number of wins.
	*
	* Return:
	*		The number of wins
	*/
	int getWins();
	int getWins(int new_wins);
	//---------------------------------------------------------------------------------------
	/*
	* getLosses
	*
	* Returns the number of losses.
	*
	* Return:
	*		The number of losses
	*/
	int getLosses();
	int getLosses(int new_loses);
	//---------------------------------------------------------------------------------------
	/*
	* getDraws
	*
	* Returns the number of draws
	*
	* Return:
	*		The number of draws
	*/
	int getDraws();
	int getDraws(int new_draws);
	//---------------------------------------------------------------------------------------
	/*
	* winner
	*
	* Changes the status of the winning player to winner
	*
	* Parameter: winner
	*		The player whose status needs to be changed
	*/
	void winner(string winner);
	//---------------------------------------------------------------------------------------
	/*
	*getRPSThrow
	*
	*Returns random number out of three options: 0, 1, 2 (representing rock, paper, scissors)
	*
	*Return:
	*	0, 1, or 2
	*/
	int getRPSThrow();
	//---------------------------------------------------------------------------------------
	/*
	*getWinRecord
	*
	*Returns the win record of the player
	*
	*Return:
	*	The win record as a double
	*/
	double getWinRecord(int new_fights);
	//---------------------------------------------------------------------------------------
	/*
	* toString
	*
	* Returns a single string containing useful information about the player.
	*
	* Return:
	*		A data string about this car
	*/
	string toString();
};
