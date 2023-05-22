#include <iostream>
#include <string>

using namespace std;
const int SIZE = 20;

int main()
{
	char word[SIZE];
	int etc = 0;
	int consonant = 0;
	int gather = 0;

	cout << "단어들을 입력하시오 (끝내려면 q): \n";
	while ((cin>>word) && strcmp(word, "q\0"))
	{
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

	cout << "모음으로 시작하는 단어 수: " << gather << endl;
	cout << "자음으로 시작하는 단어 수: " << consonant << endl;
	cout << "기타: " << etc << endl;

	return 0;
}