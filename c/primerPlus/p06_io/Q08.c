#include <stdio.h>
#include <stdbool.h>

char menu();
void buf_vocate();

int main(void)
{
	float num1, num2;
	char select;
	int scan_result;

	while ((select = menu()) != 'q')
	{

		if (!(select == 'a' || select == 's' || select == 'm' || select == 'd' || select == 'q'))
		{
			puts("�޴� �߿��� �ٽ� �Է��ϼ���.");
			continue;
		}

		printf("ù ��° ���� �Է��Ͻÿ�: ");
		while (scanf("%f", &num1) != 1)
		{
			printf("���� �ƴմϴ�.\n 2.5, -1.78E8, 3�� ���� ���� �Է��Ͻÿ�: ");		
			buf_vocate();
		}
		if (select != 'd')
		{
			printf("�� ��° ���� �Է��Ͻÿ�: ");
			while ((scanf("%f", &num2) != 1))
			{
				printf("���� �ƴմϴ�.\n 2.5, -1.78E8, 3�� ���� ���� �Է��Ͻÿ�: ");
				buf_vocate();
			}
		}
		else
		{
			printf("�� ��° ���� �Է��Ͻÿ�: ");
			while ((scanf("%f", &num2) != 1) || num2 == 0)
			{
				if (num2 == 0)
					printf("0�� �ƴ� �ٸ� ���� �Է��Ͻÿ�: ");
				else
					printf("���� �ƴմϴ�.\n 2.5, -1.78E8, 3�� ���� ���� �Է��Ͻÿ�: ");
				
				buf_vocate();
			}
		}
		buf_vocate();

		switch (select)
		{
		case 'a':
			printf("%.1f + %.1f = %.1f\n", num1, num2, num1 + num2);
			break;
		case 's':
			printf("%.1f - %.1f = %.1f\n", num1, num2, num1 - num2);
			break;
		case 'm':
			printf("%.1f * %.1f = %.1f\n", num1, num2, num1 * num2);
			break;
		case 'd':
			printf("%.1f / %.1f = %.1f\n", num1, num2, num1 / num2);
			break;
		}
	}
	puts("����!!");

	return 0;
}

char menu()
{
	char input;
	puts("���ϴ� ���꿡 �ش��ϴ� ���ڸ� �����Ͻÿ�(�������� q): ");
	printf("a. add(����)\t\ts. subtract(����)\n");
	printf("m. multiply(����)\td. divide(������)\n");
	printf("q. quit(����)\n");

	input = getchar();
	buf_vocate();
	return input;
}

void buf_vocate()
{
	while (getchar() != '\n')
		continue;
}