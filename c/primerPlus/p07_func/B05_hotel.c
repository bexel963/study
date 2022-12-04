#include <stdio.h>
#include "B05_hotel.h"

int menu(void)
{
	int code, status;

	printf("\n%s%s\n", STARS, STARS);
	printf("원하는 호텔 번호를 입력하시오(끝내려면 5): \n");
	printf("1) 페어필드 암즈		2) 호텔 올림픽\n");
	printf("3) 처트워디 플라자		4) 스톡런\n");
	printf("5) 종료\n");
	printf("\n%s%s\n", STARS, STARS);
	
	while ((status = scanf("%d", &code)) != 1 || (code < 1 || code>5))
	{
		if (status != 1)
		{
			scanf("%*s");	// 정수가 아닌 입력은 처리한다.(버퍼에서 비운다.)
			printf("숫자만 입력하세요.\n");
		}
		printf("죄송합니다만 1, 2, 3, 4, 5 중에서 선택하십시오.\n");
	}
	return code;
}

int getnights(void)
{
	int nights;

	printf("몇 밤을 주무실 거지요? ");
	while (scanf("%d", &nights) != 1)
	{
		scanf("%*s");
		printf("2와 같이, 정수를 하나 입력하시오.\n");
	}

	return nights;
}

void showprice(double rate, int nights)
{
	int n;
	double total = 0.0;
	double factor = 1.0;

	for (n = 1; n <= nights; n++, factor *= DISCOUNT)
	{
		total += rate * factor;
	}
	printf("총 투숙 요금이 $%0.2f입니다.\n", total);
}