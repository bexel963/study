#include <stdio.h>

int main(void)
{
	// c11은 sizeof에 사용되는 데이터형을 위한 %zd 지정자를 제공한다.
	printf("int형의 크기: %d바이트\n", sizeof(int));
	printf("char형의 크기: %zd바이트\n", sizeof(char));
	printf("long형의 크기: %zd바이트\n", sizeof(long));
	printf("long long형의 크기: %zd바이트\n", sizeof(long long));
	printf("float형의 크기: %zd바이트\n", sizeof(float));
	printf("double형의 크기: %zd바이트\n", sizeof(double));
	printf("long double형의 크기: %zd바이트\n", sizeof(long double));

	return 0;
}