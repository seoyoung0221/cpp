#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Weapon.h"

using namespace std;

class Character
{
	Knife knife;
	Gun gun;

protected :
	int m_HP = 50;
	int m_max_HP = 50;
	int m_level = 1;

public :
	int getHP(); 
	int getLevel();
	void setloseHP(int power);
	void attack(int weapon);
};

class Player : public Character
{
	int m_EXP = 0;
	int m_max_EXP = 100;
	vector<string> weapons;

public: 
	int getWeaponNum();
	void getWeaponType();
	bool isWeapon(int weapon);
	void setWeapon(int weapon);
	void setLevelUp();
	void setEXP(int monsterLevel);
	void showCharacterInfo();
	
};

class Monster : public Character
{
	void setLevel(int level);
};