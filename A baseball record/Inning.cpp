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

// A啊 傍拜评, B啊 荐厚评
// A啊 鸥磊, B啊 捧荐,荐厚
void Inning::inputHitterData(Team A, Team B)
{
	
	int cnt = 0;
	while (O < 3)
	{
		int strike = 0, ball = 0;
		cout << "Hitter Name : ";
		string name;
		cin >> name;
		hitter.push_back(name);
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
			if (result.compare("FB") == 0 || result.compare("GB") == 0)
			{
				hitterResult.push_back(result);
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
		cnt++;
	}
}