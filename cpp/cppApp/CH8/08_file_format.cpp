#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void file_it(ostream&, double, const double*, int);
const int LIMIT = 5;

int main()
{
	ofstream fout;
	const char* fn = "ep-data.txt";
	fout.open(fn);
	if (!fout.is_open())
	{
		cout << fn << " 파일을 열 수 없습니다. 끝.\n";
		exit(EXIT_FAILURE);
	}

	double objective;
	cout << "대물렌즈 초점거리를 mm단위로 입력하십시오: ";
	cin >> objective;
	double eps[LIMIT];
	cout << LIMIT << "가지 대안렌즈의 초점거리를 mm단위로 입력하십시오:\n";
	for (int i = 0; i < LIMIT; i++)
	{
		cout << "대안렌즈 #" << i + 1 << ": ";
		cin >> eps[i];
	}
	file_it(fout, objective, eps, LIMIT);
	file_it(cout, objective, eps, LIMIT);

	cout << "종료\n";

	return 0;
}

void file_it(ostream& os, double fo, const double* fe, int n)
{
	ios_base::fmtflags initial;
	initial = os.setf(ios_base::fixed); // 초기 포맷팅 상태 저장

	os.precision(0);
	os << "대물렌즈의 초점거리: " << fo << " mm\n";
	os.setf(ios::showpoint);
	os.precision(1);
	os.width(17);
	os << "대안렌즈 초점거리";
	os.width(15);
	os << "확대배율" << endl;
	for (int i = 0; i < n; i++)
	{
		os.width(17);
		os << fe[i];
		os.width(15);
		os << (int)(fo / fe[i] + 0.5) << endl;
	}
	os.setf(initial);	// 초기 포맷팅 상태 복원
}

/*
	- setf()
		: 다양한 포맷팅 상태를 설정할 수 있게 한다.
		  
	- setf(ios_base::fixed)
		: 고정 소수점 표기를 사용하는 모드에 객체를 놓는다.

	- setf(ios_base::showpoint)
		: 뒤따르는 숫자들이 0인 경우에도 뒤에 붙은 소수점을 표시하는 모드에 객체를 놓는다.

	- precision()
		: 객체가 고정 소수점 표기 모드에 놓였을 때 소수점의 오른쪽에 표시할 숫자들의 개수를 지정한다.

	- width()
		: 다음 출력 동작에 사용할 필드 폭을 설정한다.

	- 이 모든 설정들은 다른 메서드 호출에 의해 재설될 때까지 효력을 그대로 유지한다.
	  width() 만 하나의 값을 디스플레이하는 데 사용되고, 디폴트로 다시 돌아간다 (0필드 폭)
*/