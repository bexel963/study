
public class Ex13_casting {

	public static void main(String[] args) {

		int i = 10;
		byte b = (byte)i;	// 형변환 생략 불가
		System.out.printf("[int -> byte]  i=%d -> b=%d\n", i, b);
		
		i = 300;
		b = (byte)i;
		System.out.printf("[int -> byte]  i=%d -> b=%d\n", i, b);
		
		b = 10;
		i = b;	// 형변환 생략 가능
		System.out.printf("[byte -> int]  b=%d -> i=%d\n", b, i);
		
		b = -2;
		i = b;
		System.out.printf("[byte -> int]  b=%d -> i=%d\n", b, i);
		
		System.out.println("i = " + Integer.toBinaryString(i));	// 정수를 2진수로 변환해서 문자열로 반환
	}

}
