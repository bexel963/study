#include <iostream>
#include <cstring>

int main()
{
	using namespace std;

	char animal[20] = "bear";
	const char* bird = "wren";
	char* ps;
	
	cout << animal << " and " << bird << " and " << endl;
	
	cout << "������ ������ �Է��Ͻʽÿ�: ";
	cin >> animal;
	
	ps = animal;
	cout << ps << "s!\n";
	cout << "strcpy() �����: \n";
	cout << (int*)animal << ": " << animal << endl;
	cout << (int*)ps << ": " << ps << endl << endl;

	ps = new char[strlen(animal) + 1];
	strcpy(ps, animal);
	cout << "strcpy() �����: \n";
	cout << (int*)animal << ": " << animal << endl;
	cout << (int*)ps << ": " << ps << endl;
	delete[] ps;

	return 0;

	
}