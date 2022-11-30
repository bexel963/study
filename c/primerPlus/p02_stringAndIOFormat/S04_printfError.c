#include <stdio.h>
#define PAGES 336
#define WORDS 65618
// p.144
int main(void)
{
	short num = PAGES;
	short mnum = -PAGES;

	printf("--num--\n");
	printf("short형: %hd\n", num);
	printf("unsigned short형: %hu\n\n", num);
	printf("--mnum--\n");
	printf("short형: %hd\n", mnum);
	printf("unsigned short형: %hu\n\n", mnum);
	printf("--mnum--\n");
	printf("int형: %d\n", num);
	printf("char형: %c\n\n", num);
	printf("--WORDS--\n");
	printf("int형: %d\n", WORDS);
	printf("short형: %hd\n", WORDS);
	printf("char형: %c\n", WORDS);
}