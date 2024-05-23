//�߱� ����

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int inputRandomNum(vector<int> vec);
vector<int> inputNums();
bool checkNum(vector<string> str);

int main()
{
	srand(time(NULL));

	int cnt = 0;
	int num;
	int strike = 0;
	int ball = 0;
	vector<string> str(3);
	vector<int> randomNums;
	vector<int> input3Nums(3);

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
		input3Nums = inputNums();
		
		if (input3Nums[0] == 0)
		{
			cout << "������ ����Ǿ����ϴ�.\n";
			break;
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (randomNums[i] == input3Nums[j])
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
	int mode = 0; // �Է� ������ ���ڸ� 0, 1~9 ���� ���ڸ� 1, �� �� ���ڸ� 2

	while (mode == 0)
	{
		cout << "1 ~ 9 ������ ���� 3���� �Է� �Ͻÿ�. (�̿��� ����: ����) \n";
		cin >> str[0] >> str[1] >> str[2];
		if (checkNum(str) == false)
		{
			"���ڸ� �Է����ּ���. \n";
		}
		else
		{
			for (int i = 0; i < 3; i++)
			{
				nums[i] = stoi(str[i]);
				if (nums[i] > 9)
				{
					mode = 2;
					break;
				}
				else {
					mode = 1;
				}
			}

		}

		if (mode == 2)
		{
			for (int i = 0; i < 3; i++)
			{
				nums[i] = 0;
			}
		}

	}
	return nums;
}

// ���ڸ� Ȯ���ϴ� �Լ�
bool checkNum(vector<string> str)
{
	for (int i = 0; i < 3; i++)
	{
		// �������� Ȯ��
		for (char& c : str[i])
		{
			// 0 : ����x
			if (isdigit(c) == 0)
			{
				return false;
			}
		}
	}

	return true;
}



