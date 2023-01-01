#include <stdio.h>
#define ARTICHOKES 2.05
#define BEETS 1.15
#define CARROTS 1.09
#define SALE_RATE 0.05

#define COST_LIMIT 100
#define DISCOUNT_RATE 0.05
#define WEIGHT_LIMIT1 5
#define WEIGHT_LIMIT2 20

#define DELIVERY_FEW 6.50
#define DELIVERY_ORIGIN 14.0

char menu();

int main(void)
{
	int totWeight=0, weight;
	float a_cost=0, b_cost=0, c_cost=0;
	float totCost;
	float discountedPrice = 0;
	float deliveryFee = 0;
	float charge;
	char select;

	while ((select = menu()) != 'q')
	{
		if (!(select == 'a' || select == 'b' || select == 'c'))
		{
			puts("a, b, c, q 중에서 다시 입력하세요");
			continue;
		}
		printf("주문량 입력: ");
		scanf("%d", &weight);
		while (getchar() != '\n')
			continue;
		switch (select)
		{
		case 'a':
			a_cost += ARTICHOKES * weight;
			break;
		case 'b':
			b_cost += BEETS * weight;
			break;
		case 'c':
			c_cost += CARROTS * weight;
			break;
		}
		
		totWeight += weight;		
	}

	totCost = a_cost + b_cost + c_cost;

	if (totCost >= COST_LIMIT)
		discountedPrice = totCost * DISCOUNT_RATE;
	
	if (totWeight != 0) {
		if (totWeight < WEIGHT_LIMIT1)
			deliveryFee = DELIVERY_FEW;
		else if (totWeight < WEIGHT_LIMIT2)
			deliveryFee = DELIVERY_ORIGIN;
		else
			deliveryFee = DELIVERY_ORIGIN + (totWeight - WEIGHT_LIMIT2) * 0.5;
	}
	
	charge = totCost - discountedPrice + deliveryFee;

	printf("총 주문량: %d\n", totWeight);
	printf("아티초크: $%.2f\n", a_cost);
	printf("비트: $%.2f\n", b_cost);
	printf("당근: $%.2f\n", c_cost);
	printf("총 구매 가격: $%.2f\n", totCost);
	printf("할인된 가격: $%.2f\n", discountedPrice);
	printf("배송비: $%.2f\n", deliveryFee);
	printf("총 청구 금액은 $%.2f 입니다.\n", charge);

	return 0;
}

char menu()
{
	char input;
	puts("------------------------------");
	printf(" <상품명>\t<가격(파운드당)>\n");
	printf("a) 아티초크\t    $2.05\n");
	printf("b) 비트\t\t    $1.15\n");
	printf("c) 당근\t\t    $1.09\n");
	puts("------------------------------");
	printf("상품 선택(종료-q): ");
	input = getchar();

	while (getchar() != '\n')
		continue;
	return input;
}