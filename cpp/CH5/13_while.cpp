#include <iostream>

const int ArSize = 20;

int main()
{
	using namespace std;

	char name[ArSize];

	cout << "���� �̸��� �Է��Ͻʽÿ�: ";
	cin >> name;
	cout << "������ ���� �̸��� �� �ٿ� �� �ھ�\n ASCII �ڵ�� �Բ� ǥ���ϸ� �̷����ϴ�.\n";

	int i = 0;
	while (name[i] != '\0')
	{
		cout << name[i] << ": " << (int)name[i] << endl;
		i++;
	}

	return 0;
}