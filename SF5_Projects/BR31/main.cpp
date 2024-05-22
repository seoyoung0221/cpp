//�轺Ų��� 31����
//���� �ּ� 1������ �ִ� 3���� ���ӵ� ���ڸ� ���ϰ� 31�̶�� ���ڸ� ���ϴ� ����� ���� ����

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int inputNumber(int character);
int callNumber(int gameNum, int num);
bool checkError(string input);

int main() {
	static int user = 0;
	static int computer = 1;
	int gameNum = 0; //game�� ����Ǵ� ��
	int userNum; //user�� ��ġ�� ������ ����
	int computerNum; //computer�� ��ġ�� ������ ����

	while (true)
	{
		//������� ���� �Է�
		userNum = inputNumber(user);

		//���� ��ġ��
		cout << "����ڰ� �θ� ����! \n";
		gameNum = callNumber(gameNum, userNum);
		if (gameNum == 31)
		{
			cout << "��ǻ���� �¸��Դϴ�.";
			break;
		}

		//��ǻ���� ���� �Է�
		computerNum = inputNumber(computer);

		//���� ��ġ��
		cout << "��ǻ�Ͱ� �θ� ����! \n";
		gameNum = callNumber(gameNum, computerNum);
		if (gameNum == 31)
		{
			cout << "������� �¸��Դϴ�.";
			break;
		}

	}



	return 0;
}

// �� ���� ���ڸ� ��ĥ ������ ���ϴ� �Լ�
int inputNumber(int character) {

	srand(time(NULL));
	int num; //��ġ�� ������ ����
	string input; //������� �Է�
	bool error;

	if (character == 0) //����� ����
	{
		while (true) {
			cout << "������ �Է��ϼ���: ";
			cin >> input;
			error = checkError(input);
			if (error == false)
			{
				break;
			}
			else if (error == true)
			{
				cout << "1 ~ 3 ������ ���ڸ� �Է��ϼ���.\n";
			}
		}
		num = stoi(input);
	}
	else if (character == 1) //��ǻ�� ����
	{
		num = rand() % 3 + 1;
	}

	return num;
}

// ���� ��ġ�� �Լ�
int callNumber(int gameNum, int num) {
	for (int i = 0; i < num; i++)
	{
		gameNum++;
		if (gameNum == 31)
		{
			cout << gameNum << "\n";
			cout << "���� ����!";
			break;
		}
		else
		{
			cout << gameNum << "\n";
		}
	}
	
	cout << "\n";

	return gameNum;
}

// ����ڰ� ���� ����� �Է��ߴ��� Ȯ���ϴ� �Լ�
bool checkError(string str) 
{
	// �������� Ȯ��
	for (char& c : str)
	{
		// 0 : ����x
		if (isdigit(c) == 0)
		{
			return true;
		}
	}

	// 1~3������ �������� Ȯ��
	switch (stoi(str))
	{
	case 1: 
		return false;
	case 2:
		return false;
	case 3: 
		return false;
	default:
		return true;
	}
}