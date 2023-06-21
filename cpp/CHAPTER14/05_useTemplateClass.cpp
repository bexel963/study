#include <iostream>
#include <string>
#include <cctype>
#include "templateClass.h"
using std::cin;
using std::cout;

int main()
{
	Stack<std::string> st;
	/*
		- ���ø��� ��üȭ�� ��û�Ϸ���, ���ø� Ŭ�������� ��ü�� �����ϵ�, �������� �������� �̸��� ��ü���� ������������ ��ü�ؾ� �Ѵ�.
		- �Լ� �Ű������� ���������� ����Ͽ�, �����Ϸ��� � ������ �Լ��� ������ ������ �����ϴ� �Ϲ����� �Լ� ���ø����� �ٸ���
		  Ŭ���� ���ø������� ����Ϸ��� ���������� ���������� �����ؾ� �Ѵ�.
					template<class T>
					void simple(T t) { cout << t << '\n'; }
					...
					simple(2);			// void simple(int) ����
					simple("two");		// void simple(char*) ����
	*/

	char ch;
	std::string po;
	cout << "�ֹ����� �߰��Ϸ��� A, �ֹ����� ó���Ϸ��� P, \n"
		<< "�����Ϸ��� Q�� �Է��Ͻʽÿ�.\n";

	while (cin >> ch && std::toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			continue;
		if (!std::isalpha(ch))
		{
			cout << '\a';
			continue;
		}
		
		switch (ch)
		{
		case 'A':
		case 'a':
			cout << "�߰��� �ֹ����� ��ȣ�� �Է��Ͻʽÿ�: ";
			cin >> po;
			if (st.isfull())
				cout << "������ ���� �� �ֽ��ϴ�.\n";
			else
				st.push(po);
			break;
		case 'P':
		case 'p':
			if (st.isempty())
				cout << "������ ����ֽ��ϴ�.\n";
			else
			{
				st.pop(po);
				cout << "#" << po << " �ֹ����� ó���߽��ϴ�.\n";
			}
			break;
		}
		cout << "�ֹ����� �߰��Ϸ��� A, �ֹ����� ó���Ϸ��� P, \n"
			<< "�����Ϸ��� Q�� �Է��Ͻʽÿ�.\n";
	}
	cout << "���α׷��� �����մϴ�.\n";
	return 0;
}


/*
	- �����͸� Ŭ���� ���ø��� ������������ ����� �� ������?
	- �����͵��� ������ �߸� ����ϴ� ���
			
			����1)
				Stack<char*> st;
				string po;	-> char* po;

	  -> cin >> po; ���� error����.
			: �������� �ܼ��� ������ �Է� ���ڿ����� ���� ������ �������� �ʱ� ������, �̿� ���� ������ ��� �����Ѵ�.
			  ���α׷��� �������� �ǰ�����, cin�� �Է��� �������� ��ҿ� �����Ϸ��� �õ��� �� ������ �� ���̴�.

			����2)
				Stack<char*> st;				
				string po;	-> char po[40];

	  -> �̰��� �Է� ���ڿ��� �����ϱ� ���� ������ �����ϰ�, po�� char*���̹Ƿ� ���ÿ� ���� �� �ִ�.
	     �׷��� �迭�� pop() �޼��忡�� ����� ������ �⺻������ ��ȭ�� ����Ų��.
			: ���� ���� item�� �迭 �̸��� �ƴ϶� � ������ Lvalue�� �����ؾ� �Ѵ�.
			: �� �ڵ�� item�� ������ �� �ִٰ� �����Ѵ�. item�� � �迭�� ������ �� ��������, �迭 �̸����� ������ �� ����.

			����3)
				Stack<char*> st;
				char* po = new char[40];

	  -> �̰��� �Է� ���ڿ��� �����ϱ� ���� ������ �����ϴ� ���ٰ�, po�� �����̹Ƿ� pop()�� ��ȭ�� ����Ű�� �ʴ´�.
	     �׷��� po ������ �ϳ��ۿ� ����, �װ��� �׻� ���� �޸� ��ġ�� �����Ѵ�.
		 �� �޸��� ������ ���ο� ���ڿ��� ���� ���Ŵ� �ٲ��. �׷��� Ǫ�� ������ �Ź� ��Ȯ�� ������ �ּҸ� ���ÿ� �ִ´�.
		 �׷��� ������ ���ϸ�, �׻� ������ �ּҸ� ��´�.
		 �׷��� �װ��� �޸𸮿� ���������� �о���� ���ڿ��� �׻� �����Ѵ�.
		 Ư��, �׿� ���� ������ �� ���ڿ��� ���� ������ �̵��� ���������� �������� �����Ƿ� ������ �뵵�� ����� �� ����.
			

	=> �����͵��� ������ ����ϴ� �� ���� �����, ȣ���� ���α׷��� �����͵��� �迭�� �����ϴ� ���̴�.
	   �� �����͵��� �迭���� ������ �����ʹ� ���� �ٸ� ���ڿ��� �����Ѵ�.
	   �̷��� �����͵��� ���ÿ� �ִ� ����, ������ �����Ͱ� ���� �ٸ� ���ڿ��� �����ϱ� ������ ���������� Ʋ���� �ʴ´�.
			
*/