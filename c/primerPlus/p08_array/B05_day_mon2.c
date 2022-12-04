#include <stdio.h>
#define MONTHS 12

int main(void)
{
	int days[MONTHS] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int index;
	int* p = days;

	for (index = 0; index < MONTHS; index++)
		printf("%2d월: 날짜 수 %2d\n", index + 1, *(p + index));

	printf("\n----------------------------\n\n");

	for (index = 0; index < MONTHS; index++)
		printf("%2d월: 날짜 수 %2d\n", index + 1, *(days + index));

	return 0;

}