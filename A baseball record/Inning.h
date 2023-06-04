#pragma once

#include "Team.h"
#include <vector>
#include <string>
using namespace std;

class Inning
{
public:
	int H;	// 안타
	int B;	// 볼넷
	int E;	// 에러
	int R;	// 득점
	int O;	// 아웃
	int base[4];	// 현재 주자 상황

public:
	vector<vector<char>> ballCount;	// strike, ball을 저장
	vector<string> hitter;	// 타자의 이름을 저장
	vector<string> hitterResult;	// 타격 결과를 저장

public:
	Inning();


	int inputHitterData(Team* a, Team* b, int n, int inning, bool top = true);		// 인자로 포인터 사용
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