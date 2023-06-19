#include <iostream>
#include <cstdlib>
#include <ctime>
#include "stringImproving.h"

const int ArSize = 10;
const int MaxLen = 81;

int main()
{
	using namespace std;
	String name;
	cout << "�ȳ��Ͻʴϱ�? ������ ��� �ǽʴϱ�?\n";
	cin >> name;
	
	cout << name << " ��! ������ �츮 �Ӵ� " << ArSize << "���� �Է��� �ֽʽÿ�(�������� Enter):\n";
	String sayings[ArSize];
	char temp[MaxLen];
	int i;
	for (i = 0; i < ArSize; i++)
	{
		cout << i + 1 << ": ";
		cin.get(temp, MaxLen);
		while (cin && cin.get() != '\n')
			continue;
		if (!cin || temp[0] == '\0')
			break;
		else
			sayings[i] = temp;
	}
	int total = i;

	if (total > 0)
	{
		cout << "(������ ���� �Ӵ���� �Է��ϼ̽��ϴ�.)\n";
		for (i = 0; i < total; i++)
			cout << sayings[i] << "\n";

		String* shortest = &sayings[0];	// ù ��° ��ü�� �ʱ�ȭ�Ѵ�.
		String* first = &sayings[0];
		for (i = 1; i < total; i++)
		{
			if (sayings[i].length() < shortest->length())	// �޼��忡 ����
				shortest = &sayings[i];
			if (sayings[i] < *first)	// ��ü ���
				first = &sayings[i];	// �ּ� ����.
		}
		cout << "���� ª�� �Ӵ�:\n" << *shortest << endl;
		cout << "���������� ���� �տ� ������ �Ӵ�:\n" << *first << endl;

		srand(time(0));
		int choice = rand() % total;

		String* favorite = new String(sayings[choice]);
		/*
			- �ʱ�ȭ�� sayings[choice]�� ���� �������� �Ű����� ��������(const String&)�� ��ġ�ϹǷ�,
			  �� ������ ���� �����ڸ� ȣ���Ѵ�.
		*/

		cout << "���� ���� �����ϴ� �Ӵ�:\n" << *favorite << endl;
		delete favorite; // ���� ��ü�̱� ������ ���ȣ ���� delete�� ����Ѵ�.
	}
	else
		cout << "�˰� �ִ� �Ӵ��� �ϳ��� �����?\n";
	cout << "���α׷��� �����մϴ�.\n";

	return 0;
}

/*
	- new�� ���� ��ü �ʱ�ȭ
	  Class_name* pClass = new Class_name(value);
		: ������ ���� �����ڸ� ȣ���Ѵ�.
			Class_name(Type_name);
		: ������ ���� ����� ��ȯ�� �̷���� �� �ִ�.
			Class_name(const Type_name&);
		: int�� double�� ��ȯ�ϴ� �Ͱ� ����, ���� ��ġ�� ���� ȣ��Ǵ� ��ȯ�� ��ȣ���� ���� �� �̷������.
		: ������ ���� ������ �ʱ�ȭ�� ����Ʈ �����ڸ� ȣ���Ѵ�.
			Class_name* ptr = new Class_name;
*/

/*
	- �����Ϳ� ��ü
		: Ŭ���� ��ü�� �����ϴ� �����͸� �����Ѵ�.
				String* glamour;

		: �����͸� ������ ��ü�� �ʱ�ȭ�Ѵ�.
				String* first = &saying[0];

		: ����Ʈ Ŭ���� �����ڸ� ����Ͽ� �����͸� �ʱ�ȭ�Ѵ�.
				String* gleep = new String;

		: String(const char*) �����ڸ� ����Ͽ� �����͸� �ʱ�ȭ�Ѵ�.
				String* glop = new String("my my my");

		: String(const String&) �����ڸ� ����Ͽ� �����͸� �ʱ�ȭ�Ѵ�.
				String* favorite = new String(sayings[Choice]);

		: �����͸� ����Ͽ� Ŭ���� �޼��忡 �����ϱ����� -> �����ڸ� ����Ѵ�..
				if(sayings[i].length() < shortest->length())

		: �����͸� ����Ͽ� ��ü�� ������� ���� ���� ������(*)�� ����Ѵ�.
				if(sayings[i] < *first)
*/