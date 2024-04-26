//240426
//time

#include <iostream>
#include <time.h>
using namespace std;

int main() {
	time_t start1, end1;
	double result1;

	start1 = time(NULL);

	for (int i = 0; i < 1000000000; i++)
	{

	}

	end1 = time(NULL);
	result1 = double(end1 - start1);

	cout << "수행 시간 : " << result1 << "second" << "\n";

	clock_t start2, end2;
	double result2;

	start2 = clock();

	for (int i = 0; i < 1000000000; i++)
	{

	}


	end2 = clock();
	result2 = double(end2 - start2);
	cout << "수행 시간 : " << result2 << "millisecond" << "\n";

	return 0;
}