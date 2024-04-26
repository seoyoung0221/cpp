// 240426
// 2차원 동적 배열

#include <iostream>
using namespace std;

int main()
{
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
			cout << arr[i][j] << " ";
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
