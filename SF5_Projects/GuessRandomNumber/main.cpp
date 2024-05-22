//���� ���� ���߱�

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int inputNumber(vector<int> vec);

int main()
{
	srand(time(NULL));
	vector<int> randomNums;
	int num;
	num = rand() % 25 + 1;
	randomNums.push_back(num);

	cout << "���ڴ� 1 ~ 25������ ���ڸ� �Է��� �� �ֽ��ϴ�. \n";

	for (int i = 1; i < 6; i++)
	{
		num = inputNumber(randomNums);
		randomNums.push_back(num);
	}
}

int inputNumber(vector<int> vec){
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