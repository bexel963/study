#include <iostream>

long double probability(unsigned, unsigned);

int main()
{
	using namespace std;
	double total, choices;
	long double percentage1, percentage2;
	long double megaNum;

	cout << "��ü ���� ������ ���� ���� ������ �Է��Ͻʽÿ�: \n";

	while ((cin >> total >> choices) && choices <= total)
	{
		percentage1 = probability(total, choices);
		
		cout << "�� ��° �õ��� ���� ��ü ���� ������ �Է��Ͻʽÿ�: ";
		cin >> percentage2;

		megaNum = percentage1 * percentage2;
		
		cout << "����� �̱� Ȯ���� ";
		cout << megaNum;
		cout << "�� �߿��� �� �� �Դϴ�.\n";
		cout << "�ٽ� �� ���� �Է��Ͻʽÿ�. (�������� q�� �Է�): ";
	}
	cout << "���α׷��� �����մϴ�.\n";

	return 0;
}

long double probability(unsigned numbers, unsigned picks)
{
	long double result = 1.0;
	long double n;
	unsigned p;

	for (n = numbers, p = picks; p > 0; n--, p--)
		result = result * n / p;

	return result;
}