#include <stdio.h>
#define PAGES 336
#define WORDS 65618
// p.144
int main(void)
{
	short num = PAGES;
	short mnum = -PAGES;

	printf("--num--\n");
	printf("short��: %hd\n", num);
	printf("unsigned short��: %hu\n\n", num);
	printf("--mnum--\n");
	printf("short��: %hd\n", mnum);
	printf("unsigned short��: %hu\n\n", mnum);
	printf("--mnum--\n");
	printf("int��: %d\n", num);
	printf("char��: %c\n\n", num);
	printf("--WORDS--\n");
	printf("int��: %d\n", WORDS);
	printf("short��: %hd\n", WORDS);
	printf("char��: %c\n", WORDS);
}