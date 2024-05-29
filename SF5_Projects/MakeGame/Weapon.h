#pragma once

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

class Weapon {
protected:
	int attackPower;
	int attackNum;

public:
	virtual void attack() = 0;
};

class Knife : public Weapon
{
	int attackPower = 5;
	int attackNum = 3;
public:
	void attack() {
		cout << "Âî¸£±â\n";
	}
};

class Gun : public Weapon
{
	int attackPower = 10;
	int attackNum = 1;
public:
	void attack() {
		cout << "ÃÑ½î±â\n";
	}
};