/*
 	- 메서드 이름에 Exact 가 포함된 메서드들은 정수형 간의 연산에서 발생할 수 있는 오버플로우를 감지하기 위한 것이다. - JDK1.8 ~
 	  연산 결과로 오버플로우의 발생여부에 대해 알려주는 것은 아니고, 오버플로우가 발생하면, 예외(ArithmeticException)를 발생 시킨다.
 	- negateExact(int a)는 매개변수의 부호를 반대로 바꿔준다.
*/
public class Ex21_Exact {

	public static void main(String[] args) {

		int i = Integer.MIN_VALUE;
		
		System.out.println("i = " + i);
		System.out.println("-i = " + -i);
		
		try {
			System.out.println("negateExact(10) = " + Math.negateExact(10));
			System.out.println("negateExact(-10) = " + Math.negateExact(-10));
			System.out.println("negateExact(i) = " + Math.negateExact(i));		// 오버플로우 발생
		} catch (Exception e) {
			System.out.println("negateExact(i) = " + Math.negateExact((long)i));
		}
		// 부호를 반대로 바꾸는 식은 '~i+1' 이다. '~i'의 결과가 int의 최대 값이면, 여기에 1을 더하니 오버플로우가 발생하는 것이다.
		
	}

}
