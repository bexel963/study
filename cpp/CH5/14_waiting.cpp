#include <iostream>
#include <ctime>

int main()
{
	using namespace std;
	cout << "���� �ð��� �� ������ �Է��Ͻʽÿ�: ";
	float secs;
	cin >> secs;
	clock_t delay = secs * CLOCKS_PER_SEC;

	cout << "ī��Ʈ�� �����մϴ�.\a\n";
	clock_t start = clock(); // ���α׷��� ����� �������� �� �Լ��� ȣ��� �������� ����� �ý��� �ð��� �����Ѵ�.

	cout << "delay: " << delay << endl;
	while (clock() - start < delay)
		;

	cout << "����\a\n";

	return 0;
}