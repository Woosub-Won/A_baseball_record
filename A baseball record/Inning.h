#pragma once

#include "Team.h"
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

<<<<<<< HEAD
	int inputHitterData(Team a, Team b, int n);
=======

	int inputHitterData(Team* a, Team* b, int n);		// ���ڷ� ������ ���
>>>>>>> c7e6833 (Now can change pitcher too)
	// 2���� �迭�� ballCount�� ����
	// 1�� ssbbs
	// 2�� sbbh
	// 3�� bbbb
	// 4�� h

	// 1���� �迭�� hitterResult�� ����
	// SO
	// H1
	// BB
	// H2

};