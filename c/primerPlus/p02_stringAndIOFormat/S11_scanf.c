#include <stdio.h>

int main(void)
{
	char ch[12];
	int num;
	float fnum;

	printf("ют╥б: ");
	//scanf("%d%f%s", &num, &fnum, ch);	// -13.45e12#
	
	//printf("%d %.1e %s\n", num, fnum, ch);

	scanf("%f", &fnum);
	printf("%f\n", fnum);
}