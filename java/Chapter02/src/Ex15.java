
public class Ex15 {

	public static void main(String[] args) {

		int i = 91234567;
		float f = (float)i;	// ����ȯ ���� ����
		int i2 = (int)f;	// ����ȯ ���� �Ұ���
		
		double d = (double)i;	// ����ȯ ���� ����
		int i3 = (int)d;		// ����ȯ ���� �Ұ���
		
		float f2 = 1.666f;
		int i4 = (int)f2;	// ����ȯ ���� �Ұ���
		
		System.out.printf("i = %d\n", i);
		System.out.printf("f=%f i2=%d\n", f, i2);
		System.out.printf("d=%f i3=%d\n", d, i3);
		System.out.printf("(int)%f=%d\n", f2, i4);
	}

}
