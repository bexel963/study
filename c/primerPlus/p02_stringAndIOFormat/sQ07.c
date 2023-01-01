#include <stdio.h>
#include <float.h>

int main(void)
{
	double d;
	float f;
	
	f = 1.0 / 3.0;
	d = 1.0 / 3.0;

	printf("f[%.4f], d[%.4f]\n", f, d);
	printf("f[%.12f], d[%.12f]\n", f, d);
	printf("f[%d], d[%d]\n\n", FLT_DIG, DBL_DIG);

	return 0;
}