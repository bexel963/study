#include <iostream>
#include <string>

using namespace std;

void wordCnt(const string&);

int main()
{
	string word;

	cout << "�������� �� ���� �Է��Ͻʽÿ�(�������� ��ĭ �Է�).\n";
	while (getline(cin, word) && word != " ")
		wordCnt(word);

	cout << "����~~" << endl;

	return 0;
}

void wordCnt(const string& str)
{
	static int totalCnt = 0;
	int cnt = 0;

	cnt = str.size();
	totalCnt += cnt;		

	cout << "\"" << str << "\" ���� " << cnt << "���� ���ڰ� �ֽ��ϴ�.\n";
	cout << "���ݱ��� �� " << totalCnt << "���� ���ڸ� �Է��߽��ϴ�.\n";
	
}