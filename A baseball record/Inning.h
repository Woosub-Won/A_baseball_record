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
<<<<<<< HEAD
	int inputHitterData(Team* a, Team* b, int n);		// ���ڷ� ������ ���
=======
	int inputHitterData(Team* a, Team* b, int n);
>>>>>>> 7d9cb8fdec15386c0cc232801107c6a3e43ec1e1
=======
	int inputHitterData(Team* a, Team* b, int n);		// ���ڷ� ������ ���
>>>>>>> feature2
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