#include <stdio.h>

#define SQUARES 64	// 체스판의 네모칸 수

int main(void)
{
	const double CROP = 2E16;	// 세계 밀 생산량
	double current, total;
	int count = 1;
	
	printf("네모칸     추가         누게           ");
	printf("세계 수확량과의\n");
	printf("번  호    날알 수      날알 수           ");
	printf("상대 비율\n");
	total = current = 1.0;
	printf("%4d %12.2e %12.2e %18.2e\n", count, current, total, total / CROP);
	
	while (count < SQUARES)
	{
		count = count + 1;
		current = 2.0 * current;
		total = total + current;
		printf("%4d %12.2e %12.2e %18.2e\n", count, current, total, total / CROP);
	}
	printf("이제 끝이다.\n");

	return 0;
}