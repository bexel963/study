#include <stdio.h>

void jolly();
void deny();

int main(void)
{
	printf("For he's a");
	jolly();
	puts("fellow!");
	printf("For he's a");
	jolly();
	puts("fellow!");
	printf("For he's a");
	jolly();
	puts("fellow!");
	deny();
	return 0;
}

void jolly()
{
	printf(" jolly good ");
}
void deny()
{
	puts("Which nobody can deny!");
}