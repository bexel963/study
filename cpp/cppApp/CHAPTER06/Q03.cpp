#include <iostream>

using namespace std;

void menu();

int main()
{
	char input;
	menu();

	while ((input = cin.get()) && input != 'q')
	{
		cin.get();
		switch (input)
		{
		case 'c':
			cout << "ī�޶� ����!!\n";
			break;
		case 'p':
			cout << "�ǾƳ� ����!!\n";
			break;
		case 't':
			cout << "���� ����!!\n";
			break;
		case 'g':
			cout << "���� ����!!\n";
			break;
		default:
			cout << "c, p, t, g �߿��� �ϳ��� �����Ͻʽÿ�. (�������� q): ";
		}
	}
	return 0;
}

void menu()
{
	cout << "���� ���� ���� �߿��� �ϳ��� �����Ͻʽÿ�. (�������� q)" << endl;
	cout << "c) camera\t\tp) pianist\nt) tree\t\t\tg) game\n";
}