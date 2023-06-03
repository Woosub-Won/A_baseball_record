#include <iostream>
#include "Player.h"
#include "Team.h"
#include "Inning.h"
#include <string>

using namespace std;

void printBoard(Inning innings[][2], string a, string b, int cnt, bool top);

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

	Inning innings[12][2];
	int idxA = 0;
	int idxB = 0;
	for (int i = 0; i < 12; i++)
	{
		cout << i + 1 << "회" << " 초" << endl;
		idxA = innings[i][0].inputHitterData(&A, &B, idxA, i + 1);
		A.reflectBoard(innings[i][0].H, innings[i][0].B, innings[i][0].E, innings[i][0].R);
		A.H += innings[i][0].H;
		A.B += innings[i][0].B;
		A.E += innings[i][0].E;
		A.R += innings[i][0].R;

		printBoard(innings, A.name, B.name, i + 1, true);
		if (i >= 8)
		{
			if (B.R > A.R)
			{
				cout << "Game Over!";
				return 0;
			}
		}

		if (i == 11)
		{
			cout << "check";
		}
		cout << i + 1 << "회" << " 말" << endl;
		idxB = innings[i][1].inputHitterData(&B, &A, idxB, i + 1, false);
		B.reflectBoard(innings[i][1].H, innings[i][1].B, innings[i][1].E, innings[i][1].R);
		B.H += innings[i][1].H;
		B.B += innings[i][1].B;
		B.E += innings[i][1].E;
		B.R += innings[i][1].R;

		printBoard(innings, A.name, B.name, i + 1, false);
		if (i >= 8)
		{
			if (B.R > A.R)
			{
				cout << "Game Over!";
				return 0;
			}
		}
	}
}

void printBoard(Inning innings[][2], string a, string b, int cnt, bool top)
{
	int A_R = 0, B_R = 0;
	int A_H = 0, B_H = 0;
	int A_E = 0, B_E = 0;
	int A_B = 0, B_B = 0;


	cout << "-------------------------------------------------------------" << endl;
	cout << "l TEAM ";
	for (int i = 0; i < 12; i++)
	{
		cout << "l " << i + 1 << " ";
	}
	cout << "l R ";
	cout << "l H ";
	cout << "l E ";
	cout << "l B ";

	cout << endl << "-------------------------------------------------------------" << endl;
	cout << "l " << a << " l";
	for (int i = 0; i < 12; i++)
	{
		if (i < cnt)
		{
			cout << " " << innings[i][0].R << " l";
			A_R += innings[i][0].R;
			A_H += innings[i][0].H;
			A_E += innings[i][0].E;
			A_B += innings[i][0].B;
		}
		else
			cout << "   l";

		if (i >= 8)
			cout << " ";
	}


	cout << A_R << " ";
	cout << "l " << A_H << " ";
	cout << "l " << A_E << " ";
	cout << "l " << A_B << " ";

	cout << endl << "-------------------------------------------------------------" << endl;
	cout << "l " << b << " l";
	int j = cnt;
	if (top)
		j--;
	for (int i = 0; i < 12; i++)
	{
		if (i < j)
		{
			cout << " " << innings[i][1].R << " l";
			B_R += innings[i][1].R;
			B_H += innings[i][1].H;
			B_E += innings[i][1].E;
			B_B += innings[i][1].B;
		}
		else
			cout << "   l";

		if (i >= 8)
			cout << " ";
	}
	cout << B_R << " ";
	cout << "l " << B_H << " ";
	cout << "l " << B_E << " ";
	cout << "l " << B_B << " ";

	cout << endl << "-------------------------------------------------------------" << endl;
}