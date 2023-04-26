#include <iostream>
#include <cstring> // strlen(), strcpy() »ç¿ë
using namespace std;



struct stringy
{
	char* str;
	int ct;
};
void set(stringy&, char*);
void show(const stringy&, int n = 1);
void show(const char*, int n = 1);

int main()
{
	struct stringy beany;
	char testing[] = "Reality isn't what it used to be.";
	
	set(beany, testing);
	show(beany);
	show(beany, 2);
	
	testing[0] = 'D';
	testing[1] = 'u';

	show(testing);
	show(testing, 3);
	show("Done!");

	return 0;
}

void set(stringy& stry, char* test)
{
	int len = strlen(test);
	char* tmp = new char[len+1];
	stry.str = tmp;
	strcpy(tmp, test);
	stry.ct = len;
}
void show(const stringy& stry, int n)
{
	for (int i = 0; i < n; i++)
		cout << stry.str << endl;
	cout << "----------------" << endl;
}
void show(const char* str, int n)
{
	for (int i = 0; i < n; i++)
		cout << str << endl;
	cout << "----------------" << endl;
}