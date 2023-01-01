/*
	경보음을 한 번 울리고, 다음과 같은 텍스트를 화면에 출력

		갑작스런 소리에 깜짝 놀라 샐리는 외쳤다,
		"호박대왕이다!"
*/
#include <stdio.h>

int main(void)
{
	putchar('\a');
	printf("갑작스런 소리에 깜짝 놀라 샐리는 외쳤다,\n\"호박대왕이다!\"\n\n");

	return 0;
}