#include <stdio.h>
#define PSQR(X) printf(""#X"�� ������ %d�̴�.\n", ((X)*(X)));

int main(void)
{
	int y = 5;
	PSQR(y);
	PSQR(2 + 4);

	return 0;
}