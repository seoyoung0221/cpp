//배스킨라빈스 31게임
//서로 최소 1개에서 최대 3개의 연속된 숫자를 말하고 31이라는 숫자를 말하는 사람이 지는 게임

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int inputNumber(int character);
int callNumber(int gameNum, int num);

int main() {
	static int user = 0;
	static int computer = 1;
	int gameNum = 0; //game에 진행되는 수
	int userNum; //user가 외치는 숫자의 개수
	int computerNum; //computer가 외치는 숫자의 개수

	while (true)
	{
		//사용자의 개수 입력
		userNum = inputNumber(user);

		//숫자 외치기
		cout << "사용자가 부른 숫자! \n";
		gameNum = callNumber(gameNum, userNum);
		if (gameNum == 31)
		{
			cout << "컴퓨터의 승리입니다.";
			break;
		}

		//컴퓨터의 개수 입력
		computerNum = inputNumber(computer);

		//숫자 외치기
		cout << "컴퓨터가 부른 숫자! \n";
		gameNum = callNumber(gameNum, computerNum);
		if (gameNum == 31)
		{
			cout << "사용자의 승리입니다.";
			break;
		}

	}



	return 0;
}

// 몇 개의 숫자를 외칠 것인지 정하는 함수
int inputNumber(int character) {

	srand(time(NULL));
	int num; //외치는 숫자의 개수

	if (character == 0) //사용자 차례
	{
		cout << "개수를 입력하세요: ";
		cin >> num;
	}
	else if (character == 1) //컴퓨터 차례
	{
		num = rand() % 3 + 1;
	}

	return num;
}

// 숫자 외치는 함수
int callNumber(int gameNum, int num) {
	for (int i = 0; i < num; i++)
	{
		gameNum++;
		if (gameNum == 31)
		{
			cout << gameNum << "\n";
			cout << "게임 종료!";
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
