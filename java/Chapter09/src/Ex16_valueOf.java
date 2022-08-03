
public class Ex16_valueOf {

	public static void main(String[] args) {

		int iVal = 100;
		String strVal = String.valueOf(iVal);
		
		double dVal = 200.0;
		String strVal2 = dVal + "";
		
		// 부호 + 가 포함된 문자열이 parseInt()로 변환 가능하게 된 것은 JDK1.7 부터이다.
		double sum = Integer.parseInt("+" + strVal) + Double.parseDouble(strVal2);
		
		double sum2 = Integer.valueOf(strVal) + Double.valueOf(strVal2);
		
		System.out.println(String.join("", strVal, "+", strVal2, "=") + sum);
		System.out.println(strVal + "+" + strVal2 + "=" + sum2);
		
		// parseInt() 나 parseFloat() 같은 메소드는 문자열에 공백 또는 문자가 포함되어있는 경우 변환시 예외 발생.
		// 		-> trim()을 습관적으로 같이 사용한다.
		int val = Integer.parseInt(" 123 ".trim());
		
	}

}
