#include <iostream>
#include <string>

using namespace std;

const int len = 10;

int main()
{
	string word;
	int cnt = 0;

	cout << "���� �ܾ���� �Է��Ͻʽÿ� (�������� done �Է�): " << endl;
	cin >> word;

	while (word != "done")
	{
		cnt++;
		cin >> word;
	}

	cout << "�� " << cnt << "�ܾ �ԷµǾ����ϴ�.\n";

	return 0;
}