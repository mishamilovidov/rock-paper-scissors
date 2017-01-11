#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include "Player.h"
#pragma once

using namespace std;

/*
TEST CASES:
CASE 1:
Inputs: 3, 3, 3, 4, 4, 4, 5, 5, 1
Expected: Add Name three times, add names to line-up three times, one fight runs, second fight doesn't run because there's only one player, list all players with updated information
Actual: Add Name three times, add names to line-up three times, one fight runs, second fight doesn't run because there's only one player, list all players with updated information

CASE 2:
Inputs: 5, 1, 2, 3, 3, 4, 5, 4, 5, 1
Expected: Fight doesn't run, no one in list, no one on line up, add name, add name, add name to line up, fight does not run, add another player to line up, fight runs, players listed with updated information
Actual: Fight doesn't run, no one in list, no one on line up, add name, add name, add name to line up, fight does not run, add another player to line up, fight runs, players listed with updated information

CASE 3:
Inputs: 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 5, 5, 5, 1
Expected: Add 6 people to list, add 6 people to line up, fight can run 3 times, players displayed with updated values
Actual: Add 6 people to list, add 6 people to line up, fight can run 3 times, players displayed with updated values

*/

const int EXIT_PROGRAM_OR_FUNCTION = -1;

//Displays all players along with their recorded wins, losses, and draws
void displayAllPlayers(vector<Player*> allPlayers)
{
	if (allPlayers.size() == 0)
	{
		cout << "There are currently no players." << endl << endl;
	}
	else
	{
		for (int playerIndex = 0; playerIndex < allPlayers.size(); playerIndex++)
		{
			cout << allPlayers[playerIndex]->toString();
			cout << endl;
		}
	}
}

//Searches through vector to see if input matches name on the list
int searchAndFindPlayer(vector<Player*> allPlayers, string userNameChoice)
{
	for (int playerIndex = 0; playerIndex < allPlayers.size(); playerIndex++)
	{
		if (userNameChoice == allPlayers[playerIndex]->getName())
		{
			return playerIndex;
		}
	}
	return EXIT_PROGRAM_OR_FUNCTION;
}

//Adds player to player list based on user input as long as name isn't already on the list
void addToPlayerList(vector<Player*> &allPlayers)
{
	cout << "Please enter Player name: ";
	cin.ignore();
	string nameInput;
	getline(cin, nameInput);

	string userNameChoice = nameInput;
	int found = searchAndFindPlayer(allPlayers, userNameChoice);

	if (found != -1)
	{
		cout << "Sorry, this player was already in the vector" << endl << endl;
	}
	else
	{
		Player* p = new Player(nameInput);
		allPlayers.push_back(p);
		cout << nameInput << " was added as a player." << endl << endl;
	}
}

//Adds player to line up based on user input as long as name isn't already on the line up list
void addToLineUp(vector<Player*> allPlayers, vector<Player*> &lineUp)
{
	cout << "Which player would you like to add to the line up? ";
	cin.ignore();
	string nameInput;
	getline(cin, nameInput);

	string userNameChoice = nameInput;
	int found = searchAndFindPlayer(allPlayers, userNameChoice);

	if (found != EXIT_PROGRAM_OR_FUNCTION)
	{
		Player* new_player = allPlayers[found];
		lineUp.push_back(new_player);
		cout << nameInput << " was added to the line up." << endl << endl;
	}
	else
	{
		cout << nameInput << " was not added to the line up because " << nameInput << " is not on the player list." << endl << endl;
	}
}

//Displays players in the line up along with their recorded wins, losses, and draws
void displayLineUp(vector<Player*> lineUp)
{
	if (lineUp.size() == 0)
	{
		cout << "There are no players in the line up." << endl;
	}
	else
	{
		for (int playerIndex = 0; playerIndex < lineUp.size(); playerIndex++)
		{
			cout << "LINE UP SLOT " << playerIndex << ": " << lineUp[playerIndex]->getName();
			cout << endl;
		}
	}

	cout << endl;
}

void fight(vector<Player*> &lineUp)
{
	if (lineUp.size() >= 2)
	{
		const int ROCK = 0;
		const int PAPER = 1;
		const int SCISSORS = 2;

		int new_wins = 0;
		int new_losses = 0;
		int new_draws = 0;
		int new_fights = 0;

		Player* fighter1 = lineUp[0];
		Player* fighter2 = lineUp[1];

		cout << "Fight initiated between " << lineUp[0]->getName() << " and " << lineUp[1]->getName() << "!" << endl;

		//if a player fights himself, it's an automatic draw
		if (fighter1 == fighter2)
		{

			cout << "It's a draw because the player fought himself/herself!" << endl << endl;
			new_draws++;
			fighter1->getDraws(new_draws);
			fighter2->getDraws(new_draws);
		}

		else
		{
			//fighter1 choice
			cout << fighter1->getName() << " choice: ";
			int random1 = fighter1->getRPSThrow();
			if (random1 == ROCK)
			{
				cout << "Rock!" << endl;
			}
			else if (random1 == PAPER)
			{
				cout << "Paper!" << endl;
			}
			else if (random1 == SCISSORS)
			{
				cout << "Scissors!" << endl;
			}

			//fighter2 choice
			cout << fighter2->getName() << " choice: ";
			int random2 = fighter2->getRPSThrow();
			if (random2 == ROCK)
			{
				cout << "Rock!" << endl;
			}
			else if (random2 == PAPER)
			{
				cout << "Paper!" << endl;
			}
			else if (random2 == SCISSORS)
			{
				cout << "Scissors!" << endl;
			}

			//Outcome
			if (random1 == random2)//if both players throw the same option
			{
				cout << endl << "It's a draw!" << endl << endl;//if a player fights himself, it's an automatic draw.
				new_draws++;
				fighter1->getDraws(new_draws);
				fighter2->getDraws(new_draws);
			}
			//if fighter2 wins
			if ((random1 == ROCK && random2 == PAPER) || (random1 == PAPER && random2 == SCISSORS) || (random1 == SCISSORS && random2 == ROCK))
			{
				cout << endl << fighter2->getName() << " wins!" << endl << endl;
				new_wins++;
				fighter2->getWins(new_wins);

				new_losses++;
				fighter1->getLosses(new_losses);

			}
			//if fighter1 wins
			if ((random1 == ROCK && random2 == SCISSORS) || (random1 == PAPER && random2 == ROCK) || (random1 == SCISSORS && random2 == PAPER))
			{
				cout << endl << fighter1->getName() << " wins!" << endl << endl;
				new_wins++;
				fighter1->getWins(new_wins);

				new_losses++;
				fighter2->getLosses(new_losses);

			}
		}

		new_fights++;
		fighter1->getWinRecord(new_fights);
		fighter2->getWinRecord(new_fights);

		//erase the two players that just competed in the line up
		lineUp.erase(lineUp.begin() + 0);
		lineUp.erase(lineUp.begin() + 0);
	}
	else
	{
		cout << "There are not enough players in the line up for a fight." << endl << endl;
	}
}

int main()
{
	vector<Player*> allPlayers;
	vector<Player*> lineUp;
	srand(time(0));

	int runProgram = 0;

	cout << "Welcome to the Tournament!" << endl;

	while (runProgram == 0)
	{
		cout << "Please select an option:" << endl;
		cout << "1 - Show all contestants" << endl;
		cout << "2 - Add a player" << endl;
		cout << "3 - Add a player to the line-up" << endl;
		cout << "4 - Show current line up" << endl;
		cout << "5 - Fight!" << endl;
		cout << "6 - Exit program" << endl << endl;

		int input;
		cin >> input;

		if (input == 1)
		{
			displayAllPlayers(allPlayers);
		}
		else if (input == 4)
		{
			displayLineUp(lineUp);
		}
		else if (input == 2)
		{
			addToPlayerList(allPlayers);
		}
		else if (input == 3)
		{
			addToLineUp(allPlayers, lineUp);
		}
		else if (input == 5)
		{
			fight(lineUp);
		}
		else if (input == 6)
		{
			runProgram = EXIT_PROGRAM_OR_FUNCTION;
		}
	}

	cout << endl;
	std::system("pause");
	return 0;
}
