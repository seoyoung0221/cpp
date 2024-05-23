//야구 게임

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

	//랜덤 숫자 받기 
	for (int i = 0; i < 3; i++)
	{
		num = inputRandomNum(randomNums);
		randomNums.push_back(num);
	}

	cout << "야구 게임 \n";

	while (true)
	{
		strike = 0;
		ball = 0;
		input3Nums = inputNums();
		
		if (input3Nums[0] == 0)
		{
			cout << "게임이 종료되었습니다.\n";
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
			cout << cnt << "번 만에 맞췄습니다. \n";
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
	int mode = 0; // 입력 받은게 문자면 0, 1~9 사이 숫자면 1, 그 외 숫자면 2

	while (mode == 0)
	{
		cout << "1 ~ 9 사이의 숫자 3개를 입력 하시오. (이외의 숫자: 종료) \n";
		cin >> str[0] >> str[1] >> str[2];
		if (checkNum(str) == false)
		{
			"숫자를 입력해주세요. \n";
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

// 숫자를 확인하는 함수
bool checkNum(vector<string> str)
{
	for (int i = 0; i < 3; i++)
	{
		// 숫자인지 확인
		for (char& c : str[i])
		{
			// 0 : 숫자x
			if (isdigit(c) == 0)
			{
				return false;
			}
		}
	}

	return true;
}



