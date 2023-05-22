#include <iostream>

const int ArSize = 10;

void strcount(const char*);

int main()
{
	using namespace std;
	char input[ArSize];
	char next;

	cout << "�������� �� ���� �Է��Ͻʽÿ�:\n";
	cin.get(input, ArSize);
	while (cin)
	{
		cin.get(next);
		while (next != '\n')	// ���� ����
			cin.get(next);
		strcount(input);
		cout << "���� ���� �Է��Ͻʽÿ�(�������� �� ���� �Է�): \n";
		cin.get(input, ArSize);
	}
	cout << "���α׷��� �����մϴ�.\n";

	return 0;
}

void strcount(const char* str)
{
	using namespace std;
	static int total = 0;
	int count = 0;

	cout << "\"" << str << "\"���� ";
	while (*str++)
		count++;
	total += count;
	cout << count << "���� ���ڰ� �ֽ��ϴ�.\n";
	cout << "���ݱ��� �� " << total << "���� ���ڸ� �Է��ϼ̽��ϴ�.\n";
}