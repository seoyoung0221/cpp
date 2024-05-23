//���� ���� ���߱�

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
	cout << "�������� �� Ȥ�� ���� ���� �ڿ����� �Է����ּ��� : \n";
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

	//1�� ù ���� ���
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


	//�����迭 ����
	for (int i = 0; i < n; i++)
	{
		delete[] array[i];
	}

	delete[] array;
	return 0;
}