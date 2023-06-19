#include <iostream>
#include <string>

using namespace std;

string version1(const string&, const string&);
const string& version2(string&, const string&);		// �μ� ȿ��
const string& version3(string&, const string&);		// ���� ����

int main()
{
	string input;
	string copy;
	string result;

	cout << "���ڿ��� �Է��Ͻÿ�: ";
	getline(cin, input);
	copy = input;
	cout << "�Է��� ���ڿ�: " << input << endl << endl;

	result = version1(input, "**");
	cout << "�ٲ� ���ڿ�: " << result << endl;
	cout << "���� ���ڿ�: " << input << endl;
	cout << endl;

	result = version2(input, "###");
	cout << "�ٲ� ���ڿ�: " << result << endl;
	cout << "���� ���ڿ�: " << input << endl;
	cout << endl;
	
	cout << "���� ���ڿ� �缳��\n";
	input = copy;
	result = version3(input, "@@@");
	cout << "�ٲ� ���ڿ�: " << result << endl;
	cout << "���� ���ڿ�: " << input << endl;
	cout << endl;
	
	return 0;
}

string version1(const string& s1, const string& s2)
{
	string temp;

	temp = s2 + s1 + s2;

	return temp;
}
const string& version2(string& s1, const string& s2)
{
	s1 = s2 + s1 + s2;

	return s1;
}
const string& version3(string& s1, const string& s2)
{
	string temp;

	temp = s2 + s1 + s2;

	return temp;	// ���� ������ ���� ������ �����ϹǷ� �������� �ʴ�.
}

/*
	- �Ϲ������� C++��, Ŭ���� ��ü�� �Լ��� ������ �� ������ ����Ѵ�.
*/

/*
	- const ���� ���� �Ű������� Ư������ �ǸŰ������� ���������� ���� �Ű������� ���������� ��ġ���� ������, ���� ������������ ��ȯ�� �� ������,
	  ���α׷��� �ùٸ� ���������� �ӽ� ������ �����, ��ȯ�� ������ �װ��� �ʱ�ȭ�ϰ�, �ӽ� ������ ������ �����Ѵ�.
*/

/*
	- ������ vs ����

		: �Լ��� ���޵� �����͸� �������� �ʰ� ��븸 �ϴ� ���
			������ ��ü�� �⺻ ���������̳� ���� ����ü�� ������ �����Ѵ�.
			������ ��ü�� �迭�̶�� �����Ͱ� ������ �����̹Ƿ� �����͸� ����Ѵ�.
			������ ��ü�� ��ġ ū ����ü��� const�����ͳ� const������ ����Ѵ�.
			������ ��ü�� Ŭ���� ��ü��� const������ ����Ѵ�. => Ŭ���� ��ü �Ű������� ������ ������ �����ϴ� ���� ǥ���̴�.

		: �Լ��� ȣ�� �Լ��� �����͸� �����ϴ� ���
			������ ��ü�� �⺻ ���������̸� �����͸� ����Ѵ�.
			������ ��ü�� �迭�̸� ������ ������ �����͸� ����ϴ� ���̴�.
			������ ��ü�� ����ü�̸� ���� �Ǵ� �����͸� ����Ѵ�.
			������ ��ü�� Ŭ���� ��ü�̸� ������ ����Ѵ�.
*/