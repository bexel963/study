#include <stdio.h>

int main(void)
{
	int n = 4;
	int m = 5;
	float f = 7.0f;
	float g = 8.0f;

	printf("%d\n", n, m);
	printf("%d %d %d\n", n);
	printf("%d %d\n", f, g);

	/*
		C는 함수 프로토타입 메커니즘을 통해서, 함수 호출이 전달인자의 개수와 데이터형을 제대로 사용하는지 검사한다.
		그러나 printf()와 scanf()함수는 전달인자의 개수가 가변적이기 때문에, 이 메커니즘이 적용되지 않는다.
		그래서 오류를 잡아내지 못하고 엉뚱한 값이 출력된다.
	*/
	return 0;
}