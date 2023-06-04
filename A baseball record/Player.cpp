#include "Player.h"
#include <iostream>

using namespace std;

// 해당 클래스는 모든 함수가 getter, setter 뿐이다.

Player::Player()
{
	number = -1;
	name = "";
	position = -1;
	status = 0;
}

string Player::getName()
{
	return name;
}

int Player::getNumber()
{
	return number;
}

void Player::setName(string n)
{
	name = n;
}

void Player::setNumber(int n)
{
	number = n;
}

string Player::getPosition()
{
	switch (position)
	{
	case 0: return "DH";
	case 1: return "P";
	case 2: return "C";
	case 3: return "1B";
	case 4: return "2B";
	case 5: return "3B";
	case 6: return "SS";
	case 7: return "LF";
	case 8: return "CF";
	case 9: return "RF";
	case 10: return "IF";
	case 11: return "OF";
	}
}

void Player::setPosition(int p)
{
	position = p;
}

void Player::setStatus(int n)
{
	status = n;
}

string Player::getStatus()
{
	switch (status)
	{
	case -1: return "Not available";
	case 0: return "Available";
	case 1: return "Playing";
	}
}

int Player::getPosition(bool flag)
{
	return position;
}
int Player::getStatus(bool flag)
{
	return status;
}