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

	return temp;
}