#pragma once
#include <string>
#include "Player.h"

using namespace std;

class Team
{
public:
	int H;	// 안타
	int B;	// 볼넷
	int E;	// 에러
	int R;	// 득점

public:
	Team(const string n);	// 생성자로 팀의 이름을 받는다

public:
	string name;	// 팀의 이름
	Player* player;	// 선수들
	Player startingPlayer[10];	// 현재 경기를 뛰고 있는 선수
	Player* pitcher;	//투수들
	Player* hitter;		//타자들
	int numOfPitcher;
	int numOfHitter;
	bool isRegister;	// 선발 라인업 등록 여부

public:
	void setStartingPlayer();
	void printStartingPlayer();
	void setPitcher();
	void setHitter();
	void printPitcher();
	void printHitter();
	void printAllPlayer();
	void swapPlayer(Player* A, Player* B);
	void reflectBoard(int h, int b, int e, int r);
};

