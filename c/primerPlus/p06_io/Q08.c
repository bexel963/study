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
			puts("메뉴 중에서 다시 입력하세요.");
			continue;
		}

		printf("첫 번째 수를 입력하시오: ");
		while (scanf("%f", &num1) != 1)
		{
			printf("수가 아닙니다.\n 2.5, -1.78E8, 3과 같은 수를 입력하시오: ");		
			buf_vocate();
		}
		if (select != 'd')
		{
			printf("두 번째 수를 입력하시오: ");
			while ((scanf("%f", &num2) != 1))
			{
				printf("수가 아닙니다.\n 2.5, -1.78E8, 3과 같은 수를 입력하시오: ");
				buf_vocate();
			}
		}
		else
		{
			printf("두 번째 수를 입력하시오: ");
			while ((scanf("%f", &num2) != 1) || num2 == 0)
			{
				if (num2 == 0)
					printf("0이 아닌 다른 수를 입력하시오: ");
				else
					printf("수가 아닙니다.\n 2.5, -1.78E8, 3과 같은 수를 입력하시오: ");
				
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
	puts("종료!!");

	return 0;
}

char menu()
{
	char input;
	puts("원하는 연산에 해당하는 문자를 선택하시오(끝내려면 q): ");
	printf("a. add(덧셈)\t\ts. subtract(뺄셈)\n");
	printf("m. multiply(곱셈)\td. divide(나눗셈)\n");
	printf("q. quit(종료)\n");

	input = getchar();
	buf_vocate();
	return input;
}

void buf_vocate()
{
	while (getchar() != '\n')
		continue;
}