#include <stdio.h>

const int S_PER_M = 60;
const int S_PER_H = 3600;
const double M_PER_K = 0.62137;	// 1ų�ι����� ���� �� 

int main(void)
{
	double distk, distm;	// �޸� �Ÿ�(���� ų�ι��� ���� ���� ��)
	double rate;			// ��ռӵ�(�ð��� ���� ����)
	int min, sec;			// �޸� �ð�(��, ��)
	int time;				// �޸� �ð�(��)
	double mtime;			// 1������ �޸� �ð�(��)
	int mmin, msec;		// 1������ �޸� �ð�(��, ��)

	printf("�� ���α׷��� ���ʹ������ ������ �޸��� �����\n");
	printf("1������ �޸� �ð���, ��ռӵ��� ��ȯ�Ѵ�.\n");

	printf("�޸� �Ÿ��� ų�ι��� ���� �Է��Ͻÿ�.\n");
	scanf("%lf", &distk);

	printf("�޸� �ð��� �� ���� �� ���� �Է��Ͻÿ�.\n");
	printf("���� �� ������ �Է��Ͻÿ�.\n");
	scanf("%d", &min);
	printf("���� �� ���� �Է��Ͻÿ�.\n");
	scanf("%d", &sec);
	
	time = min * S_PER_M + sec;
	distm = M_PER_K * distk;
	rate = distm / time * S_PER_H;

	// �ð� / �Ÿ� = ���ϴ� �ð�
	mtime = (double)time / distm;
	mmin = (int)mtime / S_PER_M;
	msec = (int)mtime % S_PER_M;
	printf("����� %1.2fų�ι���(%1.2f����)�� %d��, %d�ʿ� �޷ȴ�.\n", distk, distm, min, sec);
	printf("�� ���̽��� 1������ %d��, %d�ʿ� �޸� �Ϳ� �ش��Ѵ�.\n", mmin, msec);
	printf("��� �ӵ��� %1.2fmph����.\n", rate);

	return 0;
	
}