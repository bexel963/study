#include <stdio.h>
#include "B05_names_st.h"

int main(void)
{
	names candidate;

	get_names(&candidate);
	printf("ȯ���մϴ�, ");
	show_names(&candidate);
	puts(" ��. ������ ������ ���ʽÿ�!\n");

	return 0;
}
