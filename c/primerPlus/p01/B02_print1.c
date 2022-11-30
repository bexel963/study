#include <stdio.h>

int main(void)
{
	int ten = 100;
	int two = 2;

	printf("바르게 지정했을 때: ");
	printf("%d에서 %d를 빼면 %d\n", ten, 2, ten - two);
	printf("틀리게 지정했을 때: ");
	printf("%d에서 %d를 빼면 %d\n", ten);	// 컴파일러가 에러를 잡아내지 못하고, 현재 메모리에 우연히 들어있는 엉뚱한 값 출력됨.

	printf("\n-----------------------------\n");

	printf("10진수: %d\t8진수: %#o\t16진수: %#x\n", ten, ten, ten, ten);


	
}