#include <stdio.h>
#include "B05_names_st.h"

int main(void)
{
	names candidate;

	get_names(&candidate);
	printf("È¯¿µÇÕ´Ï´Ù, ");
	show_names(&candidate);
	puts(" ¾¾. ¿À´ÃÀº ¸¶À½²¯ Áñ±â½Ê½Ã¿À!\n");

	return 0;
}
