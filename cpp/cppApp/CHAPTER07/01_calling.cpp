#include <iostream>

void simple();

int main()
{
	using namespace std;
	cout << "main()에서 simple() 함수를 호출합니다:\n";
	simple();
	cout << "main()이 simple() 함수와 종료됩니다.\n";

	return 0;
}

void simple()
{
	using namespace std;
	cout << "여기는 simple() 함수입니다.\n";
}


