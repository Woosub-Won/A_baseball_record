#include <iostream>
#include "Player.h"
#include "Team.h"
#include <string>

using namespace std;

int main()
{
	string A_team;
	string B_team;

	cout << "Team A : ";
	cin >> A_team;

	Team A(A_team);
	A.setHitter();
	A.setPitcher();
	A.setStartingPlayer();
	A.printStartingPlayer();
	A.printAllPlayer();

}