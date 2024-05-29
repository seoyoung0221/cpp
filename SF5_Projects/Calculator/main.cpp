//계산기 만들기

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

	cout << "숫자를 입력해주세요 : ";
	cin >> num1;

	while (true)
	{
		cout << "연산자를 입력해주세요 : ";
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

		cout << "숫자를 입력해주세요 : ";
		cin >> num2;
		cal->setNum(num1, num2);
		cal->calculate();

		cout << "----------------------------------------------------------\n";
		cout << "결과 : " << cal->getResult() << "\n";
		cout << "----------------------------------------------------------\n";

		cout << "연산을 계속 진행하겠습니까? (Y : 계속, AC : 초기화, EXIT : 종료) ";
		cin >> mode;
		if (mode == "Y") 
		{
			num1 = cal->getResult();
			cout << "계속합니다. \n";
		}
		else if(mode == "AC")
		{
			num1 = 0;
			cout << "초기화합니다. \n";
		}
		else if (mode == "EXIT")
		{
			cout << "종료합니다. \n";
			break;
		}
	}
	delete cal;
	return 0;
}

