#include <stdio.h>

int main(void)
{
	float weight;
	float value;

	printf("당신의 몸무게를 플래티넘 가치로 계산하면 얼마나 나갈까요?\n");
	printf("어디 한번 계산해 봅시다.\n");
	printf("뭄무게를 파운드 단위로 입력하시오: ");
	
	scanf("%f", &weight);

	// 1파운드에 해당하는 온스 수: 14.5833
	// 온스는 귀금속에 쓰이는 금형단위, 파운드는 귀금속, 보석, 약품을 제외한 모든 것에 쓰이는 상형단위
	value = 1700.0 * weight * 14.5833;
	printf("\n당신의 몸무게를 플래티넘 가치로 계산하면 $%.2f입니다.\n", value);
	printf("당신의 몸값은 그 정도 가치가 나갑니다. 플래티넘 가격이 떨이저면, \n");
	printf("가치를 유지하기 위해 식사량을 늘려야 합니다.\n");

	getchar();	// scanf()에서 입력한 개행문자를 읽고,
	getchar();	// 프로그램을 멈추가 입력을 기다린다.

	return 1;
}