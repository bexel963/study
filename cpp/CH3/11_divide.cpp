#include <iostream>

int main()
{
	using namespace std;
	
	cout.setf(ios_base::fixed, ios_base:: floatfield);

	cout << "Á¤¼ö ³ª´°¼À: 9 / 5 = " << 9 / 5 << endl;
	cout << "ºÎµ¿ ¼Ò¼öÁ¡¼ö ³ª´°¼À: 9.0 / 5.0 = " << 9.0 / 5.0 << endl;
	cout << "È¥ÇÕ ³ª´°¼À: 9.0 / 5 = " << 9.0 / 5 << endl;
	
	cout << "doubleÇü »ó¼ö: 1e7 / 9.0 = " << 1.e7 / 9.0 << endl;

	cout << "floatÇü »ó¼ö: 1e7f / 9.0f = " << 1.e7f / 9.0f << endl;

	return 0;
}