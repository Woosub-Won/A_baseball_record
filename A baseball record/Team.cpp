#include <iostream>
#include "Team.h"
#include "Player.h"

using namespace std;

Team::Team(const string n)
{
	name = n;
	for (int i = 0; i < 10; i++)
	{
		startingPlayer[i].setName("");
		startingPlayer[i].setNumber(-1);
		startingPlayer[i].setPosition(-1);
	}
	player = nullptr;
	pitcher = nullptr;
	hitter = nullptr;
	numOfPitcher = 0;
	numOfHitter = 0;
	isRegister = false;
}

void Team::setStartingPlayer()
{
	char enter;
	cout << "Do you want to register starting player? [Y/N] ";
	cin >> enter;
	if (enter == 'N')
	{
		isRegister = false;
		return;
	}
	isRegister = true;

	cout << "Starting Player" << endl;
	for (int i = 0; i < 10; i++)
	{
		string p_name;
		int p_number;
		int p_position;

		cout << "player name / back number / position : ";
		cin >> p_name;
		//cout << "player back number : ";
		cin >> p_number;
		//cout << "player position : ";
		cin >> p_position;

		startingPlayer[i].setName(p_name);
		startingPlayer[i].setNumber(p_number);
		startingPlayer[i].setPosition(p_position);
		startingPlayer[i].setStatus(1);

		for (int j = 0; j < numOfHitter && i < 9; j++)
		{
			if (p_name.compare(hitter[j].getName()) == 0)
			{
				hitter[j].setStatus(1);
				break;
			}
		}
	}
	for (int j = 0; j < numOfHitter; j++)
	{
		if (startingPlayer[9].getName().compare(pitcher[j].getName()) == 0)
		{
			pitcher[j].setStatus(1);
			break;
		}
	}
	cout << "------------------------------" << endl;
}

void Team::printStartingPlayer()
{
	if (!isRegister)
	{
		cout << "Not registered Yet!" << endl;
		return;
	}
	cout << endl;
	cout << "Team " << name << endl;
	for (int i = 0; i < 9; i++)
	{
		cout << "No." << i + 1 << "\t" << startingPlayer[i].getName()
			<< "\tposition : " << startingPlayer[i].getPosition() << endl;
	}
	cout << "SP\t" << startingPlayer[9].getName()
		<< "\tposition : " << startingPlayer[9].getPosition() << endl;
}

void Team::setPitcher()
{
	cout << "How many pitcher do you have? ";
	cin >> numOfPitcher;

	pitcher = new Player[numOfPitcher];
	for (int i = 0; i < numOfPitcher; i++)
	{
		string p_name;
		int p_number;

		cout << "player name / back number : ";
		cin >> p_name;
		//cout << "player back number : ";
		cin >> p_number;

		pitcher[i].setName(p_name);
		pitcher[i].setNumber(p_number);
		pitcher[i].setPosition(1);
		pitcher[i].setStatus(0);
	}
	cout << "------------------------------" << endl;

	for (int i = 0; i < numOfPitcher - 1; i++)
	{
		for (int j = 0; j < numOfPitcher - 1; j++)
		{
			if (pitcher[j].getNumber() > pitcher[j + 1].getNumber())
			{
				swapPlayer(&pitcher[j], &pitcher[j + 1]);
			}
		}
	}
}

void Team::setHitter()
{
	cout << "How many hitter do you have? ";
	cin >> numOfHitter;

	hitter = new Player[numOfHitter];
	for (int i = 0; i < numOfHitter; i++)
	{
		string p_name;
		int p_number;
		int p_position;

		cout << "player name / back number / position :  ";
		cin >> p_name;
		//cout << "player back number : ";
		cin >> p_number;
		//cout << "player position : ";
		cin >> p_position;

		hitter[i].setName(p_name);
		hitter[i].setNumber(p_number);
		hitter[i].setPosition(p_position);
		hitter[i].setStatus(0);
	}
	cout << "------------------------------" << endl;

	for (int i = 0; i < numOfHitter - 1; i++)
	{
		for (int j = 0; j < numOfHitter - 1; j++)
		{
			if (hitter[j].getNumber() > hitter[j + 1].getNumber())
			{
				swapPlayer(&hitter[j], &hitter[j + 1]);
			}
		}
	}
}

void Team::printPitcher()
{
	cout << "Pitcher" << endl;
	for (int i = 0; i < numOfPitcher; i++)
	{
		cout << "No." << pitcher[i].getNumber() << "\t" << pitcher[i].getName() << "\tstatus : " << pitcher[i].getStatus() << endl;
	}
}

void Team::printHitter()
{
	cout << "Hitter" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "No." << hitter[i].getNumber() << "\t" << hitter[i].getName()
			<< "\tposition : " << hitter[i].getPosition() << "\tstatus : " << hitter[i].getStatus() << endl;
	}
}


void Team::printAllPlayer()
{
	cout << endl;
	printHitter();
	cout << endl;
	printPitcher();
}

void Team::swapPlayer(Player* A, Player* B)		// A¶û B¶û ½º¿Ò
{
	Player tmp;
	tmp.setName(A->getName());
	tmp.setNumber(A->getNumber());
	tmp.setPosition(A->getPosition(true));
	tmp.setStatus(A->getStatus(true));

	A->setName(B->getName());
	A->setNumber(B->getNumber());
	A->setPosition(B->getPosition(true));
	A->setStatus(B->getStatus(true));

	B->setName(tmp.getName());
	B->setNumber(tmp.getNumber());
	B->setPosition(tmp.getPosition(true));
	B->setStatus(tmp.getStatus(true));
}