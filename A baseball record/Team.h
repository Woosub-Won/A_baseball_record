#pragma once
#include <string>
#include "Player.h"

using namespace std;

class Team
{
public:
	Team(const string n);

public:
	string name;
	Player* player;
	Player startingPlayer[10];
	Player* pitcher;
	Player* hitter;
	int numOfPitcher;
	int numOfHitter;

public:
	void setStartingPlayer();
	void printStartingPlayer();
	void setPitcher();
	void setHitter();
	void printPitcher();
	void printHitter();
	void printAllPlayer();
	void swapPlayer(Player* A, Player* B);
};

