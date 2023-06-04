#pragma once

#include "Team.h"
#include <vector>
#include <string>
using namespace std;

class Inning
{
public:
	int H;	// ��Ÿ
	int B;	// ����
	int E;	// ����
	int R;	// ����
	int O;	// �ƿ�
	int base[4];	// ���� ���� ��Ȳ

public:
	vector<vector<char>> ballCount;	// strike, ball�� ����
	vector<string> hitter;	// Ÿ���� �̸��� ����
	vector<string> hitterResult;	// Ÿ�� ����� ����

public:
	Inning();


	int inputHitterData(Team* a, Team* b, int n, int inning, bool top = true);		// ���ڷ� ������ ���
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