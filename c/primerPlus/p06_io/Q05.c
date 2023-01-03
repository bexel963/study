#include <stdio.h>

int main(void)
{
	int min = 1;
	int max = 100;
	int user_thought;
	int com_guess = 0;
	int answerCnt = 0;

	printf("숫자 하나 생각하세요(1~100): ");
	scanf("%d", &user_thought);
	while (com_guess != user_thought)
	{
		com_guess = (min + max) / 2;
		printf("%d 입니까? \n", com_guess);
		answerCnt++;
		if (com_guess < user_thought)
			min = com_guess;
		else
			max = com_guess;
	}
	printf("%d!!! 맞췄습니다. 시도한 횟수는 %d회 입니다.\n", com_guess, answerCnt);
}