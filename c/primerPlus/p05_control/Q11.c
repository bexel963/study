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
			puts("a, b, c, q �߿��� �ٽ� �Է��ϼ���");
			continue;
		}
		printf("�ֹ��� �Է�: ");
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

	printf("�� �ֹ���: %d\n", totWeight);
	printf("��Ƽ��ũ: $%.2f\n", a_cost);
	printf("��Ʈ: $%.2f\n", b_cost);
	printf("���: $%.2f\n", c_cost);
	printf("�� ���� ����: $%.2f\n", totCost);
	printf("���ε� ����: $%.2f\n", discountedPrice);
	printf("��ۺ�: $%.2f\n", deliveryFee);
	printf("�� û�� �ݾ��� $%.2f �Դϴ�.\n", charge);

	return 0;
}

char menu()
{
	char input;
	puts("------------------------------");
	printf(" <��ǰ��>\t<����(�Ŀ���)>\n");
	printf("a) ��Ƽ��ũ\t    $2.05\n");
	printf("b) ��Ʈ\t\t    $1.15\n");
	printf("c) ���\t\t    $1.09\n");
	puts("------------------------------");
	printf("��ǰ ����(����-q): ");
	input = getchar();

	while (getchar() != '\n')
		continue;
	return input;
}