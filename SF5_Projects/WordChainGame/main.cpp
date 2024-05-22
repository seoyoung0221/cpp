//타임어택 끝말잇기
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
			cout << "타임 오버!";
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
		cout << "단어를 입력하세요 : ";
		cin >> inputWord;

		if (checkError(words, inputWord) == true)
		{
			cout << "영어 단어를 입력해주세요. \n\n";
			errorCnt++;
		}

		if (checkFirstAndLast(words, inputWord) == true)
		{
			cout << "잘못된 입력입니다. \n\n";
			errorCnt++;
		}

		if (checkRepetition(words, inputWord) == true)
		{
			cout << "중복된 단어입니다. \n\n";
			errorCnt++;
		}

		if (errorCnt == 0) break;
	}
	cout << "\n";

	return inputWord;
}

// 문자인지 확인 (문자 o : false, 문자 x : true)
bool checkError(vector<string> words, string word) {
	for (char& c : word)
	{
		// 0 : 문자x
		if (isalpha(c) == 0)
		{
			return true;
		}
	}

	return false;
}

// 끝말잇기가 제대로 되어있는지 확인 (끝말잇기 o : false, 끝말잇기 x : true)
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

//중복된 단어면 true 반환
bool checkRepetition(vector<string> words, string word)
{
	int size = words.size(); // 몇 개의 단어가 저장되어 있는지 확인

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