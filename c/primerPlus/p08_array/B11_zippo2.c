#include <stdio.h>

int main(void)
{
	int zippo[4][2] = {
						{2, 4},
						{6, 8},
						{1, 3},
						{5, 7}
	};
	int (*pz)[2];	// pz는 int형 2개짜리 배열을 가리킨다.
	pz = zippo;
	
	printf("   pz = %p,    pz + 1 = %p\n", pz, pz + 1);			// 8차이
	printf("pz[0] = %p, pz[0] + 1 = %p\n", pz[0], pz[0] + 1);	// 4차이
	
	printf("pz[0][0] = %d\n", pz[0][0]);	// 2
	printf("  *pz[0] = %d\n", *pz[0]);		// 2
	printf("    **pz = %d\n", **pz);		// 2

	printf("      pz[2][1] = %d\n", pz[2][1]);			// 3
	printf("*(*(pz+2) + 1) = %d\n", *(*(pz + 2) + 1));	// 3


	return 0;
}