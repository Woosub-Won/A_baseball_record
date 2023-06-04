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

// 인자로 a,b팀과, 몇번 타자부터 시작할지, 현재 이닝과, 초,말 여부를 입력받는다.
int Inning::inputHitterData(Team* a, Team* b, int n, int inning, bool top)	// 인자로 포인터 사용
{
	int cnt = 0;
	int idx = n;

	// out이 3개가 되면 이닝교대 조건
	while (O < 3)
	{
		if (idx > 8)
			idx = 0;
		int strike = 0, ball = 0;
		cout << a->startingPlayer[idx].getName() << "[" << a->name << "]" << " vs " << "[" << b->name << "]" << b->startingPlayer[9].getName() << endl;

		char option;
		cout << "Do you want to change player? [Y/N] ";
		cin >> option;

		// 선수 교체 옵션
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
			else
			{
				cout << "Invalid Input" << endl;
				continue;
			}
		}
		else if (option == 'N')
		{
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
				default:
					cout << "Invalid Input" << endl;
					continue;
				}
			}

			// ball이 4개면 볼넷으로 1루로 걸어나간다.
			// 안에 조건문은 현재 베이스 상황에 따른 처리를 해주었다.
			if (ball == 4)
			{
				hitterResult.push_back("BB");
				if (base[0] == 0 && base[1] == 0 && base[2] == 0)		// 주자 X
				{
					base[0] = 1;
				}
				else if (base[0] == 1 && base[1] == 0 && base[2] == 0)		// 1루
				{
					base[0] = 1;
					base[1] = 1;
				}
				else if (base[0] == 1 && base[1] == 1 && base[2] == 0)		// 1,2루
				{
					base[0] = 1;
					base[1] = 1;
					base[2] = 1;
				}
				else if (base[0] == 1 && base[1] == 0 && base[2] == 1)		// 1,3루
				{
					base[0] = 1;
					base[1] = 1;
					base[2] = 1;
				}
				else if (base[0] == 0 && base[1] == 1 && base[2] == 1)		// 2,3루
				{
					base[0] = 1;
					base[1] = 1;
					base[2] = 1;
				}
				else if (base[0] == 1 && base[1] == 1 && base[2] == 1)		// 1,2,3루
				{
					base[0] = 1;
					R++;
				}
				B++;
			}
			else if (ballCount[cnt][ballCount[cnt].size() - 1] == 'H')	// 타자가 친 공이 배트에 맞고 나간경우
			{
				cout << "What is the result? ";
				string result;
				cin >> result;

				// 잘못 입력된 경우 다시 입력
				while (result.compare("E") != 0 && result.compare("FB") != 0 && result.compare("GB") != 0 &&
					result.compare("H1") != 0 && result.compare("H2") != 0 && result.compare("H3") != 0 && result.compare("HR") != 0)
				{
					cout << "Invalid Input" << endl;
					cout << "What is the result? ";
					cin >> result;
				}

				hitterResult.push_back(result);
				if (result.compare("E") == 0)
				{
					if (base[0] == 0 && base[1] == 0 && base[2] == 0)		// 주자 X
					{
						base[0] = 1;
					}
					else if (base[0] == 1 && base[1] == 0 && base[2] == 0)		// 1루
					{
						base[0] = 1;
						base[1] = 1;
					}
					else if (base[0] == 1 && base[1] == 1 && base[2] == 0)		// 1,2루
					{
						base[0] = 1;
						base[1] = 1;
						base[2] = 1;
					}
					else if (base[0] == 1 && base[1] == 0 && base[2] == 1)		// 1,3루
					{
						base[0] = 1;
						base[1] = 1;
						base[2] = 0;
						R++;
					}
					else if (base[0] == 0 && base[1] == 1 && base[2] == 1)		// 2,3루
					{
						base[0] = 1;
						base[1] = 0;
						R++;
					}
					else if (base[0] == 1 && base[1] == 1 && base[2] == 1)		// 1,2,3루
					{
						base[0] = 1;
						R++;
					}
					E++;
				}
				if (result.compare("FB") == 0 || result.compare("GB") == 0)
				{
					O++;
				}
				else if (result.compare("H1") == 0)
				{
					if (base[0] == 0 && base[1] == 0 && base[2] == 0)		// 주자 X
					{
						base[0] = 1;
					}
					else if (base[0] == 1 && base[1] == 0 && base[2] == 0)		// 1루
					{
						base[0] = 1;
						base[1] = 1;
					}
					else if (base[0] == 1 && base[1] == 1 && base[2] == 0)		// 1,2루
					{
						base[0] = 1;
						base[1] = 1;
						base[2] = 1;
					}
					else if (base[0] == 1 && base[1] == 0 && base[2] == 1)		// 1,3루
					{
						base[0] = 1;
						base[1] = 1;
						base[2] = 0;
						R++;
					}
					else if (base[0] == 0 && base[1] == 1 && base[2] == 1)		// 2,3루
					{
						base[0] = 1;
						base[1] = 0;
						R++;
					}
					else if (base[0] == 1 && base[1] == 1 && base[2] == 1)		// 1,2,3루
					{
						base[0] = 1;
						R++;
					}
					H++;
				}
				else if (result.compare("H2") == 0)
				{
					if (base[0] == 0 && base[1] == 0 && base[2] == 0)		// 주자 X
					{
						base[1] = 1;
					}
					else if (base[0] == 1 && base[1] == 0 && base[2] == 0)		// 1루
					{
						base[0] = 0;
						base[1] = 1;
						base[2] = 1;
					}
					else if (base[0] == 1 && base[1] == 1 && base[2] == 0)		// 1,2루
					{
						base[0] = 0;
						base[1] = 1;
						base[2] = 1;
						R++;
					}
					else if (base[0] == 1 && base[1] == 0 && base[2] == 1)		// 1,3루
					{
						base[0] = 0;
						base[1] = 1;
						base[2] = 1;
						R++;
					}
					else if (base[0] == 0 && base[1] == 1 && base[2] == 1)		// 2,3루
					{
						base[0] = 0;
						base[1] = 0;
						base[2] = 0;
						R += 2;
					}
					else if (base[0] == 1 && base[1] == 1 && base[2] == 1)		// 1,2,3루
					{
						base[0] = 0;
						base[1] = 1;
						base[2] = 1;
						R += 2;
					}
					H++;
				}
				else if (result.compare("H3") == 0)
				{
					if (base[0] == 0 && base[1] == 0 && base[2] == 0)		// 주자 X
					{
						base[2] = 1;
					}
					else if (base[0] == 1 && base[1] == 0 && base[2] == 0)		// 1루
					{
						base[0] = 0;
						base[1] = 0;
						base[2] = 1;
						R++;
					}
					else if (base[0] == 1 && base[1] == 1 && base[2] == 0)		// 1,2루
					{
						base[0] = 0;
						base[1] = 0;
						base[2] = 1;
						R += 2;
					}
					else if (base[0] == 1 && base[1] == 0 && base[2] == 1)		// 1,3루
					{
						base[0] = 0;
						base[1] = 0;
						base[2] = 1;
						R += 2;
					}
					else if (base[0] == 0 && base[1] == 1 && base[2] == 1)		// 2,3루
					{
						base[0] = 0;
						base[1] = 0;
						base[2] = 1;
						R += 2;
					}
					else if (base[0] == 1 && base[1] == 1 && base[2] == 1)		// 1,2,3루
					{
						base[0] = 0;
						base[1] = 0;
						base[2] = 1;
						R += 3;
					}
					H++;
				}
				else if (result.compare("HR") == 0)
				{
					if (base[0] == 0 && base[1] == 0 && base[2] == 0)		// 주자 X
					{
						base[0] = base[1] = base[2] = 0;
						R++;
					}
					else if (base[0] == 1 && base[1] == 0 && base[2] == 0)		// 1루
					{
						base[0] = base[1] = base[2] = 0;
						R += 2;
					}
					else if (base[0] == 1 && base[1] == 1 && base[2] == 0)		// 1,2루
					{
						base[0] = base[1] = base[2] = 0;
						R += 3;
					}
					else if (base[0] == 1 && base[1] == 0 && base[2] == 1)		// 1,3루
					{
						base[0] = base[1] = base[2] = 0;
						R += 3;
					}
					else if (base[0] == 0 && base[1] == 1 && base[2] == 1)		// 2,3루
					{
						base[0] = base[1] = base[2] = 0;
						R += 3;
					}
					else if (base[0] == 1 && base[1] == 1 && base[2] == 1)		// 1,2,3루
					{
						base[0] = base[1] = base[2] = 0;
						R += 4;
					}
					H++;
				}
			}
			else if (strike == 3)
			{
				hitterResult.push_back("SO");
				O++;
			}
			cout << "result : " << hitterResult[hitterResult.size() - 1] << endl;;
			cnt++;

			// 이닝이 9회가 이상이고, 홈팀이 공격중일 때, 점수가 나서 역전이 되면 끝내기 안타의 조건이므로
			// 경기를 곧장 종료시킨다.
			if (inning >= 9 && top == false)
			{
				if (a->R + R > b->R)
					return idx;
			}
		}
	}
	return idx;
}