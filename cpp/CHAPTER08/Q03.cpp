#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void conv(string&);

int main()
{
	string str;

	cout << "문자열을 입력하시오 (끝내려면 q): ";
	while (getline(cin, str) && str != "q")
	{
		conv(str);
		cout << str << endl;
		cout << "문자열을 입력하시오 (끝내려면 q): ";
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