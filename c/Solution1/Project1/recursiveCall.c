#include<stdio.h>

/*
	- ���ȣ��
		- �Լ� ���ο��� �ڽ��� ������ ȣ���ϴ� �����̴�.
		- �� ������ �ݺ����� ����.
		- �ݺ��� ������ ���� ������ ������ �����ؾ� �Ѵ�.
		- Call stack�� Ȱ���ϱ� ���� ����Ѵ�.
*/
int test(int a) {

	if (a <= 0)
		return 0;
	printf("test(%d)\n", a);
	return test(a - 1);
}
// f9 -> f5 -> f11 (call trace) -> f10
int main() {

	test(5);
	return 0;
}