// names_st.h ���Ͽ� �ߺ� ���� ��ȣ ��� �߰�

#ifndef NAME��S_H_
#define NAMES_H_

#define SLEN 32

struct names_st
{
	char first[SLEN];
	char last[SLEN];
};

typedef struct names_st names;

void get_names(names*);
void show_names(const names*);
char* s_gets(char*, int);

#endif
