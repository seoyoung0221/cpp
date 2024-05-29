//���� �����

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class Calculator 
{
protected:

	float m_num1, m_num2;
	static float result;

public:
	virtual float calculate() = 0;

	void setNum(float num1, float num2) {
		this->m_num1 = num1;
		this->m_num2 = num2;
	}

	static float getResult() {
		return result;
	}
};

float Calculator::result = 0;

class Add : public Calculator
{

public: 

	float calculate() override
	{
		result = m_num1 + m_num2;
		return result;
	}
};

class Minus : public Calculator
{

	float calculate() override
	{
		result = m_num1 - m_num2;
		return result;
	}
};


class Multiplication : public Calculator
{

	float calculate() override
	{
		result = m_num1 * m_num2;
		return result;
	}
};

class Division : public Calculator
{
	float calculate() override
	{
		result = m_num1 / m_num2;
		return result;
	}
};


int main() {
	string mode;
	char symbol;
	float num1, num2;
	Calculator* cal;

	cout << "���ڸ� �Է����ּ��� : ";
	cin >> num1;

	while (true)
	{
		cout << "�����ڸ� �Է����ּ��� : ";
		cin >> symbol;
		switch (symbol)
		{
		case('+'):
			cal = new Add();
			break;
		case('-'):
			cal = new Minus();
			break;
		case('*'):
			cal = new Multiplication();
			break;
		case('/'):
			cal = new Division();
			break;
		default :
			continue;
		}

		cout << "���ڸ� �Է����ּ��� : ";
		cin >> num2;
		cal->setNum(num1, num2);
		cal->calculate();

		cout << "----------------------------------------------------------\n";
		cout << "��� : " << cal->getResult() << "\n";
		cout << "----------------------------------------------------------\n";

		cout << "������ ��� �����ϰڽ��ϱ�? (Y : ���, AC : �ʱ�ȭ, EXIT : ����) ";
		cin >> mode;
		if (mode == "Y") 
		{
			num1 = cal->getResult();
			cout << "����մϴ�. \n";
		}
		else if(mode == "AC")
		{
			num1 = 0;
			cout << "�ʱ�ȭ�մϴ�. \n";
		}
		else if (mode == "EXIT")
		{
			cout << "�����մϴ�. \n";
			break;
		}
	}
	delete cal;
	return 0;
}

