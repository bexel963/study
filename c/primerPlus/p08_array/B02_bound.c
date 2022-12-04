#include <stdio.h>
#define SIZE 4

int main(void)
{
	int value1 = 44;
	int arr[SIZE];
	int value2 = 88;
	int i;

	printf("value1 = %d, value2 = %d\n", value1, value2);
	for (i = -1; i <= SIZE; i++)
		arr[i] = 2 * i + 1;
	
	for (i = -1; i < 7; i++)
		printf("%2d %d\n", i, arr[i]);

	printf("value1 = %d, value2 = %d\n", value1, value2);

	printf("arr[-1]狼 林家: %p\n", &arr[-1]);
	printf("arr[4]狼 林家: %p\n", &arr[4]);
	printf("value1狼 林家: %p\n", &value1);
	printf("value2狼 林家: %p\n", &value2);

	return 0;
}