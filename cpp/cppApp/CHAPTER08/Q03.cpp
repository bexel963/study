#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void conv(string&);

int main()
{
	string str;

	cout << "���ڿ��� �Է��Ͻÿ� (�������� q): ";
	while (getline(cin, str) && str != "q")
	{
		conv(str);
		cout << str << endl;
		cout << "���ڿ��� �Է��Ͻÿ� (�������� q): ";
	}

	return 0;
}

void conv(string& str)
{		
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = toupper(str[i]);
	}
}