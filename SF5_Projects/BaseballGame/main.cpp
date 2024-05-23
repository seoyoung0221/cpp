//�߱� ����

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int inputRandomNum(vector<int> vec);
int checkNum(string str);

int main()
{
	srand(time(NULL));

	int cnt = 0;
	int num;
	int strike = 0;
	int ball = 0;
	vector<string> str(3);
	vector<int> randomNums;
	vector<int> inputNums(3);

	//���� ���� �ޱ� 
	for (int i = 0; i < 3; i++)
	{
		num = inputRandomNum(randomNums);
		randomNums.push_back(num);
	}

	cout << "�߱� ���� \n";

	while (true)
	{
		strike = 0;
		ball = 0;
		cout << "1 ~ 9 ������ ���� 3���� �Է� �Ͻÿ�. (�̿��� ����: ����) \n";
		cin >> str[0] >> str[1] >> str[2];

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (randomNums[i] == inputNums[j])
				{
					if (i == j)
					{
						strike++;
					}
					else
					{
						ball++;
					}

				}
			}
		}

		cout << "Strike : " << strike << "\tBall : " << ball << "\n";
		cnt++;

		if (strike == 3)
		{
			cout << cnt << "�� ���� ������ϴ�. \n";
			break;
		}
	}



	return 0;
}

int inputRandomNum(vector<int> vec) {
	srand(time(NULL));
	int num;
	int size = vec.size();
	bool sameNum = true;

	while (sameNum)
	{
		num = rand() % 9 + 1;
		if (size == 0)
		{
			break;
		}
		for (int i = 0; i < size; i++)
		{
			if (vec[i] != num)
			{
				sameNum = false;
			}
			else if (vec[i] == num)
			{
				sameNum = true;
				break;
			}
		}
	}

	return num;

}

vector<int> inputNums() {
	vector<string> str(3);
	vector<int> nums(3);
	int mode;

	while (true)
	{
		cout << "1 ~ 9 ������ ���� 3���� �Է� �Ͻÿ�. (�̿��� ����: ����) \n";
		cin >> str[0] >> str[1] >> str[2];
		
	}

}
//return 0 > 1~9 ������ ����
//return 1 > 1~9 �̿��� ����
//return 2 > ���� x
int checkNum(string str)
{
	// �������� Ȯ��
	for (char& c : str)
	{
		// 0 : ����x
		if (isdigit(c) == 0)
		{
			return 2;
		}
	}

	if (stoi(str) >= 1 && stoi(str) <= 9)
	{
		return 0;
	}

	return 1;
}


