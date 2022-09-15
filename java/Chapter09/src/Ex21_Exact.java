/*
 	- �޼��� �̸��� Exact �� ���Ե� �޼������ ������ ���� ���꿡�� �߻��� �� �ִ� �����÷ο츦 �����ϱ� ���� ���̴�. - JDK1.8 ~
 	  ���� ����� �����÷ο��� �߻����ο� ���� �˷��ִ� ���� �ƴϰ�, �����÷ο찡 �߻��ϸ�, ����(ArithmeticException)�� �߻� ��Ų��.
 	- negateExact(int a)�� �Ű������� ��ȣ�� �ݴ�� �ٲ��ش�.
*/
public class Ex21_Exact {

	public static void main(String[] args) {

		int i = Integer.MIN_VALUE;
		
		System.out.println("i = " + i);
		System.out.println("-i = " + -i);
		
		try {
			System.out.println("negateExact(10) = " + Math.negateExact(10));
			System.out.println("negateExact(-10) = " + Math.negateExact(-10));
			System.out.println("negateExact(i) = " + Math.negateExact(i));		// �����÷ο� �߻�
		} catch (Exception e) {
			System.out.println("negateExact(i) = " + Math.negateExact((long)i));
		}
		// ��ȣ�� �ݴ�� �ٲٴ� ���� '~i+1' �̴�. '~i'�� ����� int�� �ִ� ���̸�, ���⿡ 1�� ���ϴ� �����÷ο찡 �߻��ϴ� ���̴�.
		
	}

}
