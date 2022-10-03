#include<stdio.h>

/*
	- 재귀호출
		- 함수 내부에서 자신을 스스로 호출하는 구조이다.
		- 논리 구조는 반복문과 같다.
		- 반복을 끝내기 위한 조건을 신중히 생각해야 한다.
		- Call stack을 활용하기 위해 사용한다.
*/
int test(int a) {

	if (a <= 0)
		return 0;
	printf("test(%d)\n", a);
	return test(a - 1);
}
// f9 -> f5 -> f11 (call trace) -> f10
int main() {

	test(5);
	return 0;
}