#include <iostream>

using namespace std;

const int perMin = 60;
const int perSec = 3600;

int main()
{
	int angle, min, sec;

	cout << "위도를 도, 분, 초 단위로 각각 입력하세요:\n";

	cout << "먼저, 도각을 입력하시오: ";
	cin >> angle;
	cout << "다음에, 분각을 입력하시오: ";
	cin >> min;
	cout << "끝으로, 초각을 입력하시오: ";
	cin >> sec;	

	cout << angle << "도, " << min << "분, " << sec << "초 = " << (angle + sec * 1 / (float)perSec + min * 1 / (float)perMin) << "도" << endl;

	return 0;
}