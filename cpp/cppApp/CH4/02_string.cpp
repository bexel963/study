#include <iostream>

int main()
{
	using namespace std;

	const int size = 15;
	char name1[size];
	char name2[size] = "C++owboy";

	cout << "�ȳ��ϼ���! ���� " << name2 << "�Դϴ�! �Ƿ����� ������?\n";
	cin >> name1;
	cout << "��, " << name1 << "��! ����� �̸��� " << strlen(name1) << "���Դϴٸ�\n"
		 << sizeof(name1) << "����Ʈ ũ���� �迭�� ����Ǿ����ϴ�.\n"
		 << "�̸��� " << name1[0] << "�ڷ� �����ϴ±���.\n";
	name2[3] = '\0';
	cout << "�� �̸��� ó�� �� ���ڴ� ������ �����ϴ�: " << name2 << endl;

	return 0;
}