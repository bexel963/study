#include <stdio.h>

int main(void)
{
	int evenCnt = 0;
	int oddCnt = 0;
	int evenSum = 0;
	int oddSum = 0;
	int num;

	puts("�������� �Է��ϼ���(�������� 0 �Է�): ");
	while (scanf("%d", &num))
	{
		if (num == 0)
			break;
		if (num % 2 == 0)
		{
			evenCnt++;
			evenSum += num;
		}			
		else
		{
			oddCnt++;
			oddSum += num;
		}				
	}
	
	printf("¦���� ����: %d\n¦���� ���: %.2f\n", evenCnt, (float)evenSum / evenCnt);
	printf("Ȧ���� ����: %d\nȦ���� ���: %.2f\n", oddCnt, (float)oddSum / oddCnt);

	return 0;
	
}