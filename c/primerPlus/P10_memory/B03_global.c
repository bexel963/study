#include <stdio.h>

int units = 0;
void critic(void);

int main(void)
{
	extern int units;	// 선택적인 재선언

	printf("버터 한 통 가격이 몇 파운드인지 아세요?\n");
	scanf("%d", &units);
	while (units != 56)
	{
		critic();
	}
	printf("미리 가격을 알고 있었군요!\n");

	return 0;
}

void critic(void)
{
	/*선택적인 재선언이 생략되었다.*/
	printf("틀렸습니다. 다시 맞춰보세요.\n");
	scanf("%d", &units);
}