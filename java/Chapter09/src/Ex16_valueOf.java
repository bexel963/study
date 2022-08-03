
public class Ex16_valueOf {

	public static void main(String[] args) {

		int iVal = 100;
		String strVal = String.valueOf(iVal);
		
		double dVal = 200.0;
		String strVal2 = dVal + "";
		
		// ��ȣ + �� ���Ե� ���ڿ��� parseInt()�� ��ȯ �����ϰ� �� ���� JDK1.7 �����̴�.
		double sum = Integer.parseInt("+" + strVal) + Double.parseDouble(strVal2);
		
		double sum2 = Integer.valueOf(strVal) + Double.valueOf(strVal2);
		
		System.out.println(String.join("", strVal, "+", strVal2, "=") + sum);
		System.out.println(strVal + "+" + strVal2 + "=" + sum2);
		
		// parseInt() �� parseFloat() ���� �޼ҵ�� ���ڿ��� ���� �Ǵ� ���ڰ� ���ԵǾ��ִ� ��� ��ȯ�� ���� �߻�.
		// 		-> trim()�� ���������� ���� ����Ѵ�.
		int val = Integer.parseInt(" 123 ".trim());
		
	}

}
