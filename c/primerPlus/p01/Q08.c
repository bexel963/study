/*
	�̱������� ���� ������ pint�� ����Ѵ�.
	1pint�� 2cups�̰�, 1cup�� 8ounces, 1ounce�� 2tablespoons, 1tablespoon�� 3teaspoon�̴�.
	cup������ ���ǰ� ������ ���� �װ��� pints, ounces, tablespoons, teaspoons���� ȯ���Ͽ� ǥ��
	�� �� ��� �ε��Ҽ������� ���������� �� �������� ����....
*/
#include <stdio.h>

int main(void)
{
	float pint;	// ����
	float cups;	
	float ounces;
	float tablespoons;
	float teaspoons;

	printf("���� �Է�(cup����): ");
	scanf("%f", &cups);

	pint = cups / 2;
	ounces = cups * 8;
	tablespoons = ounces * 2;
	teaspoons = tablespoons * 3;
	putchar('\n');

	printf("%.4f(pint)\n", pint);
	printf("%.4f(ounces)\n", ounces);
	printf("%.4f(tablespoons)\n", tablespoons);
	printf("%.4f(teaspoons)\n\n", teaspoons);

	return 0;
}