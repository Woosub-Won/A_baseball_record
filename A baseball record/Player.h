#pragma once
#include <string>

using namespace std;

class Player
{
public:
	Player();

public:
	int number;
	string name;
	int position;
	int status;	// 0 : ���, 1 : �����, -1 : ��ü �ƿ�

public:
	int getNumber();
	string getName();
	void setNumber(int n);
	void setName(string n);
	string getPosition();
	
	void setPosition(int p);
	void setStatus(int n);
	
	string getStatus();

	int getPosition(bool flag);
	int getStatus(bool flag);
};