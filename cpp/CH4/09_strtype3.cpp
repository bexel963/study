#include <iostream>
#include <string>
#include <cstring>	// C 스타일 문자열 라이브러리

int main()
{
	using namespace std;

	char charr1[20];
	char charr2[20] = "jaguar";
	string str1;
	string str2 = "panther";

	str1 = str2;
	strcpy(charr1, charr2);

	str1 += " paste";
	strcat(charr1, " juice");

	int len1 = str1.size();
	int len2 = strlen(charr1);

	cout << str1 << " 문자열에는 " << len1 << "개의 문자가 들어있다.\n";
	cout << charr1 << " 문자열에는 " << len2 << "개의 문자가 들어있다.\n";

	return 0;
}