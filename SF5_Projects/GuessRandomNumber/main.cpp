//���� ���� ���߱�

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
	int cnt = 0; // ���� ������ ����
	//ù��° ���� ���� �ޱ�
	num = rand() % 25 + 1;
	randomNums.push_back(num);

	cout << "���ڴ� 1 ~ 25������ ���ڸ� �Է��� �� �ֽ��ϴ�. \n";

	//���� ���� �ޱ� 
	for (int i = 1; i < 6; i++)
	{
		num = inputRandomNum(randomNums);
		randomNums.push_back(num);
	}

	//������� �Է� �ޱ�
	for (int i = 0; i < 6; i++)
	{
		num = inputUserNum(userNums);
		userNums.push_back(num);
	}

	//�� �迭 ���ؼ� �� ������ ����ϱ�
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
	cout << "��÷��ȣ ����!\n";
	for (int i = 0; i < 6; i++)
	{
		cout << randomNums[i] << " ";
	}

	cout << "\n 1 ~ 7����� ����� ���� �� �ֽ��ϴ�. \n";

	switch (cnt)
	{
	case 0 :
		cout << "7���Դϴ�!";
		break;
	case 1:
		cout << "6���Դϴ�!";
		break;
	case 2:
		cout << "5���Դϴ�!";
		break;
	case 3:
		cout << "4���Դϴ�!";
		break;
	case 4:
		cout << "3���Դϴ�!";
		break;
	case 5:
		cout << "2���Դϴ�!";
		break;
	case 6:
		cout << "1���Դϴ�!";
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
			cout << "1��° ���ڸ� �Է��ϼ��� : \n";
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
			cout << size+1 << "��° ���ڸ� �Է��ϼ��� : \n";
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

// 1~25���� ���ڸ� true ��ȯ
bool checkNum(string str)
{
	// �������� Ȯ��
	for (char& c : str)
	{
		// 0 : ����x
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
	int size = words.size(); // �� ���� �ܾ ����Ǿ� �ִ��� Ȯ��

	for (int i = 0; i < size; i++)
	{
		if (words[i] == word) {
			return true;
		}
	}
	return false;
}