#include <stdio.h>

int test(int a)
{
	printf("test() : Hello World\n");
	return 0;
}
int main() {
	
	/*
		- 함수 포인터
			- 함수의 이름은 그 자체가 주소이다.
			- 함수의 이름을 저장할 수 있는 포인터가 함수 포인터이다.
			- 함수 포인터를 이용해 보다 간결한 코드를 만들 수 있다.
			- 함수 포인터가 꼭 필요한 시점은 여러 사람이 함께 작업할 때 이다.
	*/
	int (*pfTest)(int) = test;

	pfTest(4);

	return 0;
}