// 텍스트 파일을 열고, 파일의 끝까지 문자 단위로 읽고, 그 파일에 들어 있는 문자들의 수를 보고하는 프로그램

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
const int SIZE = 20;

int main()
{
	string fileName = "wordList.txt";
	char word[SIZE];
	int etc = 0;
	int consonant = 0;
	int gather = 0;

	ifstream inFile;

	inFile.open(fileName);
	if (!inFile.is_open())
	{
		cout << fileName << " 파일을 열 수 없습니다. " << endl;
		cout << "프로그램을 종료합니다.\n";
		exit(EXIT_FAILURE);
	}
	
	while (inFile >> word)
	{
		cout << word << endl;
		if (!isalpha(word[0]))
			etc++;
		else
		{
			switch (word[0])
			{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				gather++;
				break;
			default:
				consonant++;
			}
		}
	}
	if (inFile.eof())
		cout << "파일 끝에 도달했습니다.\n";
	else if (inFile.fail())
		cout << "데이터 불일치로 입력이 종료되었습니다.\n";
	else
		cout << "알 수 없는 이유로 입력이 종료되었습니다.\n";

	cout << "모음으로 시작하는 단어 수: " << gather << endl;
	cout << "자음으로 시작하는 단어 수: " << consonant << endl;
	cout << "기타: " << etc << endl;

	return 0;
}