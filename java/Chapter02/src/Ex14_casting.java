
public class Ex14_casting {

	public static void main(String[] args) {

		float f = 9.1234567f;
		double d = 9.1234567;
		double d2 = f;	// 형변환 생략 가능
		
		System.out.printf("f = %20.18f\n", f);
		System.out.printf("d = %20.18f\n", d);
		System.out.printf("d2 = %20.18f\n", d2);
	}

}
