#include <iostream>

int main()
{	//5.67, 171

	using namespace std;

	const int cInch = 12;
	const float cM = 0.0254;
	const float cKg = 2.2;
	float height;
	float weight;
	float bmi;

	cout << "Ű �Է�(��Ʈ): ";
	cin >> height;	
	cout << "ü�� �Է�(�Ŀ��): ";
	cin >> weight;
	
	height = height * cInch * cM;
	weight = weight / cKg;
	bmi = weight / (height * height);

	cout << "bmi����: " << bmi << endl;

	return 0;
}