#include <iostream>
#include <string>

using namespace std;

void wordCnt(const string&);

int main()
{
	string word;

	cout << "영문으로 한 행을 입력하십시오(끝내려면 빈칸 입력).\n";
	while (getline(cin, word) && word != " ")
		wordCnt(word);

	cout << "종료~~" << endl;

	return 0;
}

void wordCnt(const string& str)
{
	static int totalCnt = 0;
	int cnt = 0;

	cnt = str.size();
	totalCnt += cnt;		

	cout << "\"" << str << "\" 에는 " << cnt << "개의 문자가 있습니다.\n";
	cout << "지금까지 총 " << totalCnt << "개의 문자를 입력했습니다.\n";
	
}