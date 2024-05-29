#include "Character.h"

int Character::getHP() { return m_HP; }
int Character::getLevel() { return m_level; }

void Character::attack(int weapon)
{
	

}


//���ݹ޾� HP�� ���̴� �Լ�
void Character::setloseHP(int weapon) {
	// weapon : 0�̸� ���� ���� 1 �̸� knife, weapon : 2 �̸� gun
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

//EXP ȹ���Լ� & exp�� 100���� Ŭ �� levelup
void Player::setEXP(int monsterLevel) {
	this->m_EXP += monsterLevel * 100;
	if (this->m_EXP >= this->m_max_EXP) {
		setLevelUp();
		m_EXP = 0;
	}
	cout << "���� ����ġ : " << m_EXP << "\n";
}

int Player::getWeaponNum()
{
	return weapons.size();
}

void Player::getWeaponType()
{
	int num = 0;
	cout << "--------------------------------\n";
	cout << "���� ������ �ִ� ����\n";

	for (int i = 0; i < getWeaponNum(); i++)
	{
		if (weapons[i] == "knife") {
			cout << "Į\n";
			num++;
		}
		if (weapons[i] == "gun") {
			cout << "��\n";
			num++;
		}
	}
	if (num == 0)
	{
		cout << "������ �ִ� ���Ⱑ �����ϴ�. \n";
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
		cout << "���Ⱑ �����ϴ�. \n";
		return false;
	}
}



void Player::showCharacterInfo()
{
	cout << "ĳ������ ���� \n";
	cout << "--------------------------------\n";
	cout << "���� : " << this->m_level << "\n";
	cout << "���� ü�� : " << this-> m_HP << "\n";
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
				cout << "�̹� �����ϴ� �����Դϴ�. \n";
			}
		}
		if (findWeapon == false)
		{
			weapons.push_back("knife");
			cout << "Į�� �ֿ����ϴ�.\n";
		}
	}
	else if (weapon == 2)
	{
		for (int i = 0; i < weapons.size(); i++)
		{
			if (weapons[i] == "gun")
			{
				findWeapon = true;
				cout << "�̹� �����ϴ� �����Դϴ�. \n";
			}
		}
		if (findWeapon == false)
		{
			weapons.push_back("gun");
			cout << "���� �ֿ����ϴ�. \n";
		}
	}

}

void Monster::setLevel(int level)
{
	this->m_level = level;
	this->m_max_HP = 50 + 50 * level;
	this->m_HP = 50 + 50 * level;

}