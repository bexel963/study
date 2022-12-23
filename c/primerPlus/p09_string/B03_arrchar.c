#include <stdio.h>
#define SLEN 40
#define LIM 5

int main(void)
{
	/*
		- 배열과 포인터
			0. 배열 이름 heart는 상수이지만, 포인터 head는 변수이다.
			1. 둘 다 배열 표기를 사용할 수 있다.
			2. 둘 다 포인터 덧셈을 사용할 수 있다.
			3. 포인터 형식만 증가 연산자를 사용할 수 있다.
			4. 배열의 이름은 상수 이지만, 배열의 원소들은 변수이다.

		- head[0] = 'A';	-> Error
			: 동일한 문자열 리터럴들을 메모리에 유일본으로 나타내는 것을 컴파일러가 선택할 수 있다.
			  컴파일러가 이와 같은 단일본 표현 방식을 사용하고, head[0]을 "A"로 변경하는 것을 허용한다면 그 문자열이 사용된 모든 곳이 영향을 받는다.
			  그러므로 포인터를 문자열 리터럴로 초기활할 때, const 변경자를 사용하는 것이 바람직하다.

		- 문자열을 바꿀 계획이 있다면 문자열 리터럴에 포인터를 사용하지 않는다.
	*/
	char heart[] = "I love Tillie!";
	const char* head = "I love Millie!";
	

	for (int i = 0; i < 6; i++)
		putchar(heart[i]);
	putchar('\n');
	for (int i = 0; i < 6; i++)
		putchar(head[i]);
	putchar('\n');
	
	for (int i = 0; i < 6; i++)
		putchar(*(heart + i));
	putchar('\n');
	for (int i = 0; i < 6; i++)
		putchar(*(head + i));
	putchar('\n');

	while (*(head) != '\0')
		putchar(*(head++));
	putchar('\n');
	
	puts("\n=============================================================\n");

	/*
		- mytalents
			: 5개의 포인터 배열
			  mytalents 내의 포인터는 초기화에 사용된 문자열 리터럴의 위치를 가리키는데, 이것(리터럴)은 정적인 메모리에 저장된다.
			  mytalents의 각 열의 길이는 들쭉날쭉이다(열의 길이가 각각 다르다).
			  실제로 mytalents 배열 원소에 의해 가리켜지는 문자열은 메모리에  반드시 연속적으로 저장될 필요는 없다.
			  mytalents 내의 포인터들은 문자열 리터럴을 가리키기 때문에 이 문자열은 고칠 수 없다.

		- yourtalents
			: 각 SLEN크기의 값을 가진 배열 5개의 배열
			  yourtalents내의 배열은 문자열 리터럴의 복사본이 포함되었기 때문에 각 문자열이 두 번씩 저장된다.
			  yourtalents의 각 원소는 같은 크기이며, 크기가 가장 긴 문자열을 유지할 수 있도록 크기가 충분해야 하기 때문에 배열내의 메모리 할당이 비효율적이다.
			  yourtalents의 내용들은 바뀔 수 있다.

		- 문자열을 고치거나 문자열 입력을 위한 공간을 확보하기를 원한다면 문자열 리터럴을 가리키는 포인터를 사용하지 않는다.
	*/
	const char* mytalents[LIM] = {
		"Adding numbers swiftly",
		"Multiplying accurately", "Stashing data",
		"Following instructions to the letter",
		"Understanding the C languate"
	};
	char yourtalents[LIM][SLEN] = {
		"Walking in a straight line",
		"Sleeping", "Watching television",
		"Mailing letters", "Reading email"
	};

	int i;
	
	puts("Let's compare talents.");
	printf("%-36s %-30s\n", "My Talents", "Your Talents");
	for (i = 0; i < LIM; i++)
	{
		printf("%-36s %-30s\n", mytalents[i], yourtalents[i]);
	}
	printf("\nsizeof mytalents: %zd, sizeof yourtalents: %zd\n", sizeof(mytalents), sizeof(yourtalents));

	return 0;
}