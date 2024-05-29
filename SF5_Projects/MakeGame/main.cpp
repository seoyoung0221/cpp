//게임 만들기

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
			cout << "주울 무기를 선택하세요. \n";
			cout << "1 : 칼, 2 : 총 ";
			cin >> weaponOption;
			player.setWeapon(weaponOption);
			break;
		case 3:
			cout << "몬스터와 싸웁니다. \n";
			cout << "몬스터의 레벨 : " << monster.getLevel() << "\n";
			cout << "몬스터의 체력 : " << monster.getHP() << "\n";

			while (monster.getHP() != 0 && player.getHP() != 0)
			{
				cout << "몬스터를 공격합니다. \n\n";
				if (player.getWeaponNum() == 0)
				{
					cout << "공격할 무기가 없어 도망칩니다. \n";
					break;
				}
				
				cout << "공격할 무기를 선택하세요. \n";
				cout << "1 : 칼, 2 : 총 ";
				cin >> weaponOption;
				if (player.isWeapon(weaponOption) == false)
				{
					cout << "무기가 없어 도망칩니다. \n";
					break;
				}

				cout << "몬스터의 체력 : " << monster.getHP() << "\n";
				monster.setloseHP(weaponOption);
				cout << "몬스터의 체력 : " << monster.getHP() << "\n\n";

				if (monster.getHP() == 0) {
					break;
				}

				cout << "플레이어를 공격합니다. \n\n";
				cout << "플레이어의 체력 : " << player.getHP() << "->" ;
				player.setloseHP(0);
				cout << player.getHP() << "\n\n";
			}

			if (monster.getHP() == 0)
			{
				cout << "몬스터를 이겼습니다. \n";
				player.setEXP(monster.getLevel());
			}
			else if (player.getHP() == 0)
			{
				cout << "몬스터에게 졌습니다. \n";
				cout << "프로그램이 종료되었습니다. \n";
				option = 0;
			}
			break;

		case 0:
			cout << "게임을 종료합니다. \n";
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
		cout << "원하는 메뉴를 선택하세요.\n";
		cout << "--------------------------------\n";
		cout << "1. 현재 상태 출력 2. 무기 줍기 3. 몬스터와 싸우기 0. 게임 종료 ";
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
			cout << "잘못된 입력입니다. \n";
	}
	return stoi(option);
}

bool findNumber(string str)
{

	for (char& c : str)
	{
		// 숫자면 0이 아님
		// 숫자일 때 true 리턴
		if (isdigit(c) != 0)
		{
			return true;
		}
	}

	return false;
}