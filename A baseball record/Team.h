#pragma once
#include <string>
#include "Player.h"

using namespace std;

class Team
{
public:
	int H;	// ��Ÿ
	int B;	// ����
	int E;	// ����
	int R;	// ����

public:
	Team(const string n);	// �����ڷ� ���� �̸��� �޴´�

public:
	string name;	// ���� �̸�
	Player* player;	// ������
	Player startingPlayer[10];	// ���� ��⸦ �ٰ� �ִ� ����
	Player* pitcher;	//������
	Player* hitter;		//Ÿ�ڵ�
	int numOfPitcher;
	int numOfHitter;
	bool isRegister;	// ���� ���ξ� ��� ����

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

