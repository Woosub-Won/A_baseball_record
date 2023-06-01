#pragma once

#include <vector>
#include <string>
using namespace std;

class Inning
{
private:
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

	void inputHitterData();
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