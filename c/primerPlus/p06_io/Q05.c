#include <stdio.h>

int main(void)
{
	int min = 1;
	int max = 100;
	int user_thought;
	int com_guess = 0;
	int answerCnt = 0;

	printf("���� �ϳ� �����ϼ���(1~100): ");
	scanf("%d", &user_thought);
	while (com_guess != user_thought)
	{
		com_guess = (min + max) / 2;
		printf("%d �Դϱ�? \n", com_guess);
		answerCnt++;
		if (com_guess < user_thought)
			min = com_guess;
		else
			max = com_guess;
	}
	printf("%d!!! ������ϴ�. �õ��� Ƚ���� %dȸ �Դϴ�.\n", com_guess, answerCnt);
}