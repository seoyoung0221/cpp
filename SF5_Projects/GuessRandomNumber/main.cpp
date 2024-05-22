//랜덤 숫자 맞추기

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int inputRandomNum(vector<int> vec);
int inputUserNum(vector<int> vec);
bool checkNum(string str);

int main()
{
	srand(time(NULL));
	vector<int> randomNums;
	vector<int> userNums;
	int num;
	int cnt = 0; // 같은 숫자의 개수
	//첫번째 랜덤 숫자 받기
	num = rand() % 25 + 1;
	randomNums.push_back(num);

	cout << "숫자는 1 ~ 25까지의 숫자만 입력할 수 있습니다. \n";

	//랜덤 숫자 받기 
	for (int i = 1; i < 6; i++)
	{
		num = inputRandomNum(randomNums);
		randomNums.push_back(num);
	}

	//사용자의 입력 받기
	for (int i = 0; i < 6; i++)
	{
		num = inputUserNum(userNums);
		userNums.push_back(num);
	}

	//두 배열 비교해서 몇 등인지 출력하기
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (randomNums[i] == userNums[j])
			{
				cnt++;
			}
		}
	}
	
	cout << "----------------------------------";
	cout << "당첨번호 공개!\n";
	for (int i = 0; i < 6; i++)
	{
		cout << randomNums[i] << " ";
	}

	cout << "\n 1 ~ 7등까지 결과가 나올 수 있습니다. \n";

	switch (cnt)
	{
	case 0 :
		cout << "7등입니다!";
		break;
	case 1:
		cout << "6등입니다!";
		break;
	case 2:
		cout << "5등입니다!";
		break;
	case 3:
		cout << "4등입니다!";
		break;
	case 4:
		cout << "3등입니다!";
		break;
	case 5:
		cout << "2등입니다!";
		break;
	case 6:
		cout << "1등입니다!";
		break;
	default:
		break;
	}
}

int inputRandomNum(vector<int> vec){
	srand(time(NULL)); 
	int num;
	int size = vec.size();
	bool sameNum = true;

	while (sameNum)
	{
		num = rand() % 25 + 1;
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

int inputUserNum(vector<int> vec)
{
	int num;
	int size = vec.size();
	string str;
	bool sameNum = true;

	if (vec.size() == 0) {
		while (true)
		{
			cout << "1번째 숫자를 입력하세요 : \n";
			cin >> str;
			if (checkNum(str) == true)
			{
				break;
			}
		}
		num = stoi(str);
	}
	else
	{
		while (sameNum) 
		{
			cout << size+1 << "번째 숫자를 입력하세요 : \n";
			cin >> str;
			if (checkNum(str) == true)
			{
				num = stoi(str);
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
		}
	}

	return num;
}

// 1~25사이 숫자면 true 반환
bool checkNum(string str)
{
	// 숫자인지 확인
	for (char& c : str)
	{
		// 0 : 숫자x
		if (isdigit(c) == 0)
		{
			return false;
		}
	}

	if (stoi(str) > 25)
	{
		return false;
	}

	return true;
}

bool checkRepetition(vector<string> words, string word)
{
	int size = words.size(); // 몇 개의 단어가 저장되어 있는지 확인

	for (int i = 0; i < size; i++)
	{
		if (words[i] == word) {
			return true;
		}
	}
	return false;
}