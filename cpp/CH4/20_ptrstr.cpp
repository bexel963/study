#include <iostream>
#include <cstring>

int main()
{
	using namespace std;

	char animal[20] = "bear";
	const char* bird = "wren";
	char* ps;
	
	cout << animal << " and " << bird << " and " << endl;
	
	cout << "동물의 종류를 입력하십시오: ";
	cin >> animal;
	
	ps = animal;
	cout << ps << "s!\n";
	cout << "strcpy() 사용전: \n";
	cout << (int*)animal << ": " << animal << endl;
	cout << (int*)ps << ": " << ps << endl << endl;

	ps = new char[strlen(animal) + 1];
	strcpy(ps, animal);
	cout << "strcpy() 사용후: \n";
	cout << (int*)animal << ": " << animal << endl;
	cout << (int*)ps << ": " << ps << endl;
	delete[] ps;

	return 0;

	
}