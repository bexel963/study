#include <stdio.h>
#define PAGES 959
#define BLURB "Authentic imitation!"

int main(void)
{
	const double RENT = 3852.99;
	
	printf("*%d*\n", PAGES);
	printf("*%2d*\n", PAGES);
	printf("*%10d*\n", PAGES);
	printf("*%-10d*\n", PAGES);

	printf("\n------------------------------\n");

	printf("*%f*\n", RENT);
	printf("*%e*\n", RENT);
	printf("*%4.2f*\n", RENT);
	printf("*%3.1f*\n", RENT);
	printf("*%10.3f*\n", RENT);
	printf("*%10.3Ef*\n", RENT);
	printf("*%+4.2f*\n", RENT);
	printf("*%010.2f*\n", RENT);

	printf("\n------------------------------\n");

	printf("%x %X %#x\n", 31, 31, 31);
	printf("**%d**% d**% d**\n", 42, 42, -42);
	printf("**%5d**%5.3d**%05d**%05.3d**\n", 6, 6, 6, 6);

	printf("\n------------------------------\n");

	printf("[%2s]\n", BLURB);
	printf("[%24s]\n", BLURB);
	printf("[%24.5s]\n", BLURB);
	printf("[%-24.5s]\n", BLURB);

	printf("\n------------------------------\n");

	printf("%9d %9d %9d\n", 12, 234, 1222);
	printf("%9d %9d %9d\n", 4, 5, 23);
	printf("%9d %9d %9d\n", 225334, 2322, 10001);
	printf("그 선수는 %.2f 마일을 3시간에 달렸다.\n", 10.2248154);
	printf("그 선수는 %8.2f 마일을 3시간에 달렸다.\n", 10.2248154);

	return 0;
}