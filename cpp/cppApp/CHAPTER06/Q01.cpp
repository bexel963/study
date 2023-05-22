#include <iostream>
#include <cctype>

using namespace std;

int main()
{
	char ch;

	/*cin >> ch;
	while (ch != '@')
	{
		if ('0' <= ch && ch <= '9')
		{
			cin >> ch;
			continue;
		}

		ch = toupper(ch);
		cout << ch;
		cin >> ch;
	}*/

	while ((ch = cin.get()) != '@')
	{
		if ('0' <= ch && ch <= '9')
		{			
			continue;
		}
		ch = toupper(ch);
		cout << ch;
	}

	return 0;
}