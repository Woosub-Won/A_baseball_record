#include <iostream>
#include "Player.h"
#include "Team.h"
#include "Inning.h"
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

	cout << endl;
	/*cout << "Team B : ";
	cin >> B_team;

	Team B(B_team);
	B.setHitter();
	B.setPitcher();
	B.setStartingPlayer();
	B.printStartingPlayer();
	B.printAllPlayer();*/

	Inning innings[9][2];
	for (int i = 0; i < 9; i++)
	{
		cout << i + 1 << "회" << " 초" << endl;
		innings[i][0].inputHitterData();
		cout << i + 1 << "회" << " 말" << endl;
		innings[i][1].inputHitterData();
	}
}