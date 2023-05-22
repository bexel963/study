#include <iostream>

unsigned int c_in_str(const char*, char);

int main()
{
	using namespace std;
	char mmm[15] = "minimun";

	const char* wail = "ululate";

	unsigned int ms = c_in_str(mmm, 'm');
	unsigned int us = c_in_str(wail, 'u');
	cout << mmm << "���� m�� " << ms << "�� ����ֽ��ϴ�.\n";
	cout << wail << "���� u�� " << us << "�� ����ֽ��ϴ�.\n";

	return 0;
}

unsigned int c_in_str(const char* str, char ch)
{
	int count = 0;

	while (*str)	// => str�� '\0'�̸� ������ Ż���Ѵ�.  '\0' �� ��ġ �ڵ�� 0�̴�.
	{
		if (*str == ch)
			count++;
		str++;
	}

	return count;
}

/*
	- C��Ÿ�� ���ڿ��� ��Ÿ���� ��� 3����
		1) char���� �迭
			char ghost[15] = "galloping";
		2) ū����ǥ�� ���� ���ڿ� ���(���ڿ� ���ͷ�)
			"gamboling"
		3) ���ڿ��� �ּҷ� ������ char���� �����ϴ� ������
			char* str = "galumphing"

		=> 3 ���� ��� char���� �����ϴ� �������̴�. ������ �� �� ���� ��� ���ڿ� ó�� �Լ��� �Ű������� ����� �� �ִ�.
			int n1 = strlen(ghost);
			int n2 = strlen(str);
			int n3 = strlen("gamboling");

	- C ��Ÿ�� ���ڿ��� �Ϲ� �迭�� �߿��� �������� ���ڿ����� ���� ���ڰ� ��� �ִٴ� ���̴�.
	  ���� ���ڿ��� ũ��� �Ű������� ������ �ʿ䰡 ����.
	  �� ��ſ� �Լ��� ������ ����Ͽ� �� ���� ���ڿ� ������ ������ ���ʷ� ���ڵ��� �˻��ؾ� �Ѵ�.
*/