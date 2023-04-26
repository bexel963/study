#include <iostream>
#include <string>

using namespace std;

const int len = 10;

int main()
{
	string word;
	int cnt = 0;

	cout << "영어 단어들을 입력하십시오 (끝내려면 done 입력): " << endl;
	cin >> word;

	while (word != "done")
	{
		cnt++;
		cin >> word;
	}

	cout << "총 " << cnt << "단어가 입력되었습니다.\n";

	return 0;
}