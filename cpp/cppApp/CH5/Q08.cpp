#include <iostream>
#include <cstring>

using namespace std;

const int len = 10;

int main()
{
	char word[len];
	int cnt = 0;

	cout << "���� �ܾ���� �Է��Ͻʽÿ� (�������� done �Է�): " << endl;
	cin >> word;
	
	while (strcmp(word, "done") != 0)
	{
		cnt++;
		cin >> word;
	}

	cout << "�� " << cnt << "�ܾ �ԷµǾ����ϴ�.\n";

	return 0;
}