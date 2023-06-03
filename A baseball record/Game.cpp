#include <iostream>
#include "Player.h"
#include "Team.h"
#include "Inning.h"
#include <string>

using namespace std;

void printBoard(Inning innings[][2], string a, string b, int cnt);

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
	cout << "Team B : ";
	cin >> B_team;

	Team B(B_team);
	B.setHitter();
	B.setPitcher();
	B.setStartingPlayer();
	B.printStartingPlayer();
	B.printAllPlayer();

	Inning innings[9][2];
	int idxA = 0;
	int idxB = 0;
	for (int i = 0; i < 9; i++)
	{
		cout << i + 1 << "회" << " 초" << endl;
		idxA = innings[i][0].inputHitterData(&A, &B, idxA);
		A.reflectBoard(innings[i][0].H, innings[i][0].B, innings[i][0].E, innings[i][0].R);
		
		printBoard(innings, A.name, B.name, i + 1);

		cout << i + 1 << "회" << " 말" << endl;
		idxB = innings[i][1].inputHitterData(&B, &A, idxB);
		B.reflectBoard(innings[i][1].H, innings[i][1].B, innings[i][1].E, innings[i][1].R);

		printBoard(innings, A.name, B.name, i + 1);
	}
}

void printBoard(Inning innings[][2], string a, string b, int cnt)
{
	cout << "-------------------------------------------------------------" << endl;
	cout << "l TEAM ";
	for (int i = 0; i < 9; i++)
	{
		cout << "l " << i + 1 << " ";
	}
	cout << endl << "-------------------------------------------------------------" << endl;
	cout << "l " << a << " l";
	for (int i = 0; i < cnt; i++)
	{
		cout << " " << innings[i][0].R << " l";
	}
	cout << endl << "-------------------------------------------------------------" << endl;
	cout << "l " << b << " l";
	for (int i = 0; i < cnt; i++)
	{
		cout << " " << innings[i][1].R << " l";
	}
	cout << endl << "-------------------------------------------------------------" << endl;
}