// 240426
// 2차원 동적 배열

#include <iostream>
using namespace std;

int main()
{
	/*글자, 숫자 판단
	string name = "jo2hn*";

	for (int i; i < name.length(); i++)
	{
		isdigit(name[i]);
		if(isdigit(name[i]) != 0)
		{
			//숫자 O
		}else if(isdigit(name[i] == 0)
		{
			//숫자 x
		}

		isalpha(name[i]);
		//alpha는 반대로 작동 , 특수문자도 0으로 출력
	}
	*/
	int x, y;
	int loop_cnt = 1;
	int error = 0;

	// 입력 받기
	cout << "첫번째 자연수를 입력하세요 : ";
	cin >> x;
	cout << "두번째 자연수를 입력하세요 : ";
	cin >> y; 

	// 동적 배열 만들기
	int** arr = new int* [x];

	for (int i = 0; i < x; i++)
	{
		arr[i] = new int[y];
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			arr[i][j] = loop_cnt;
			loop_cnt++;
		}
	}

	// 동적 배열 출력
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << "\n";
	}

	// 동적 배열 해제
	for (int i = 0; i < x; i++) 
	{
		delete[] arr[i];
	}
	
	delete[] arr;

	return 0;
}
