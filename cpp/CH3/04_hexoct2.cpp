#include <iostream>

int main()
{
	using namespace std;
	int chest = 42;
	int waist = 42;
	int inseam = 42;

	cout << "�մ� ���Ŵ� �Ѹ���� ���� �ݴϴ�!\n";
	cout << "�����ѷ� " << chest << " (10����)\n";

	cout << hex;
	cout << "�㸮�ѷ� " << waist << " (16����)\n";

	cout << oct;
	cout << "�νɱ��� " << inseam << " (8����)\n";

	return 0;
}