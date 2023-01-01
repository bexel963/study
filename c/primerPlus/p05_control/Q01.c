#include <stdio.h>

int main(void)
{
	int spcCnt = 0;
	int newLineCnt = 0;
	int letterCnt = 0;
	char input;

	puts("문장 입력: ");
	while ((input = getchar()) != '#')	// p06_io의 에코 참고
	{
		switch (input)
		{
		case ' ':
			spcCnt++;
			break;
		case '\n':
			newLineCnt++;
			break;
		default:
			letterCnt++;
			break;
		}
	}
	printf("빈칸 수          : %d\n개행문자 수      : %d\n기타 모든 문자 수: %d\n", spcCnt, newLineCnt, letterCnt);

	return 0;
}