#include <stdio.h>
#define MONTHS 12

int main(void)
{
	int days[MONTHS] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	const int days2[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int days3[MONTHS] = { 31, 28,[4] = 31, 30, 31,[1] = 29 };
	int index;

	for (index = 0; index < MONTHS; index++)
		printf("%2d월: 날짜 수 %2d\n", index + 1, days[index]);

	printf("\n----------------------------\n\n");

	printf("%d\n", sizeof days2);
	printf("%d\n", sizeof days2[0]);
	for (index = 0; index < (sizeof days2 / sizeof days2[0]) ; index++)
		printf("%2d월: 날짜 수 %2d\n", index + 1, days2[index]);

	printf("\n----------------------------\n\n");

	for (index = 0; index < MONTHS; index++)
		printf("%2d월: 날짜 수 %2d\n", index + 1, days3[index]);


	return 0;
}