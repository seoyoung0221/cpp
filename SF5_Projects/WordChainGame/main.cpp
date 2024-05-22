//Ÿ�Ӿ��� �����ձ�
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

string inputWord(vector<string> words);
bool checkError(vector<string> words, string word);
bool checkFirstAndLast(vector<string> words, string word);
bool checkRepetition(vector<string> words, string word);
void printWords(vector<string> words);

int main() {
	clock_t startTime = clock();
	clock_t endTime;
	vector<string> words;
	string newWord;

	words.push_back("airplane");
	cout << words[0] << "\n";

	while (true) {
		newWord = inputWord(words);
		words.push_back(newWord);

		printWords(words);

		endTime = clock();
		if ((endTime - startTime) / CLOCKS_PER_SEC > 30)
		{
			cout << "Ÿ�� ����!";
			break;
		}

	}
	

	return 0;
}

string inputWord(vector<string> words) {
	string inputWord;
	int errorCnt;
	while (true)
	{
		errorCnt = 0;
		cout << "�ܾ �Է��ϼ��� : ";
		cin >> inputWord;

		if (checkError(words, inputWord) == true)
		{
			cout << "���� �ܾ �Է����ּ���. \n\n";
			errorCnt++;
		}

		if (checkFirstAndLast(words, inputWord) == true)
		{
			cout << "�߸��� �Է��Դϴ�. \n\n";
			errorCnt++;
		}

		if (checkRepetition(words, inputWord) == true)
		{
			cout << "�ߺ��� �ܾ��Դϴ�. \n\n";
			errorCnt++;
		}

		if (errorCnt == 0) break;
	}
	cout << "\n";

	return inputWord;
}

// �������� Ȯ�� (���� o : false, ���� x : true)
bool checkError(vector<string> words, string word) {
	for (char& c : word)
	{
		// 0 : ����x
		if (isalpha(c) == 0)
		{
			return true;
		}
	}

	return false;
}

// �����ձⰡ ����� �Ǿ��ִ��� Ȯ�� (�����ձ� o : false, �����ձ� x : true)
bool checkFirstAndLast(vector<string> words, string word) {
	string lastWord = words.back();
	int wordSize = lastWord.size();

	if (lastWord[wordSize - 1] == word[0]) {
		return false;
	}
	else
	{
		return true;
	}


}

//�ߺ��� �ܾ�� true ��ȯ
bool checkRepetition(vector<string> words, string word)
{
	int size = words.size(); // �� ���� �ܾ ����Ǿ� �ִ��� Ȯ��

	for (int i = 0; i < size; i++)
	{
		if (words[i] == word) {
			return true;
		}
	}
	return false;
}

void printWords(vector<string> words)
{
	int size = words.size();
	for (int i = 0; i < size; i++)
	{
		cout << words[i];
		if (i == size - 1)
		{
			cout << "\n";
		}
		else
		{
			cout << "->";
		}

	}

}