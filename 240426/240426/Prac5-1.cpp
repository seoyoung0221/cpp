#include <iostream>

int main() {
	int n1, n2;
	std::cout << "숫자를 입력하세요: ";
	std::cin >> n1 ;
	std::cin >> n2;
	int** arr2 = new int* [n1];

	for (int i = 0; i < n1; i++) {
		arr2[i] = new int[n2];
	}

	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			arr2[i][j] = 0;
		}
	}
	/*
	for (int i = 0; i < n3; i++)
	{
		for (int j = 0; j < n3; j++)
		{
			std::cout << arr2[i][j] << " ";
		}
		std::cout << "\n";
	}

	*/
	for (int i = 0; i < n1; i++) {
		delete[] arr2[i];
	}

	delete[] arr2;

}