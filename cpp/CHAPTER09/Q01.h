const int Len = 40;
struct golf
{
	char fullname[Len];
	int handicap;
};

void setgolf(golf& g, const char* name, int hc);	// ���ȭ������ ����ü ����
int setgolf(golf& g);								// ��ȭ������ ����ü ����
void handicap(golf& g, int hc);						// �ڵ�ĸ�� ���ο� ������ ����
void showgolf(const golf& g);						// ����ü ���� ���
