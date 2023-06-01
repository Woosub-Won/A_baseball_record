#pragma once

#include <vector>
#include <string>
using namespace std;

class Inning
{
public:
	int H;
	int B;
	int E;
	int R;
	int O;
	int base[4];

public:
	vector<vector<char>> ballCount;
	vector<string> hitter;
	vector<string> hitterResult;

public:
	Inning();

	void inputHitterData(Team A);
	// 2차원 배열로 ballCount를 저장
	// 1번 ssbbs
	// 2번 sbbh
	// 3번 bbbb
	// 4번 h

	// 1차원 배열로 hitterResult를 저장
	// SO
	// H1
	// BB
	// H2

};