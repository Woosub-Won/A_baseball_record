#include "Inning.h"
#include "Team.h"
#include <iostream>
#include <string>

using namespace std;

Inning::Inning()
{
	H = 0;
	B = 0;
	E = 0;
	R = 0;
	O = 0;
	for (int i = 0; i < 4; i++)
	{
		base[i] = 0;
	}

	/*vector<vector<char>> ballCount;
	vector<string> hitter;
	vector<string> hitterResult;*/
}


int Inning::inputHitterData(Team* a, Team* b, int n)	// 牢磊肺 器牢磐 荤侩
{
	int cnt = 0;
	int idx = n;
	while (O < 3)
	{
		if (idx > 8)
			idx = 0;
		int strike = 0, ball = 0;
		cout << a->startingPlayer[idx].getName() << "[" << a->name << "]" << " vs " << "[" << b->name << "]" << b->startingPlayer[9].getName() << endl;

		char option;
		cout << "Do you want to change player? [Y/N] ";
		cin >> option;

		if (option == 'Y')
		{
			cout << "Which team? " << a->name << " or " << b->name << "? ";
			string teamName;
			cin >> teamName;
			if (teamName.compare(a->name) == 0)
			{
				a->printHitter();
				cout << "Which player? ";
				string playerName;
				cin >> playerName;

				Player newPlayer;
				for (int i = 0; i < a->numOfHitter; i++)
				{
					if (a->startingPlayer[idx].getName().compare(a->hitter[i].getName()) == 0)
						a->hitter[i].setStatus(-1);

					if (playerName.compare(a->hitter[i].getName()) == 0)
					{
						newPlayer.setName(a->hitter[i].getName());
						newPlayer.setNumber(a->hitter[i].getNumber());
						newPlayer.setPosition(a->hitter[i].getPosition(true));
						newPlayer.setStatus(a->hitter[i].getStatus(true));
						a->hitter[i].setStatus(1);
					}
				}
				a->startingPlayer[idx].setName(newPlayer.getName());
				a->startingPlayer[idx].setNumber(newPlayer.getNumber());
				a->startingPlayer[idx].setPosition(newPlayer.getPosition(true));
				a->startingPlayer[idx].setStatus(newPlayer.getStatus(true));
				cout << "Hitter Name : " << a->startingPlayer[idx].getName() << endl;
			}
			else if (teamName.compare(b->name) == 0)
			{
				b->printPitcher();
				cout << "Which player? ";
				string playerName;
				cin >> playerName;

				Player newPlayer;
				for (int i = 0; i < b->numOfPitcher; i++)
				{
					if (b->startingPlayer[9].getName().compare(b->pitcher[i].getName()) == 0)
						b->pitcher[i].setStatus(-1);

					if (playerName.compare(b->pitcher[i].getName()) == 0)
					{
						newPlayer.setName(b->pitcher[i].getName());
						newPlayer.setNumber(b->pitcher[i].getNumber());
						newPlayer.setPosition(b->pitcher[i].getPosition(true));
						newPlayer.setStatus(b->pitcher[i].getStatus(true));
						b->pitcher[i].setStatus(1);
					}
				}
				b->startingPlayer[9].setName(newPlayer.getName());
				b->startingPlayer[9].setNumber(newPlayer.getNumber());
				b->startingPlayer[9].setPosition(newPlayer.getPosition(true));
				b->startingPlayer[9].setStatus(newPlayer.getStatus(true));
				cout << "Pitcher Name : " << b->startingPlayer[9].getName() << endl;
			}
		}

		hitter.push_back(a->startingPlayer[idx++].getName());
		ballCount.push_back(vector<char>());
		while (strike < 3 && ball < 4)
		{
			cout << "Current ball count : " << strike << "S " << ball << "B " << O << "O" << endl;
			char situation;
			cin >> situation;
			ballCount[cnt].push_back(situation);
			switch (situation)
			{
			case 'S': strike++; break;
			case 'B': ball++;	break;
			case 'F':
				if (strike < 2)
					strike++;
				break;
			case 'H':
				strike = 3;
				break;
			}
		}

		if (ball == 4)
		{
			hitterResult.push_back("BB");
			if (base[0] == 0 && base[1] == 0 && base[2] == 0)		// 林磊 X
			{
				base[0] = 1;
			}
			else if (base[0] == 1 && base[1] == 0 && base[2] == 0)		// 1风
			{
				base[0] = 1;
				base[1] = 1;
			}
			else if (base[0] == 1 && base[1] == 1 && base[2] == 0)		// 1,2风
			{
				base[0] = 1;
				base[1] = 1;
				base[2] = 1;
			}
			else if (base[0] == 1 && base[1] == 0 && base[2] == 1)		// 1,3风
			{
				base[0] = 1;
				base[1] = 1;
				base[2] = 1;
			}
			else if (base[0] == 0 && base[1] == 1 && base[2] == 1)		// 2,3风
			{
				base[0] = 1;
				base[1] = 1;
				base[2] = 1;
			}
			else if (base[0] == 1 && base[1] == 1 && base[2] == 1)		// 1,2,3风
			{
				base[0] = 1;
				R++;
			}
			B++;
		}
		else if (ballCount[cnt][ballCount[cnt].size() - 1] == 'H')
		{
			cout << "What is the result? ";
			string result;
			cin >> result;
			hitterResult.push_back(result);
			if (result.compare("FB") == 0 || result.compare("GB") == 0)
			{
				O++;
			}
			else if (result.compare("H1") == 0)
			{
				if (base[0] == 0 && base[1] == 0 && base[2] == 0)		// 林磊 X
				{
					base[0] = 1;
					H++;
				}
				else if (base[0] == 1 && base[1] == 0 && base[2] == 0)		// 1风
				{
					base[0] = 1;
					base[1] = 1;
					H++;
				}
				else if (base[0] == 1 && base[1] == 1 && base[2] == 0)		// 1,2风
				{
					base[0] = 1;
					base[1] = 1;
					base[2] = 1;
					H++;
				}
				else if (base[0] == 1 && base[1] == 0 && base[2] == 1)		// 1,3风
				{
					base[0] = 1;
					base[1] = 1;
					base[2] = 0;
					R++;
					H++;
				}
				else if (base[0] == 0 && base[1] == 1 && base[2] == 1)		// 2,3风
				{
					base[0] = 1;
					base[1] = 0;
					R++;
					H++;
				}
				else if (base[0] == 1 && base[1] == 1 && base[2] == 1)		// 1,2,3风
				{
					base[0] = 1;
					R++;
					H++;
				}
			}
			else if (result.compare("H2") == 0)
			{
				if (base[0] == 0 && base[1] == 0 && base[2] == 0)		// 林磊 X
				{
					base[1] = 1;
					H++;
				}
				else if (base[0] == 1 && base[1] == 0 && base[2] == 0)		// 1风
				{
					base[0] = 0;
					base[1] = 1;
					base[2] = 1;
					H++;
				}
				else if (base[0] == 1 && base[1] == 1 && base[2] == 0)		// 1,2风
				{
					base[0] = 0;
					base[1] = 1;
					base[2] = 1;
					R++;
					H++;
				}
				else if (base[0] == 1 && base[1] == 0 && base[2] == 1)		// 1,3风
				{
					base[0] = 0;
					base[1] = 1;
					base[2] = 1;
					R++;
					H++;
				}
				else if (base[0] == 0 && base[1] == 1 && base[2] == 1)		// 2,3风
				{
					base[0] = 0;
					base[1] = 0;
					base[2] = 0;
					R += 2;
					H++;
				}
				else if (base[0] == 1 && base[1] == 1 && base[2] == 1)		// 1,2,3风
				{
					base[0] = 0;
					base[1] = 1;
					base[2] = 1;
					R += 2;;
					H++;
				}
			}
			else if (result.compare("H3") == 0)
			{
				if (base[0] == 0 && base[1] == 0 && base[2] == 0)		// 林磊 X
				{
					base[2] = 1;
					H++;
				}
				else if (base[0] == 1 && base[1] == 0 && base[2] == 0)		// 1风
				{
					base[0] = 0;
					base[1] = 0;
					base[2] = 1;
					R++;
					H++;
				}
				else if (base[0] == 1 && base[1] == 1 && base[2] == 0)		// 1,2风
				{
					base[0] = 0;
					base[1] = 0;
					base[2] = 1;
					R += 2;
					H++;
				}
				else if (base[0] == 1 && base[1] == 0 && base[2] == 1)		// 1,3风
				{
					base[0] = 0;
					base[1] = 0;
					base[2] = 1;
					R += 2;
					H++;
				}
				else if (base[0] == 0 && base[1] == 1 && base[2] == 1)		// 2,3风
				{
					base[0] = 0;
					base[1] = 0;
					base[2] = 1;
					R += 2;
					H++;
				}
				else if (base[0] == 1 && base[1] == 1 && base[2] == 1)		// 1,2,3风
				{
					base[0] = 0;
					base[1] = 0;
					base[2] = 1;
					R += 3;
					H++;
				}
			}
			else if (result.compare("HR") == 0)
			{
				if (base[0] == 0 && base[1] == 0 && base[2] == 0)		// 林磊 X
				{
					base[0] = base[1] = base[2] = 0;
					R++;
					H++;
				}
				else if (base[0] == 1 && base[1] == 0 && base[2] == 0)		// 1风
				{
					base[0] = base[1] = base[2] = 0;
					R += 2;
					H++;
				}
				else if (base[0] == 1 && base[1] == 1 && base[2] == 0)		// 1,2风
				{
					base[0] = base[1] = base[2] = 0;
					R += 3;
					H++;
				}
				else if (base[0] == 1 && base[1] == 0 && base[2] == 1)		// 1,3风
				{
					base[0] = base[1] = base[2] = 0;
					R += 3;
					H++;
				}
				else if (base[0] == 0 && base[1] == 1 && base[2] == 1)		// 2,3风
				{
					base[0] = base[1] = base[2] = 0;
					R += 3;
					H++;
				}
				else if (base[0] == 1 && base[1] == 1 && base[2] == 1)		// 1,2,3风
				{
					base[0] = base[1] = base[2] = 0;
					R += 4;
					H++;
				}
			}
		}
		else if (strike == 3)
		{
			hitterResult.push_back("SO");
			O++;
		}
		cout << "result : " << hitterResult[hitterResult.size() - 1] << endl;;
		cnt++;
	}
	return idx;
}