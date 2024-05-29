//���� �����

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Character.h"
#include "Weapon.h"

using namespace std;

int InputOption();
bool findNumber(string str);

int main() {
	int option = -1;
	int weaponOption;
	Player player;

	while (option != 0)
	{
		option = InputOption();
		weaponOption = 0;
		Monster monster;
		switch (option)
		{
		case 1:
			player.showCharacterInfo();
			break;
		case 2:
			cout << "�ֿ� ���⸦ �����ϼ���. \n";
			cout << "1 : Į, 2 : �� ";
			cin >> weaponOption;
			player.setWeapon(weaponOption);
			break;
		case 3:
			cout << "���Ϳ� �ο�ϴ�. \n";
			cout << "������ ���� : " << monster.getLevel() << "\n";
			cout << "������ ü�� : " << monster.getHP() << "\n";

			while (monster.getHP() != 0 && player.getHP() != 0)
			{
				cout << "���͸� �����մϴ�. \n\n";
				if (player.getWeaponNum() == 0)
				{
					cout << "������ ���Ⱑ ���� ����Ĩ�ϴ�. \n";
					break;
				}
				
				cout << "������ ���⸦ �����ϼ���. \n";
				cout << "1 : Į, 2 : �� ";
				cin >> weaponOption;
				if (player.isWeapon(weaponOption) == false)
				{
					cout << "���Ⱑ ���� ����Ĩ�ϴ�. \n";
					break;
				}

				cout << "������ ü�� : " << monster.getHP() << "\n";
				monster.setloseHP(weaponOption);
				cout << "������ ü�� : " << monster.getHP() << "\n\n";

				if (monster.getHP() == 0) {
					break;
				}

				cout << "�÷��̾ �����մϴ�. \n\n";
				cout << "�÷��̾��� ü�� : " << player.getHP() << "->" ;
				player.setloseHP(0);
				cout << player.getHP() << "\n\n";
			}

			if (monster.getHP() == 0)
			{
				cout << "���͸� �̰���ϴ�. \n";
				player.setEXP(monster.getLevel());
			}
			else if (player.getHP() == 0)
			{
				cout << "���Ϳ��� �����ϴ�. \n";
				cout << "���α׷��� ����Ǿ����ϴ�. \n";
				option = 0;
			}
			break;

		case 0:
			cout << "������ �����մϴ�. \n";
			break;
		}
	}
	return 0;
}

int InputOption()
{
	string option;
	while (true)
	{
		cout << "���ϴ� �޴��� �����ϼ���.\n";
		cout << "--------------------------------\n";
		cout << "1. ���� ���� ��� 2. ���� �ݱ� 3. ���Ϳ� �ο�� 0. ���� ���� ";
		cin >> option;

		bool checkOptionLength = false;
		if (option.length() == 1)
			checkOptionLength = true;

		bool checkOptionInt = false;
		bool checkOptionSize = false;

		if (findNumber(option))
		{
			checkOptionInt = true;

			if (stoi(option) <= 4 && stoi(option) >= 0)
				checkOptionSize = true;
		}

		if (checkOptionLength && checkOptionSize && checkOptionSize)
			break;
		else
			cout << "�߸��� �Է��Դϴ�. \n";
	}
	return stoi(option);
}

bool findNumber(string str)
{

	for (char& c : str)
	{
		// ���ڸ� 0�� �ƴ�
		// ������ �� true ����
		if (isdigit(c) != 0)
		{
			return true;
		}
	}

	return false;
}