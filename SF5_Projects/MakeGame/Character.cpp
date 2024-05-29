#include "Character.h"

int Character::getHP() { return m_HP; }
int Character::getLevel() { return m_level; }

void Character::attack(int weapon)
{
	

}


//공격받아 HP가 깎이는 함수
void Character::setloseHP(int weapon) {
	// weapon : 0이면 몬스터 공격 1 이면 knife, weapon : 2 이면 gun
	if (weapon == 0)
	{
		if (this->m_HP - 5*m_level < 0)
		{

			this->m_HP = 0;
		}
		else
		{
			this->m_HP -= 5 * m_level;
		}

	}else if (weapon == 1)
	{
		knife.attack();
		if (this->m_HP - 15 * m_level < 0)
		{
			
			this->m_HP = 0;
		}
		else
		{
			this->m_HP -= 15 * m_level;
		}
	}
	else if (weapon == 2)
	{
		gun.attack();
		if (this->m_HP - 10 * m_level < 0)
		{
			this->m_HP = 0;
		}
		else
		{
			this->m_HP -= 10 * m_level;
		}
	}
}

void Player::setLevelUp()
{
	this->m_level++;
	this->m_max_HP += 10;
	this->m_HP = m_max_HP;
	cout << "level up! \n";
}

//EXP 획득함수 & exp가 100보다 클 시 levelup
void Player::setEXP(int monsterLevel) {
	this->m_EXP += monsterLevel * 100;
	if (this->m_EXP >= this->m_max_EXP) {
		setLevelUp();
		m_EXP = 0;
	}
	cout << "현재 경험치 : " << m_EXP << "\n";
}

int Player::getWeaponNum()
{
	return weapons.size();
}

void Player::getWeaponType()
{
	int num = 0;
	cout << "--------------------------------\n";
	cout << "현재 가지고 있는 무기\n";

	for (int i = 0; i < getWeaponNum(); i++)
	{
		if (weapons[i] == "knife") {
			cout << "칼\n";
			num++;
		}
		if (weapons[i] == "gun") {
			cout << "총\n";
			num++;
		}
	}
	if (num == 0)
	{
		cout << "가지고 있는 무기가 없습니다. \n";
	}
}

bool Player::isWeapon(int weapon)
{
	int num = 0;
	if (weapon == 1)
	{
		for (int i = 0; i < getWeaponNum(); i++)
		{
			if (weapons[i] == "knife") num++;
		}
	}
	else if (weapon == 2)
	{
		for (int i = 0; i < getWeaponNum(); i++)
		{
			if (weapons[i] == "gun") num++;
		}
	}
	if (num == 1)
		return true;
	else
	{
		cout << "무기가 없습니다. \n";
		return false;
	}
}



void Player::showCharacterInfo()
{
	cout << "캐릭터의 정보 \n";
	cout << "--------------------------------\n";
	cout << "레벨 : " << this->m_level << "\n";
	cout << "현재 체력 : " << this-> m_HP << "\n";
	getWeaponType();
}


void Player::setWeapon(int weapon)
{
	bool findWeapon = false;

	if (weapon == 1) {
		for (int i = 0; i < weapons.size(); i++)
		{
			if (weapons[i] == "knife")
			{
				findWeapon = true;
				cout << "이미 존재하는 무기입니다. \n";
			}
		}
		if (findWeapon == false)
		{
			weapons.push_back("knife");
			cout << "칼을 주웠습니다.\n";
		}
	}
	else if (weapon == 2)
	{
		for (int i = 0; i < weapons.size(); i++)
		{
			if (weapons[i] == "gun")
			{
				findWeapon = true;
				cout << "이미 존재하는 무기입니다. \n";
			}
		}
		if (findWeapon == false)
		{
			weapons.push_back("gun");
			cout << "총을 주웠습니다. \n";
		}
	}

}

void Monster::setLevel(int level)
{
	this->m_level = level;
	this->m_max_HP = 50 + 50 * level;
	this->m_HP = 50 + 50 * level;

}