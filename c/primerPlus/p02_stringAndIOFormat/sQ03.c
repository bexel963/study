#include <stdio.h>

int main(void)
{
	float f;

	printf("�Ҽ��� �� �ϳ� �Է�: ");
	scanf("%f", &f);	
	printf("�Էµ� ���� %.1f �Ǵ� %.1e �̴�.\n", f, f);
	
	getchar();

	printf("�Ҽ��� �� �ϳ� �Է�: ");
	scanf("%f", &f);
	printf("�Էµ� ���� %+.3f �Ǵ� %.3E �̴�.\n\n", f, f);

	return 0;
	
}