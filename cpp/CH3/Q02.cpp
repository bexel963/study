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

	cout << "키 입력(피트): ";
	cin >> height;	
	cout << "체중 입력(파운드): ";
	cin >> weight;
	
	height = height * cInch * cM;
	weight = weight / cKg;
	bmi = weight / (height * height);

	cout << "bmi지수: " << bmi << endl;

	return 0;
}