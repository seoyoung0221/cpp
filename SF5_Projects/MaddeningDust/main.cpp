//랜덤 숫자 맞추기

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int main() {
	int n;
	int cnt = 1;
	int rowBefore, colBefore, rowAfter, colAfter;
	cout << "마방진의 행 혹은 열의 수를 자연수로 입력해주세요 : \n";
	cin >> n;

	int** array = new int* [n];

	for (int i = 0; i < n; i++)
	{
		array[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			array[i][j] = 0;
		}
	}

	//1은 첫 행의 가운데
	rowBefore = 0;
	colBefore = n / 2;

	for (int i = 0; i < n * n; i++)
	{
		array[rowBefore][colBefore] = cnt;

		rowAfter = rowBefore - 1;
		colAfter = colBefore + 1;
		

		if (rowAfter < 0) {
			rowAfter = n - 1;
		}
		if (colAfter >= n) {
			colAfter = 0;
		}

		if (array[rowAfter][colAfter] != 0)
		{
			rowAfter = rowBefore + 1;
			colAfter = colBefore;
		}

		rowBefore = rowAfter;
		colBefore = colAfter;
		cnt++;

	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << array[i][j] << "\t";
		}
		cout << "\n";
	}


	//동적배열 해제
	for (int i = 0; i < n; i++)
	{
		delete[] array[i];
	}

	delete[] array;
	return 0;
}