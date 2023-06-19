#include <iostream>
#include <cstring>

using namespace std;

const int len = 10;

int main()
{
	char word[len];
	int cnt = 0;

	cout << "영어 단어들을 입력하십시오 (끝내려면 done 입력): " << endl;
	cin >> word;
	
	while (strcmp(word, "done") != 0)
	{
		cnt++;
		cin >> word;
	}

	cout << "총 " << cnt << "단어가 입력되었습니다.\n";

	return 0;
}