
public class Ex13_casting {

	public static void main(String[] args) {

		int i = 10;
		byte b = (byte)i;	// ����ȯ ���� �Ұ�
		System.out.printf("[int -> byte]  i=%d -> b=%d\n", i, b);
		
		i = 300;
		b = (byte)i;
		System.out.printf("[int -> byte]  i=%d -> b=%d\n", i, b);
		
		b = 10;
		i = b;	// ����ȯ ���� ����
		System.out.printf("[byte -> int]  b=%d -> i=%d\n", b, i);
		
		b = -2;
		i = b;
		System.out.printf("[byte -> int]  b=%d -> i=%d\n", b, i);
		
		System.out.println("i = " + Integer.toBinaryString(i));	// ������ 2������ ��ȯ�ؼ� ���ڿ��� ��ȯ
	}

}