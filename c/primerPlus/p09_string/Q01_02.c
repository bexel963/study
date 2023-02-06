#include <stdio.h>
#define SIZE 10

void print(char*, int);
void my_fgets(char*, int);
void my_fgets2(char*, int);


int main(void)
{
	char input[SIZE + 1];

	fputs("문자열 입력: ", stdout);
	//fgets(input, SIZE, stdin);
	my_fgets2(input, SIZE);

	puts(input);
	//print(input, SIZE);

	return 0;
}

void my_fgets(char* arr, int length)
{
	int cnt = 0;
	while (cnt < length)
	{
		arr[cnt] = getchar();
		cnt++;
	}
	while (getchar() != '\n')
		continue;
}
void my_fgets2(char* arr, int length)
{
	int cnt = 0;
	while (cnt < length)
	{
		arr[cnt] = getchar();
		if (arr[cnt] == '\n' || arr[cnt] == ' ' || arr[cnt] == '\t')
		{
			arr[cnt] = '\0';
			break;
		}
		cnt++;
	}
	while (getchar() != '\n')
		continue;
}
void print(char* arr, int length)
{
	for (int i = 0; i < length; i++)
		putchar(arr[i]);
	putchar('\n');
}