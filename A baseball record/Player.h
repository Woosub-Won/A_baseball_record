#pragma once
#include <string>

using namespace std;

class Player
{
public:
	Player();	//생성자

public:
	int number;		// 등번호
	string name;	// 선수 이름
	int position;	// 선수 포지션
	int status;	// 0 : 대기, 1 : 경기중, -1 : 교체 아웃

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