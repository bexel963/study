#include <stdio.h>
#define SIZE 4

int main(void)
{
	int no_data[SIZE];
	int some_data[SIZE] = { 1492,1066 };
	int i;

	printf("%2s%14s\n", "i", "no_data[i]");
	for(i=0 ; i<SIZE ; i++)
		printf("%2d%14d\n", i, no_data[i]);
	
	printf("\n------------------------------------------\n\n");

	printf("%2s%14s\n", "i", "some_data[i]");
	for (i = 0; i < SIZE; i++)
		printf("%2d%14d\n", i, some_data[i]);

	return 0;
}