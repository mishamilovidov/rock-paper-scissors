#include "Player.h"
#include <ctime>
#include <cstdlib>

using namespace std;

//---------------------------------------------------------------------------------------
Player::Player(string nameInput)
{
	name = nameInput;
	wins = 0;
	losses = 0;
	draws = 0;
	fights = 0;
	winRecord = 0;
}
Player::~Player() {}
//---------------------------------------------------------------------------------------
string Player::getName()
{
	return name;
}
int Player::getWins()
{
	return wins;
}
int Player::getWins(int new_wins)
{
	wins += new_wins;
	return wins;
}
int Player::getLosses()
{
	return losses;
}
int Player::getLosses(int new_losses)
{
	losses += new_losses;
	return losses;
}
int Player::getDraws()
{
	return draws;
}
int Player::getDraws(int new_draws)
{
	draws += new_draws;
	return draws;
}
//---------------------------------------------------------------------------------------
int Player::getRPSThrow()
{
	int RPSThrow = rand() % 3;

	return RPSThrow;
}
//---------------------------------------------------------------------------------------
double Player::getWinRecord(int new_fights)
{
	fights = fights + new_fights;
	winRecord = ((double)wins / fights) * 100;

	return winRecord;
}
//---------------------------------------------------------------------------------------
string Player::toString()
{
	stringstream ss;
	ss << "Name: " << name << endl;
	ss << "Wins: " << wins << endl;
	ss << "Losses: " << losses << endl;
	ss << "Draws: " << draws << endl;
	ss << "Win Record: " << winRecord << "%" << endl;

	return ss.str();
}
//---------------------------------------------------------------------------------------
